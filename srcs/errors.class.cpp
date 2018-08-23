#include "../includes/header.hpp"
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

const char	*errors::overflowError::what() const throw()
{
	return ("overflow");
}

const char	*errors::underflowError::what() const throw()
{
	return ("underflow");
}

const char	*errors::unknownCommandError::what() const throw()
{
	return ("Unknown Command");
}

const char	*errors::syntaxError::what() const throw()
{
	return ("Syntax Error");
}

const char	*errors::initUnderflowError::what() const throw()
{
	return ("amount is too small for the operand to hold");
}

const char	*errors::initOverflowError::what() const throw()
{
	return ("amount is too big for the operand to hold");
}
