#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"

int	main(int argc, char **argv)
{
	std::string	temp;
	reader	init;
	try {
		if (argc == 1)
			init.inputread();
		else if (argc == 2) {
			temp = argv[1];
			if (temp.find(".avm") == std::string::npos)
				throw errors::fileError();
			else
				init.fileread(argv[1]);
		} else {
			throw errors::inputError();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
