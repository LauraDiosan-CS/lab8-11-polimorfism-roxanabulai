#include <exception>
#ifndef MYEXCEPTION3_H
#define MYEXCEPTION3_H

class MyException3 :public std::exception {
private:
	const char* message;
public:
	MyException3(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif