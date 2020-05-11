#pragma once
#include "User.h"
class TestsUser {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testClone();
	void testGetUserName();
	void testGetPassword();
	void testSetUserName();
	void testSetPassword();
	void testEqualityOperator();
	void testToStringDelimiter();

public:
	void testAll();
};