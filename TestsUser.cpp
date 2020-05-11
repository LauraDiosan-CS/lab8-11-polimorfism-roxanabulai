#include "User.h"
#include "TestsUser.h"
#include<assert.h>

void TestsUser::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testClone();
	this->testGetUserName();
	this->testSetUserName();
	this->testGetPassword();
	this->testSetPassword();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestsUser::testImplicitConstructor()
{
	User* u = new User();
	assert(u->getUserName().empty());
	assert(u->getPassword().empty());

}

void TestsUser::testConstructorWithParameters()
{
	User* u1 = new User("Ana", "111aaa");
	assert(u1->getUserName() == "Ana");
	assert(u1->getPassword() == "111aaa");
}

void TestsUser::testClone()
{
	User* u1 = new User("Ana", "111aaa");
	User* userClone = (User*)u1->clone();

	assert(*u1 == *userClone);
	assert(u1 != userClone);
}

void TestsUser::testGetUserName()
{
	User* u1 = new User("Ana", "111aaa");
	assert(u1->getUserName() == "Ana");
}

void TestsUser::testGetPassword()
{
	User* u1 = new User("Ana", "111aaa");
	assert(u1->getPassword() == "111aaa");
}

void TestsUser::testSetUserName()
{
	User* u1 = new User("Ana", "111aaa");
	u1->setUserName("Bia");
	assert(u1->getUserName() == "Bia");
}

void TestsUser::testSetPassword()
{
	User* u1 = new User("Ana", "111aaa");
	u1->setPassword("222bbb");
	assert(u1->getPassword() == "222bbb");
}


void TestsUser::testEqualityOperator()
{
	User* u1 = new User("Ana", "111aaa");
	User* u2 = u1;
	assert(u2==u1);

	u1->setUserName("Anca");
	assert(!(u1->clone()==u2->clone()));
	u2->setUserName(u1->getUserName());
	assert(u1==u2);


}

void TestsUser::testToStringDelimiter()
{
	User* u1=new User("Ana", "111aaa");
	assert(u1->toStringDelimiter(" ") == "Ana 111aaa");
	assert(u1->toStringDelimiter(",") == "Ana,111aaa");
}