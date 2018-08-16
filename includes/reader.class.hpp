#ifndef READER_CLASS_HPP
# define READER_CLASS_HPP

class reader {
	public:
		reader(void);
		~reader(void);
		const std::string		removecomment(std::string line);
		const std::vector<std::string>	inputread(void);
		bool				fileCheck(std::string file);
		const std::vector<std::string>	fileread(const char *file);
};

#endif
