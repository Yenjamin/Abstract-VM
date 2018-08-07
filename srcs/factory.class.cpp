#include "../includes/factory.class.hpp"

factory::factory(void)
{
	return ;
}

factory::~factory(void)
{
	return ;
}

IOperand const * factory::createInt8(std::string const & value) const
{
	int8_t	nbr = static_cast<int8_t>(atoi(value.c_str()));

	if (nbr < INT8_MIN)
		throw errors::underflowError();
	if (nbr > INT8_MAX)
		throw errors::overflowError();
	return new Operand<int8_t>(Int8, static_cast<int8_t>(nbr));
}

IOperand const * factory::createInt16(std::string const & value) const
{
	int16_t	nbr = static_cast<int16_t>(atoi
}
