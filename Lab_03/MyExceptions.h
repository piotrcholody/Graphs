#ifndef MyExceptions_h
#define MyExceptions_h
#include <exception>

class CreatingRegularGraphFailed: public std::exception {
	virtual const char* what() const throw() {
		return "Creating regular graph with this amount of vertices and degree is not possible";
	}
};

#endif // MyExceptions_h
