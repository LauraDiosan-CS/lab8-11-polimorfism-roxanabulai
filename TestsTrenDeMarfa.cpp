/*
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
	this->testGetNrGarnituriDisponibile();
	this->testSetNrGarnituriDisponibile();
	this->testGetNrGarnituriRezervate();
	this->testSetNrGarnituriRezervate();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestTrenDeMarfa::testImplicitConstructor()
{
	TrenDeMarfa tren_marfa;
	assert(tren_marfa.get_nr_garnituri_disponibile() == 0);
	assert(tren_marfa.get_nr_garnituri_rezervate() == 0);
}

void TestTrenDeMarfa::testConstructorWithParameters()
{
	TrenDeMarfa tren_marfa("Regional", "Alstom", 122, "carbune", 45, 55);
	assert(tren_marfa.get_marfa() == "carbune");
	assert(tren_marfa.get_nr_garnituri_disponibile() == 45);
	assert(tren_marfa.get_nr_garnituri_rezervate() == 55);
}

void TestTrenDeMarfa::testCopyConstructor()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDeMarfa tren_marfa2(tren_marfa1);
	assert(tren_marfa1.get_marfa() == tren_marfa2.get_marfa());
	assert(tren_marfa1.get_nr_garnituri_disponibile() == tren_marfa2.get_nr_garnituri_disponibile());
	assert(tren_marfa1.get_nr_garnituri_rezervate() == tren_marfa2.get_nr_garnituri_rezervate());
}

void TestTrenDeMarfa::testClone()
{
	TrenDeMarfa tren_marfa("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDeMarfa* tren_marfaClone = (TrenDeMarfa*)tren_marfa.clone();

	assert(tren_marfa == *tren_marfaClone);
	assert(&tren_marfa != tren_marfaClone);
}

void TestTrenDeMarfa::testGetMarfa()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 45, 55);
	assert(tren_marfa1.get_marfa() == "carbune");
}

void TestTrenDeMarfa::testSetMarfa()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 45, 55);
	tren_marfa1.set_marfa("lemne");
	assert(tren_marfa1.get_marfa() == "lemne");
}

void TestTrenDeMarfa::testSetNrGarnituriDisponibile()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "carbune", 45, 55);
	tren_marfa1.set_nr_garnituri_disponibile(40);
	assert(tren_marfa1.get_nr_garnituri_disponibile() == 40);
}

void TestTrenDeMarfa::testGetNrGarnituriDisponibile()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, "lemne", 45, 55);
	assert(tren_marfa1.get_nr_garnituri_disponibile() == 45);
}

void TestTrenDeMarfa::testGetNrGarnituriRezervate()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, 223, 45, 55);
	assert(tren_marfa1.get_nr_garnituri_rezervate() == 55);
}

void TestTrenDeMarfa::testSetNrGarnituriRezervate()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, 223, 45, 55);
	tren_marfa1.set_nr_garnituri_rezervate(56);
	assert(tren_marfa1.get_nr_garnituri_rezervate() == 56);
}
void TestTrenDeMarfa::testAssignmentOperator()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, 223, 45, 55);
	TrenDeMarfa tren_marfa2;
	tren_marfa2 = tren_marfa1;
	assert(tren_marfa2.get_marfa() == tren_marfa1.get_marfa());
	assert(tren_marfa2.get_nr_garnituri_disponibile() == tren_marfa1.get_nr_garnituri_disponibile());
	assert(tren_marfa2.get_nr_garnituri_rezervate() == tren_marfa1.get_nr_garnituri_rezervate());
}

void TestTrenDeMarfa::testEqualityOperator()
{
	TrenDeMarfa tren_marfa1("Regional", "Alstom", 100, 223, 45, 55);
	TrenDeMarfa tren_marfa2 = tren_marfa1;
	assert(tren_marfa2 == tren_marfa1);

	tren_marfa2.set_marfa(2224);
	assert(!(tren_marfa1 == tren_marfa2));
	tren_marfa2.set_marfa(tren_marfa1.get_marfa());
	assert(tren_marfa1 == tren_marfa2);

	tren_marfa2.set_nr_garnituri_rezervate(58);
	assert(!(tren_marfa1 == tren_marfa2));
	tren_marfa2.set_nr_garnituri_rezervate(tren_marfa1.get_nr_garnituri_rezervate());
	assert(tren_marfa1 == tren_marfa2);

	tren_marfa2.set_nr_garnituri_disponibile(200);
	assert(!(tren_marfa1 == tren_marfa2));
	tren_marfa2.set_nr_garnituri_disponibile(tren_marfa1.get_nr_garnituri_disponibile());
	assert(tren_marfa1 == tren_marfa2);
}

void TestTrenDeMarfa::testToStringDelimiter()
{
	TrenDeMarfa tren_marfa1("regional", "Alstom", 100, 223, 45, 55);
	assert(tren_marfa1.toStringDelimiter(" ") == "TrenM regional Alstom 100 223 45 55");
	assert(tren_marfa1.toStringDelimiter(",") == "TrenM,regional,Alstom,100,223,45,55");
}
*/