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
	int8_t	nbr = static_cast<int8_t>(stoi(value.c_str()));

	return new Operand<int8_t>(Int8, static_cast<int8_t>(nbr));
}

IOperand const * factory::createInt16(std::string const & value) const
{
	int16_t	nbr = static_cast<int16_t>(stoi(value.c_str()));

	return new Operand<int16_t>(Int16, static_cast<int16_t>(nbr));
}

IOperand const * factory::createInt32(std::string const & value) const
{
	int32_t	nbr = static_cast<int32_t>(stoi(value.c_str()));

	return new Operand<int32_t>(Int32, static_cast<int32_t>(nbr));
}

IOperand const * factory::createFloat(std::string const & value) const
{
	double	nbr = static_cast<float>(stof(value.c_str()));

	return new Operand<float>(Float, static_cast<float>(nbr));
}

IOperand const * factory::createDouble(std::string const & value) const
{
	long double	nbr = static_cast<double>(sof(value.c_str()));

	return new Operand<double>(Double, static_cast<double>(nbr));
}
