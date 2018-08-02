#include "../includes/Header.hpp"
#include "../includes/errors.class.hpp"

const char	*errors::inputError::what() const throw()
{
	return ("too many arguments");
}

const char	*errors::fileError::what() const throw()
{
	return ("file must be in .avm");
}

const char	*errors::directoryError::what() const throw()
{
	return ("program cannot read folders");
}

const char      *errors::fileOpenError::what() const throw()
{
	        return ("cannot open the file");
}
