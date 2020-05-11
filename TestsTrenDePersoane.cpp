#include "TrenDePersoane.h"
#include "TestsTrenDePersoane.h"
#include<assert.h>

void TestTrenDePersoane::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNrLocuri();
	this->testSetNrLocuri();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestTrenDePersoane::testImplicitConstructor()
{
	TrenDePersoane tren_persoane;
	assert(tren_persoane.get_nr_locuri() == 0);
}

void TestTrenDePersoane::testConstructorWithParameters()
{
	TrenDePersoane tren_persoane("Regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane.get_nr_locuri() == 222);
}

void TestTrenDePersoane::testCopyConstructor()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane tren_persoane2(tren_persoane1);
	assert(tren_persoane1.get_nr_locuri() == tren_persoane2.get_nr_locuri());

}

void TestTrenDePersoane::testClone()
{
	TrenDePersoane tren_persoane("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane* tren_persoaneClone = (TrenDePersoane*)tren_persoane.clone();

	assert(tren_persoane == *tren_persoaneClone);
	assert(&tren_persoane != tren_persoaneClone);
}

void TestTrenDePersoane::testGetNrLocuri()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane1.get_nr_locuri() == 222);
}

void TestTrenDePersoane::testSetNrLocuri()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	tren_persoane1.set_nr_locuri(223);
	assert(tren_persoane1.get_nr_locuri() == 223);
}

void TestTrenDePersoane::testAssignmentOperator()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane tren_persoane2;
	tren_persoane2 = tren_persoane1;
	assert(tren_persoane1.get_nr_locuri() == tren_persoane2.get_nr_locuri());

}

void TestTrenDePersoane::testEqualityOperator()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane tren_persoane2 = tren_persoane1;
	assert(tren_persoane2 == tren_persoane1);

	tren_persoane2.set_nr_locuri(2224);
	assert(!(tren_persoane1 == tren_persoane2));
	tren_persoane2.set_nr_locuri(tren_persoane1.get_nr_locuri());
	assert(tren_persoane1 == tren_persoane2);

}

void TestTrenDePersoane::testToStringDelimiter()
{
	TrenDePersoane tren_persoane1("regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane1.toStringDelimiter(" ") == "TrenP regional Alstom 100 222 45 55");
	assert(tren_persoane1.toStringDelimiter(",") == "TrenP,regional,Alstom,100,222,45,55");
}
