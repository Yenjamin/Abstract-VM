#include "../includes/factory.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/operand.class.hpp"

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
	long double	nbr = static_cast<long double>(stold(value));

	if (nbr < INT8_MIN)
		throw errors::initUnderflowError();
	if (nbr > INT8_MAX)
		throw errors::initOverflowError();
	return new Operand<int8_t>(Int8, value);
}

IOperand const * factory::createInt16(std::string const & value) const
{
	long double	nbr = static_cast<long double>(stold(value));

	if (nbr < INT16_MIN)
		throw errors::initUnderflowError();
	if (nbr > INT16_MAX)
		throw errors::initOverflowError();
	return new Operand<int16_t>(Int16, value);
}

IOperand const * factory::createInt32(std::string const & value) const
{
	long double	nbr = static_cast<long double>(stold(value));

	if (nbr < INT32_MIN)
		throw errors::initUnderflowError();
	if (nbr > INT32_MAX)
		throw errors::initOverflowError();
	return new Operand<int32_t>(Int32, value);
}

IOperand const * factory::createFloat(std::string const & value) const
{
	long double	nbr = static_cast<long double>(stold(value));

	if (std::fabsl(nbr) < FLT_MIN && std::fabsl(nbr) > 0)
		throw errors::initUnderflowError();
	if (nbr > FLT_MAX)
		throw errors::initOverflowError();
	return new Operand<float>(Float, value);
}

IOperand const * factory::createDouble(std::string const & value) const
{
	long double	nbr = static_cast<long double>(stold(value));

	if (std::fabsl(nbr) < DBL_MIN && std::fabsl(nbr) > 0)
		throw errors::initUnderflowError();
	if (nbr > DBL_MAX)
		throw errors::initOverflowError();
	return new Operand<double>(Double, value);
}

IOperand const * factory::createOperand(eOperandType type, std::string const & val) const
{
	functionpt	arr[] {
		&factory::createInt8,
		&factory::createInt16,
		&factory::createInt32,
		&factory::createFloat,
		&factory::createDouble
	};
	functionpt	op = arr[type];
	return ((this->*op)(val));
};
