#include "../includes/header.hpp"
#include "../includes/operand.hpp"

template<typename T>
operand<T>::operand(void)
{
	return ;
}

template<typename T>
operand<T>::operand(std::std::string val, eOperandType type) : _type(type)
{
	long double tmp = std::stold(val);
	T new_val = static_cast<T>(tmp);
	_val = std::to_string(static_cast<T>(new_val));
}

template<typename T>
operand<T>::~operand(void)
{
	return ;
}

template<typename T>
eOperandType	operand<T>::getType(void) const
{
	return (_type);
}

template<typename T>
int	operand<T>::getPrecision(void) const
{
	switch (_type)
	{
		case int8:
			return(0);
		case int16:
			return(1);
		case int32:
			return(2);
		case Float:
			return(3);
		case Double:
			return(4);
	}
}

template<typename T>
std::string const & operand<T>::toString(void) const
{
	return (this->_val);
}

template<typename T>
IOperand const & operand<T>::operator=(IOperand const & rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

template<typename T>
IOperand const * operand<T>::operator+(IOperand const & rhs) const
{
	long double		val1 = std::stold(this->_val);
	long double		val2 = std::stold(rhs.toString());
	long double		result = val1 + val2;
	int			prec1 = this->getPrecision();
	int			prec2 = rhs.getPrecision();
	factory			f;
}
