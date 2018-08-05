#ifndef RUN_CLASS_HPP
# define RUN_CLASS_HPP

class run {
public:
    run(const std::vector<std::string> commands);
    run(const run &rhs);
    ~run(void);
    void    runvm(void);

private:
    const std::vector<std::string>  _commands;
};

#endif