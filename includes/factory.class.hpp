#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

class factory {
	public:
		factory(void);
		~factory(void);
		IOperand const * createInt8(std::string const & value) const;
		IOperand const * createInt16(std::string const & value) const;
		IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
		typedef IOperand const * (factory::*functionpt)(const std::string &) const;
};

#endif
