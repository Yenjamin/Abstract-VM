#include "../includes/Header.hpp"
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

const std::vector<std::string>		reader::inputread(void)
{
	std::vector<std::string>	commands;
	std::string			line = "";
	while (line != ";;")
	{
		getline(std::cin, line);
		if (line.size() >= 1)
			commands.push_back(line);
	}
	std::vector<std::string>::const_iterator     top;
	std::vector<std::string>::const_iterator       next;

	top = commands.begin();
	next = commands.end();
	while (top != next) {
		std::cout << *top << std::endl;
		top++;
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
				if (line.size() >= 1)
					commands.push_back(line);
			}
			content.close();
			std::vector<std::string>::const_iterator     top;
			std::vector<std::string>::const_iterator       next;
			
			top = commands.begin();
			next = commands.end();
			while (top != next) {
				std::cout << *top << std::endl;
				top++;
			}
		}
	}
	else
		throw errors::fileOpenError();
	return (commands);
}
