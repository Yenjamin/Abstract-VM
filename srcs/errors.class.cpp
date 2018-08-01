#include "../includes/Header.hpp"
#include "../includes/errors.class.hpp"

const char	*errors::inputerror::what() const throw()
{
	return ("Input Error");
}
