#ifndef RUN_CLASS_HPP
# define RUN_CLASS_HPP

#include "IOperand.hpp"

class run {
public:
    run(const std::vector<std::string> commands);
    run(const run &rhs);
    ~run(void);
    void	runinstructions(std::string line, std::vector<IOperand const *> stack);
    void	runinstructions(std::string line);
    void	runvm(void);

private:
    const std::vector<std::string>  _commands;
};

#endif
