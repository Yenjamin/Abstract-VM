#ifndef RUN_CLASS_HPP
# define RUN_CLASS_HPP

#include "IOperand.hpp"

class run {
public:
    run(const std::vector<std::string> commands);
    run(const run &rhs);
    ~run(void);
    void	runinstructions(std::string line);
    void	runvm(void);
    std::vector<IOperand const *>	_stack;
    const std::vector<std::string>	_commands;
};

#endif
