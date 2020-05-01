#include "TrenDePersoane.h"
#include "Tests_TrenDePersoane.h"
#include<assert.h>

void TestTrenDePersoane::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNrLocuri();
	this->testSetNrLocuri();
	this->testGetNrGarnituriDisponibile();
	this->testSetNrGarnituriDisponibile();
	this->testGetNrGarnituriRezervate();
	this->testSetNrGarnituriRezervate();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestTrenDePersoane::testImplicitConstructor()
{
	TrenDePersoane tren_persoane;
	assert(tren_persoane.get_nr_locuri() == 0);
	assert(tren_persoane.get_nr_garnituri_disponibile() == 0);
	assert(tren_persoane.get_nr_garnituri_rezervate() == 0);
}

void TestTrenDePersoane::testConstructorWithParameters()
{
	TrenDePersoane tren_persoane("Regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane.get_nr_locuri() == 222);
	assert(tren_persoane.get_nr_garnituri_disponibile() == 45);
	assert(tren_persoane.get_nr_garnituri_rezervate() == 55);
}

void TestTrenDePersoane::testCopyConstructor()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane tren_persoane2(tren_persoane1);
	assert(tren_persoane1.get_nr_locuri() == tren_persoane2.get_nr_locuri());
	assert(tren_persoane1.get_nr_garnituri_disponibile() == tren_persoane2.get_nr_garnituri_disponibile());
	assert(tren_persoane1.get_nr_garnituri_rezervate() == tren_persoane2.get_nr_garnituri_rezervate());
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

void TestTrenDePersoane::testSetNrGarnituriDisponibile()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	tren_persoane1.set_nr_garnituri_disponibile(40);
	assert(tren_persoane1.get_nr_garnituri_disponibile() == 40);
}

void TestTrenDePersoane::testGetNrGarnituriDisponibile()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane1.get_nr_garnituri_disponibile() == 45);
}

void TestTrenDePersoane::testGetNrGarnituriRezervate()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane1.get_nr_garnituri_rezervate() == 55);
}

void TestTrenDePersoane::testSetNrGarnituriRezervate()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	tren_persoane1.set_nr_garnituri_rezervate(56);
	assert(tren_persoane1.get_nr_garnituri_rezervate() == 56);
}
void TestTrenDePersoane::testAssignmentOperator()
{
	TrenDePersoane tren_persoane1("Regional", "Alstom", 100, 222, 45, 55);
	TrenDePersoane tren_persoane2;
	tren_persoane2 = tren_persoane1;
	assert(tren_persoane1.get_nr_locuri() == tren_persoane2.get_nr_locuri());
	assert(tren_persoane1.get_nr_garnituri_disponibile() == tren_persoane2.get_nr_garnituri_disponibile());
	assert(tren_persoane1.get_nr_garnituri_rezervate() == tren_persoane2.get_nr_garnituri_rezervate());
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

	tren_persoane2.set_nr_garnituri_rezervate(58);
	assert(!(tren_persoane1 == tren_persoane2));
	tren_persoane2.set_nr_garnituri_rezervate(tren_persoane1.get_nr_garnituri_rezervate());
	assert(tren_persoane1 == tren_persoane2);

	tren_persoane2.set_nr_garnituri_disponibile(200);
	assert(!(tren_persoane1 == tren_persoane2));
	tren_persoane2.set_nr_garnituri_disponibile(tren_persoane1.get_nr_garnituri_disponibile());
	assert(tren_persoane1 == tren_persoane2);
}

void TestTrenDePersoane::testToStringDelimiter()
{
	TrenDePersoane tren_persoane1("regional", "Alstom", 100, 222, 45, 55);
	assert(tren_persoane1.toStringDelimiter(" ") == "TrenP regional Alstom 100 222 45 55");
	assert(tren_persoane1.toStringDelimiter(",") == "TrenP,regional,Alstom,100,222,45,55");
}
