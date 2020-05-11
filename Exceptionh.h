#include <exception>
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException :public std::exception {
private:
	const char* message;
public:
	MyException(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif