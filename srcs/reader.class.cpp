#include "../includes/Header.hpp"
#include "../includes/reader.class.hpp"

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

const std::vector<std::string>	reader::fileread(const char *file)
{
	std::vector<std::string>	commands;
	std::string 			line = "";
	/*std::ifstream			content(file);
	content.seekg(0, content.end);
	if (content.is_open() || content.good())
	{
		std::cout << "hello" << std::endl;
		content.close();
	}
	else
	{
		std::cout << "No!" << std::endl;
	}*/
	return (commands);
}
