#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include "header.hpp"

enum	eOperandType {
	int8,
	int16,
	int32,
	Float,
	Double
};

class	IOperand {
	public:
		virtual int		getPrecision(void) const = 0;
		virtual eOperandType	getType(void) const = 0;
		virtual IOperand const * operator+(IOperand const & rhs) const = 0;
		virtual IOperand const * operator-(IOperand const & rhs) const = 0;
		virtual IOperand const * operator*(IOperand const & rhs) const = 0;
		virtual IOperand const * operator/(IOperand const & rhs) const = 0;
		virtual IOperand const * operator%(IOperand const & rhs) const = 0;
		virtual std::string const & toString(void) const = 0;
		virtual ~IOperand(void) {}
};

#endif
