#include "../includes/header.hpp"
#include "../includes/reader.class.hpp"
#include "../includes/errors.class.hpp"
#include "../includes/run.class.hpp"

run::run(const std::vector<std::string> commands) : _commands(commands)
{
    return ;
}

run::run(const run &rhs) : _commands(NULL)
{
    static_cast<void>(rhs);
    return ;
}

run::~run(void)
{
    return ;
}

void    run::runvm(void)
{
    std::vector<std::string>::const_iterator    top;
    std::vector<std::string>::const_iterator    next;
    reader  info;

    top = _commands->begin();
    next = _commands->end();
}