#ifndef ERRORS_CLASS_HPP
# define ERRORS_CLASS_HPP

#include "header.hpp"

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
		class overflowError : public std::exception {
			public:
				const char *what() const throw();
		};
		class underflowError : public std::exception {
			public:
				const char *what() const throw();
		};
		class unknownCommandError : public std::exception {
			public:
				const char *what() const throw();
		};
		class syntaxError : public std::exception {
			public:
				const char *what() const throw();
		};
		class initUnderflowError : public std::exception {
			public:
				const char *what() const throw();
		};
		class initOverflowError : public std::exception {
			public:
				const char *what() const throw();
		};

};

#endif
