#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

#include "IOperand.hpp"

template<typename T>
class operand : public IOperand
{
	public:
		operand(void);
		operand(std::string val, eOperandType type);
		virtual ~operand(void);
		std::string	_val;
		eOperandType	_type;
		virtual eOperandType	getType(void) const;
		virtual int		getPrecision(void) const;
		virtual std::string const & toString(void) const;
		IOperand const & operator=(IOperand const & rhs);
		virtual IOperand const * operator+(IOperand const & rhs) const;
		virtual IOperand const * operator-(IOperand const & rhs) const;
		virtual IOperand const * operator*(IOperand const & rhs) const;
		virtual IOperand const * operator/(IOperand const & rhs) const;
		virtual IOperand const * operator%(IOperand const & rhs) const;
};

#include "../srcs/operand.class.cpp"

#endif
