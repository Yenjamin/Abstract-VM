#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/run.class.hpp"

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

void	run::runinstructions(std::string line/*, std::vector<IOperand const *> stack*/)
{
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
}

void    run::runvm(void)
{
    std::vector<std::string>::const_iterator    top;
    std::vector<std::string>::const_iterator    bottom;
//    std::vector<IOperand const *>		stack;
    reader  info;

    top = _commands.begin();
    bottom = _commands.end();
    while (top != bottom) {
	    std::cout << *top << std::endl;
	    runinstructions(*top);
	    top++;
    }
}
