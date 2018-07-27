#include "../includes/Header.hpp"
#include "../includes/reader.class.hpp"

const std::vector<std::string*>		&reader::inputread(void)
{
	std::vector<std::string*>	*commands = new std::vector<std::string*>;
	std::string			line = "";
	while (line != ";;")
	{
		getline(std::cin, line);
		if (line.size() >= 1)
			commands->push_back(new std::string(line));
	}
	std::vector<std::string*>::const_iterator     top;
	std::vector<std::string*>::const_iterator       next;

	top = commands->begin();
	next = commands->end();
	while (top != next) {
		std::cout << **top << std::endl;
		top++;
	}
	return (*commands);
}

//const std::vector<std::string*>	&reader::fileread(const char *file)
//{
//}
