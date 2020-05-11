#include "TrenDeMarfa.h"
#include "TestsTrenDeMarfa.h"
#include<assert.h>

void TestTrenDeMarfa::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetMarfa();
	this->testSetMarfa();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestTrenDeMarfa::testImplicitConstructor()
{
	TrenDeMarfa tren_marfa;
	assert(tren_marfa.get_marfa().empty());

}

void TestTrenDeMarfa::testConstructorWithParameters()
{
	TrenDeMarfa tren_marfa("Regional", "Alstom", 100, "carbune", 55, 45);
	assert(tren_marfa.get_marfa() == "carbune");
}

void TestTrenDeMarfa::testCopyConstructor()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	TrenDeMarfa tren_marfa2(tren_marfa1);
	assert(tren_marfa1.get_marfa() == tren_marfa2.get_marfa());
}

void TestTrenDeMarfa::testClone()
{
	TrenDeMarfa tren_marfa("Regional", "Alstom", 100, "carbune", 55, 45);
	TrenDeMarfa* tren_marfaClone = (TrenDeMarfa*)tren_marfa.clone();

	assert(tren_marfa == *tren_marfaClone);
	assert(&tren_marfa != tren_marfaClone);
}

void TestTrenDeMarfa::testGetMarfa()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	assert(tren_marfa1.get_marfa() == "carbune");
}

void TestTrenDeMarfa::testSetMarfa()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	tren_marfa1.set_marfa("lemne");
	assert(tren_marfa1.get_marfa() == "lemne");
}



void TestTrenDeMarfa::testAssignmentOperator()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	TrenDeMarfa tren_marfa2;
	tren_marfa2 = tren_marfa1;
	assert(tren_marfa2.get_marfa() == tren_marfa1.get_marfa());

}

void TestTrenDeMarfa::testEqualityOperator()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	TrenDeMarfa tren_marfa2 = tren_marfa1;
	assert(tren_marfa2 == tren_marfa1);

	tren_marfa2.set_marfa("lemne");
	assert(!(tren_marfa1 == tren_marfa2));
	tren_marfa2.set_marfa(tren_marfa1.get_marfa());
	assert(tren_marfa1 == tren_marfa2);


}

void TestTrenDeMarfa::testToStringDelimiter()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 55, 45);
	assert(tren_marfa1.toStringDelimiter(" ") == "TrenM Regional Alstom 100 carbune 55 45");
	assert(tren_marfa1.toStringDelimiter(",") == "TrenM,Regional,Alstom,100,carbune,55,45");
}