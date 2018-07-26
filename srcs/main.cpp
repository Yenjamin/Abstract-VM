#include "../includes/Header.hpp"

int	main(int argc, char **argv)
{
	try {
		if (argc == 1) {
			std::string	line;
			getline(std::cin, line);
			std::cout << line << std::endl;
			//read from standard
		} else if (argc == 2) {
			std::string	temp = argv[1];
			if (temp.find(".avm") == std::string::npos)
				std::cout << "Error: Invalid use of the program" << std::endl;
			else
				std::cout << argv[1] <<std::endl;
			//read from file
		} else {
			std::cout << "Error: Invalid use of the program" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
