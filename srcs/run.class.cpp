#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/run.class.hpp"
#include "../includes/IOperand.hpp"
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

void	runinstructions(std::string line, std::vector<IOperand const *> stack)
{
	std::string				op;
	std::string				val;
	factory					a;
	if (line == "pop")
		/*if (stack.size() < 1)
			throw errors//errors: empty stack
		else
		{
			IOperand const *	pop1 = stack[stack.size() - 1];
			delete pop1;
			stack.pop_back();
		}*/
		
		std::cout << "pop" << std::endl;
	else if (line == "dump")
		std::cout << "dump" << std::endl;
	else if (line == "add")
		std::cout << "add" << std::endl;
	else if (line == "sub")
		std::cout << "sub" << std::endl;
	else if (line == "mul")
		std::cout << "mul" << std::endl;
	else if (line == "div")
		std::cout << "div" << std::endl;
	else if (line == "mod")
		std::cout << "mod" << std::endl;
	else if (line == "print")
		std::cout << "print" << std::endl;
	else if (line.substr(0,4) == "push")
	{
		op = line.substr(line.find(' ') + 1, (line.find('(') - line.find(' ') - 1));
		val = line.substr(line.find('(') + 1, (line.size() - 2 - line.find('(')));
		if (op == "int8")
		{
			IOperand const * t = a.createOperand(eOperandType::int8, val);
			stack.push_back(t);
		}
		else if (op == "int16")
		{
			IOperand const * t = a.createOperand(eOperandType::int16, val);
			stack.push_back(t);
		}
		else if (op == "int32")
		{
			IOperand const * t = a.createOperand(eOperandType::int32, val);
			stack.push_back(t);
		}
		else if (op == "float")
		{
			IOperand const * t = a.createOperand(eOperandType::Float, val);
			stack.push_back(t);
		}
		else if (op == "double")
		{
			IOperand const * t = a.createOperand(eOperandType::Double, val);
			stack.push_back(t);
		}
	}
	else if (line.substr(0,6) == "assert")
	{
		std::cout << "assert" << std::endl;
		op = line.substr(line.find(' ') + 1, (line.find('(') - line.find(' ') - 1));
		std::cout << op << std::endl;
		val = line.substr(line.find('(') + 1, (line.size() - 2 - line.find('(')));
		std::cout << val << std::endl;
	}
}

void    run::runvm(void)
{
    std::vector<std::string>::const_iterator    top;
    std::vector<std::string>::const_iterator    bottom;
    std::vector<IOperand const *>		stack;
    reader  info;

    top = _commands.begin();
    bottom = _commands.end();
    while (top != bottom) {
	    std::cout << *top << std::endl;
	    runinstructions(*top, stack);
	    top++;
    }
}
