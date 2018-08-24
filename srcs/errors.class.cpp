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

const char	*errors::emptyStackError::what() const throw()
{
	return ("the stack is empty");
}

const char	*errors::operationError::what() const throw()
{
	return ("need at least 2 values on stack to perform");
}

const char	*errors::zeroError::what() const throw()
{
	return ("can't mod/div by 0");
}

const char	*errors::typeError::what() const throw()
{
	return ("wrong type");
}

const char	*errors::assertError::what() const throw()
{
	return ("assert returns false");
}

const char	*errors::exitError::what() const throw()
{
	return ("no exit found");
}
