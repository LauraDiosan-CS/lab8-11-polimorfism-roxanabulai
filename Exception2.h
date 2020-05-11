#include <exception>
#ifndef MYEXCEPTION2_H
#define MYEXCEPTION2_H

class MyException2 :public std::exception {
private:
	const char* message;
public:
	MyException2(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif