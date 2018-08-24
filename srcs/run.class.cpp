#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/run.class.hpp"
#include "../includes/operand.class.hpp"

run::run(const std::vector<std::string> commands) : _commands(commands)
{
    return ;
}

run::run(const run &rhs) : _commands()
{
    static_cast<void>(rhs);
    return ;
}

run::~run(void)
{
    return ;
}

void	run::runinstructions(std::string line)
{
	std::string				op;
	std::string				val;
	factory					a;
	if (line == "pop")
		if (_stack.size() < 1)
			throw errors::emptyStackError();
		else
		{
			IOperand const *	pop1 = _stack[_stack.size() - 1];
			delete pop1;
			_stack.pop_back();
		}
	else if (line == "dump")
	{
		if (_stack.size() < 1)
			throw errors::emptyStackError();
		else
			for (int i = _stack.size() - 1; i >= 0; i--)
				std::cout << _stack[i]->toString() << std::endl;
	}
	else if (line == "add")
	{
		if (_stack.size() < 2)
			throw errors::operationError();
		else
		{
			IOperand const * val1 = _stack[_stack.size() - 1];
			IOperand const * val2 = _stack[_stack.size() - 2];
			IOperand const * result;
			result = *val1 + *val2;
			delete val1;
			delete val2;
			_stack.pop_back();
			_stack.pop_back();
			_stack.push_back(result);
		}
	}
	else if (line == "sub")
		if (_stack.size() < 2)
			throw errors::operationError();
		else
		{
			IOperand const * val1 = _stack[_stack.size() - 1];
			IOperand const * val2 = _stack[_stack.size() - 2];
			IOperand const * result;
			result = *val1 - *val2;
			delete val1;
			delete val2;
			_stack.pop_back();
			_stack.pop_back();
			_stack.push_back(result);
		}
	else if (line == "mul")
	{
		if (_stack.size() < 2)
			throw errors::operationError();
		else
		{
			IOperand const * val1 = _stack[_stack.size() - 1];
			IOperand const * val2 = _stack[_stack.size() - 2];
			IOperand const * result;
			result = *val1 * *val2;
			delete val1;
			delete val2;
			_stack.pop_back();
			_stack.pop_back();
			_stack.push_back(result);
		}
	}
	else if (line == "div")
	{
		if (_stack.size() < 2)
			throw errors::operationError();
		else
		{
			IOperand const * val1 = _stack[_stack.size() - 1];
			IOperand const * val2 = _stack[_stack.size() - 2];
			IOperand const * result;
			if (std::stold(val1->toString()) == 0)
				throw errors::zeroError();
			result = *val2 / *val1;
			delete val1;
			delete val2;
			_stack.pop_back();
			_stack.pop_back();
			_stack.push_back(result);
		}
	}
	else if (line == "mod")
	{
		if (_stack.size() < 2)
			throw errors::operationError();
		else
		{
			IOperand const * val1 = _stack[_stack.size() - 1];
			IOperand const * val2 = _stack[_stack.size() - 2];
			IOperand const * result;
			if (std::stold(val1->toString()) == 0)
				throw errors::zeroError();
			result = *val2 % *val1;
			delete val1;
			delete val2;
			_stack.pop_back();
			_stack.pop_back();
			_stack.push_back(result);
		}
	}
	else if (line == "print")
	{
		if (_stack.size() < 1)
			throw errors::emptyStackError();
		if (_stack[_stack.size() - 1]->getType() != 0)
			throw errors::typeError();
		else
			std::cout << static_cast<char>(static_cast<int8_t>(std::stold(_stack[_stack.size() - 1]->toString()))) << std::endl;
	}
	else if (line.substr(0,4) == "push")
	{
		op = line.substr(line.find(' ') + 1, (line.find('(') - line.find(' ') - 1));
		val = line.substr(line.find('(') + 1, (line.size() - 2 - line.find('(')));
		if (op == "int8")
		{
			IOperand const * t = a.createOperand(eOperandType::int8, val);
			_stack.push_back(t);
		}
		else if (op == "int16")
		{
			IOperand const * t = a.createOperand(eOperandType::int16, val);
			_stack.push_back(t);
		}
		else if (op == "int32")
		{
			IOperand const * t = a.createOperand(eOperandType::int32, val);
			_stack.push_back(t);
		}
		else if (op == "float")
		{
			IOperand const * t = a.createOperand(eOperandType::Float, val);
			_stack.push_back(t);
		}
		else if (op == "double")
		{
			IOperand const * t = a.createOperand(eOperandType::Double, val);
			_stack.push_back(t);
		}
	}
	else if (line.substr(0,6) == "assert")
	{
		if (_stack.size() < 1)
			throw errors::emptyStackError();
		else
		{
			op = line.substr(line.find(' ') + 1, (line.find('(') - line.find(' ') - 1));
			val = line.substr(line.find('(') + 1, (line.size() - 2 - line.find('(')));
			IOperand const * tmp = _stack[_stack.size() - 1];
			if (op == "int8" && tmp->getType() == 0)
			{
				if (val != tmp->toString())
					throw errors::assertError();
			}
			else if (op == "int16" && tmp->getType() == 1)
			{
				if (val != tmp->toString())
					throw errors::assertError();
			}
			else if (op == "int32" && tmp->getType() == 2)
			{
				if (val != tmp->toString())
					throw errors::assertError();
			}
			else if (op == "float" && tmp->getType() == 3)
			{
				if (val != tmp->toString())
					throw errors::assertError();
			}
			else if (op == "double" && tmp->getType() == 4)
			{
				if (val != tmp->toString())
					throw errors::assertError();
			}
			else
				throw errors::assertError();
		}
	}
}

void    run::runvm(void)
{
    std::vector<std::string>::const_iterator    top;
    std::vector<std::string>::const_iterator    bottom;
    reader  info;

    top = _commands.begin();
    bottom = _commands.end();
    while (top != bottom) {
	    std::cout << *top << std::endl;
	    runinstructions(*top);
	    top++;
    }
}
