#ifndef IOPERAND_HPP
# define IOPERAND_HPP

enum	eOperandType {
	In8,
	Int16,
	Int32,
	Float,
	Double,
	Error
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
