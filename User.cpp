#include "User.h"

//constructor implicit
User::User()
{
}
//constructor cu parametri
User::User(string u, string p) :userName(u), password(p)
{
}

//getteri
string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}
//setteri
void User::setUserName(string u)
{
	userName = u;
}

void User::setPassword(string p)
{
	password = p;
}
//operator ==
bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

User* User::clone()
{
	return new User(this->userName, this->password);
}

string User::toString()
{
	return userName + " " + password;
}

string User::toStringDelimiter(string delimiter)
{
	return userName + delimiter + password;
}


User::~User()
{
}
