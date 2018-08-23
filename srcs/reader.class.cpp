#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"

reader::reader(void)
{
	return ;
}

reader::~reader(void)
{
	return ;
}

const std::string			reader::removecomment(std::string line)
{
	std::string			temp = "";

	temp = line.substr(0, line.find(';'));
	return (temp);
}

const std::string			reader::trimmer(std::string line)
{
	std::string			tmp = line;
	int				i = -1;

	tmp = removecomment(tmp);
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	replace(tmp.begin(), tmp.end(), '\t', ' ');
	tmp = std::regex_replace(tmp, std::regex("^ +| +$|( ) +"), "$1");
	i = tmp.find('(');
	if (i >= 0)
	{
		if (tmp[i - 1] == ' ')
		{
			tmp.erase ((i - 1), 1);
		}
	}
	return (tmp);
}

const std::string			commandcheck(std::string line)
{
	std::regex			withOperand("(push|assert) (int8|int16|int32|float|double)\\([-+]?[0-9]\\d*(\\.\\d+)?\\)\\B");
	std::regex	                adfunc("(push|assert).*");
	std::regex			funcName("(add|sub|mod|dump|div|mul|pop|print).*");
	std::regex			func("(add|sub|mod|dump|div|mul|pop|print)\\b");

	if (std::regex_match(line, funcName) == true)
	{
		if (std::regex_match(line, func) == true)
		{
			return (line);
		}
		else
			throw errors::syntaxError();
	}
	else if (std::regex_match(line, adfunc) == true)
	{
		if (std::regex_match(line, withOperand) == true)
		{
			return (line);
		}
		else
			throw errors::syntaxError();
	}
	else
		throw errors::unknownCommandError();
}

const std::vector<std::string>		reader::inputread(void)
{
	std::vector<std::string>	commands;
	std::string			line = "";
	while (getline(std::cin, line) && line != ";;")
	{
		line = trimmer(line);
		if (line.size() >= 1)
		{
			commandcheck(line);
			commands.push_back(line);
		}
	}
	return (commands);
}

bool				reader::fileCheck(std::string file)
{
	FILE *fp = fopen(file.c_str(), "r");
	struct stat fileInfo;
	 fstat(fileno(fp), &fileInfo);
	 if (!S_ISREG(fileInfo.st_mode)) {
	     fclose(fp);
	     return false;
	         }
	 else
		 return true;
}

const std::vector<std::string>	reader::fileread(const char *file)
{
	std::vector<std::string>	commands;
	std::string 			line = "";
	std::ifstream			content(file);
	if (content.is_open())
	{
		if (fileCheck(std::string(file)) == 0)
			throw errors::directoryError();
		else
		{
			while (!content.eof())
			{
				getline(content, line);
				line = trimmer(line);
				if (line.size() >= 1)
				{
					commandcheck(line);
					commands.push_back(line);
				}
			}
			content.close();
		}
	}
	else
		throw errors::fileOpenError();
	return (commands);
}


