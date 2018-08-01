#ifndef READER_CLASS_HPP
# define READER_CLASS_HPP

class reader {
	public:
		const std::vector<std::string>	inputread(void);
		bool				fileCheck(std::string file);
		const std::vector<std::string>	fileread(const char *file);
};

#endif
