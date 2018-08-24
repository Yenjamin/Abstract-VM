#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

#include "IOperand.hpp"
#include "factory.class.hpp"

template<typename T>
class operand : public IOperand
{
	public:
		operand(void)
		{
			return ;
		}

		operand(eOperandType type, std::string val) : _type(type) {
			long double tmp = std::stold(val);
			T valt = static_cast<T>(tmp);
			_val = std::to_string(static_cast<T>(valt));
		}

		~operand(void)
		{
			return ;
		}

		eOperandType	getType(void) const
		{
			return (_type);
		}

		int		getPrecision(void) const
		{
			switch (_type)
			{
				case int8:
					return (0);
				case int16:
					return (1);
				case int32:
					return (2);
				case Float:
					return (3);
				case Double:
					return (4);
			}
		}

		std::string const & toString(void) const
		{
			return (this->_val);
		}

		operand const &operator=(operand const &rhs)
		{
			if (this != &rhs)
				*this = rhs;
			return (*this);
		}

		IOperand const *operator+(IOperand const &rhs) const
		{
			long double		val1 = std::stold(this->_val);
			long double		val2 = std::stold(rhs.toString());
			long double		result = val1 + val2;
			int			prec1 = this->getPrecision();
			int			prec2 = rhs.getPrecision();
			factory			a;
			IOperand const *	op = NULL;

			if (prec1 < prec2)
				op = a.createOperand(rhs.getType(), std::to_string(result));
			else
				op = a.createOperand(this->getType(), std::to_string(result));
			return (op);
		}

		IOperand const *operator-(IOperand const &rhs) const
		{
			long double	 	val1 = std::stold(this->_val);
			long double             val2 = std::stold(rhs.toString());
			long double             result = val1 - val2;
			int                     prec1 = this->getPrecision();
			int                     prec2 = rhs.getPrecision();
			factory                 a;
			IOperand const *        op = NULL;

			if (prec1 < prec2)
				op = a.createOperand(rhs.getType(), std::to_string(result));
			else
				op = a.createOperand(this->getType(), std::to_string(result));
			return (op);
		}

		IOperand const *operator*(IOperand const &rhs) const
		{
			long double             val1 = std::stold(this->_val);
			long double             val2 = std::stold(rhs.toString());
			long double             result = val1 * val2;
			int                     prec1 = this->getPrecision();
			int                     prec2 = rhs.getPrecision();
			factory                 a;
			IOperand const *        op = NULL;

			if (prec1 < prec2)
				op = a.createOperand(rhs.getType(), std::to_string(result));
			else
				op = a.createOperand(this->getType(), std::to_string(result));
			return (op);
		}

		IOperand const *operator/(IOperand const &rhs) const
		{
			long double             val1 = std::stold(this->_val);
			long double             val2 = std::stold(rhs.toString());
			long double             result = val1 / val2;
			int                     prec1 = this->getPrecision();
			int                     prec2 = rhs.getPrecision();
			factory                 a;
			IOperand const *        op = NULL;

			if (prec1 < prec2)
				op = a.createOperand(rhs.getType(), std::to_string(result));
			else
				op = a.createOperand(this->getType(), std::to_string(result));
			return (op);
		}

		IOperand const *operator%(IOperand const &rhs) const
		{
			long double             val1 = std::stold(this->_val);
			long double             val2 = std::stold(rhs.toString());
			long double             result = std::fmod(val1, val2);
			int                     prec1 = this->getPrecision();
			int                     prec2 = rhs.getPrecision();
			factory                 a;
			IOperand const *        op = NULL;

			if (prec1 < prec2)
				op = a.createOperand(rhs.getType(), std::to_string(result));
			else
				op = a.createOperand(this->getType(), std::to_string(result));
			return (op);
		}
		std::string	_val;
		eOperandType	_type;
};

#endif
