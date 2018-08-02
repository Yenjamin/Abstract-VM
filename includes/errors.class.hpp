#ifndef ERRORS_CLASS_HPP
# define ERRORS_CLASS_HPP

#include "Header.hpp"

class errors {
	public:
		class inputError : public std::exception {
			public:
				const char *what() const throw();
		};
		class fileError : public std::exception {
			public:
				const char *what() const throw();
		};
		class directoryError : public std::exception {
			public:
				const char *what() const throw();
		};
		class fileOpenError : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
