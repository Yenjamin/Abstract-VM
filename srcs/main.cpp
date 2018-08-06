#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/run.class.hpp"

int	main(int argc, char **argv)
{
	std::string	temp;
	reader	init;
	try {
		if (argc == 1)
		{
			run	vm(init.inputread());
			vm.runvm();
		}
		else if (argc == 2) {
			temp = argv[1];
			if (temp.find(".avm") == std::string::npos)
				throw errors::fileError();
			else
			{
				run	vm(init.fileread(argv[1]));
				vm.runvm();
			}
		} else {
			throw errors::inputError();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
