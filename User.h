#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User(); //constructor implicit
	User(string, string); //constructor cu param

	string getUserName();
	string getPassword();

	void setUserName(string);
	void setPassword(string);

	bool operator==(const User& u);

	User* clone();

	string toString();
	string toStringDelimiter(string delimiter);
	~User(); //destructor
};

