#include "../includes/Header.hpp"
#include "../includes/reader.class.hpp"

int	main(int argc, char **argv)
{
	std::string	temp;
	reader	init;
	try {
		if (argc == 1) {
			init.inputread();
			//read from standard
		} else if (argc == 2) {
			temp = argv[1];
			if (temp.find(".avm") == std::string::npos)
				throw errors::inputerror();
			else
			{
				std::cout << argv[1] <<std::endl;
				init.fileread(argv[1]);
			}
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
