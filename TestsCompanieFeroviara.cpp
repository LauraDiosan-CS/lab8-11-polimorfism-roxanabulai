#include "CompanieFeroviara.h"
#include "TestsCompanieFeroviara.h"
#include<assert.h>

void TestCompanieFeroviara::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNumeModel();
	this->testSetNumeModel();
	this->testGetNumeProducator();
	this->testSetNumeProducator();
	this->testGetNrVagoane();
	this->testSetNrVagoane();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToStringDelimiter();
}

void TestCompanieFeroviara::testImplicitConstructor()
{
	CompanieFeroviara comp_ferov;
	assert(comp_ferov.get_nume_model().empty());
	assert(comp_ferov.get_nume_producator().empty());
	assert(comp_ferov.get_nr_vagoane() == 0);
	assert(comp_ferov.get_nr_garnituri_disponibile() == 0);
	assert(comp_ferov.get_nr_garnituri_rezervate() == 0);
}

void TestCompanieFeroviara::testConstructorWithParameters()
{
	CompanieFeroviara comp_ferov("Regional", "Alstom", 100, 45, 55);
	assert(comp_ferov.get_nume_model() == "Regional");
	assert(comp_ferov.get_nume_producator() == "Alstom");
	assert(comp_ferov.get_nr_vagoane() == 100);
	assert(comp_ferov.get_nr_garnituri_disponibile() == 45);
	assert(comp_ferov.get_nr_garnituri_rezervate() == 55);
}

void TestCompanieFeroviara::testCopyConstructor()
{
	CompanieFeroviara comp_ferov1("Regional", "Alstom", 100, 35, 65);
	CompanieFeroviara comp_ferov2(comp_ferov1);
	assert(comp_ferov1.get_nume_model() == comp_ferov1.get_nume_model());
	assert(comp_ferov2.get_nume_producator() == comp_ferov1.get_nume_producator());
	assert(comp_ferov2.get_nr_vagoane() == comp_ferov1.get_nr_vagoane());
	assert(comp_ferov2.get_nr_garnituri_disponibile() == comp_ferov1.get_nr_garnituri_disponibile());
	assert(comp_ferov2.get_nr_garnituri_rezervate() == comp_ferov1.get_nr_garnituri_rezervate());
}

void TestCompanieFeroviara::testClone()
{
	CompanieFeroviara comp_ferov1("Regional", "Alstom", 100, 50, 50);
	CompanieFeroviara* comp_ferovClone = comp_ferov1.clone();
	assert(comp_ferov1 == *comp_ferovClone);
	assert(&comp_ferov1 != comp_ferovClone);

}

void TestCompanieFeroviara::testGetNumeModel()
{
	CompanieFeroviara comp_ferov1("Regional", "Alstom", 100, 20, 80);
	assert(comp_ferov1.get_nume_model() == "Regional");
}

void TestCompanieFeroviara::testSetNumeModel()
{
	CompanieFeroviara comp_ferov;
	comp_ferov.set_nume_model("Cu aburi");
	assert(comp_ferov.get_nume_model() == "Cu aburi");
}

void TestCompanieFeroviara::testSetNumeProducator()
{
	CompanieFeroviara comp_ferov;
	comp_ferov.set_nume_producator("Siemens");
	assert(comp_ferov.get_nume_producator() == "Siemens");
}

void TestCompanieFeroviara::testGetNumeProducator()
{
	CompanieFeroviara comp_ferov1("Regional", "Alstom", 100, 50, 50);
	assert(comp_ferov1.get_nume_producator() == "Alstom");
}

void TestCompanieFeroviara::testGetNrVagoane()
{
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	assert(comp_ferov.get_nr_vagoane() == 100);
}

void TestCompanieFeroviara::testGetNrGarnituriRezervate() {
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	assert(comp_ferov.get_nr_garnituri_rezervate() == 50);
}
void TestCompanieFeroviara::testGetNrGarnituriDisponibile() {
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	assert(comp_ferov.get_nr_garnituri_disponibile() == 50);
}
void TestCompanieFeroviara::testSetNrVagoane()
{
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	comp_ferov.set_nr_vagoane(200);
	assert(comp_ferov.get_nr_vagoane() == 200);
}
void TestCompanieFeroviara::testSetNrGarnituriDisponibile()
{
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	comp_ferov.set_nr_garnituri_disponibile(200);
	assert(comp_ferov.get_nr_garnituri_disponibile() == 200);
}
void TestCompanieFeroviara::testSetNrGarnituriRezervate()
{
	CompanieFeroviara comp_ferov("Regional", "Almstom", 100, 50, 50);
	comp_ferov.set_nr_garnituri_rezervate(200);
	assert(comp_ferov.get_nr_garnituri_rezervate() == 200);
}

void TestCompanieFeroviara::testAssignmentOperator()
{
	CompanieFeroviara comp_ferov1("Regional", "Almstom", 100, 20, 80);
	CompanieFeroviara comp_ferov2;
	comp_ferov2 = comp_ferov1;
	assert(comp_ferov2.get_nume_model() == comp_ferov1.get_nume_model());
	assert(comp_ferov2.get_nume_producator() == comp_ferov1.get_nume_producator());
	assert(comp_ferov2.get_nr_vagoane() == comp_ferov1.get_nr_vagoane());
	assert(comp_ferov2.get_nr_garnituri_disponibile() == comp_ferov1.get_nr_garnituri_disponibile());
	assert(comp_ferov2.get_nr_garnituri_rezervate() == comp_ferov1.get_nr_garnituri_rezervate());
}

void TestCompanieFeroviara::testEqualityOperator()
{
	CompanieFeroviara comp_ferov1("Regional", "Almstom", 100, 20, 80);
	CompanieFeroviara comp_ferov2 = comp_ferov1;
	assert(comp_ferov2 == comp_ferov1);

	comp_ferov2.set_nume_model("cu aburi");
	assert(!(comp_ferov1 == comp_ferov2));
	comp_ferov2.set_nume_model(comp_ferov1.get_nume_model());
	assert(comp_ferov1 == comp_ferov2);

	comp_ferov2.set_nume_producator("Siemens");
	assert(!(comp_ferov1 == comp_ferov2));
	comp_ferov2.set_nume_producator(comp_ferov1.get_nume_producator());
	assert(comp_ferov1 == comp_ferov2);

	comp_ferov2.set_nr_vagoane(200);
	assert(!(comp_ferov1 == comp_ferov2));
	comp_ferov2.set_nr_vagoane(comp_ferov1.get_nr_vagoane());
	assert(comp_ferov1 == comp_ferov2);

	comp_ferov2.set_nr_garnituri_disponibile(200);
	assert(!(comp_ferov1 == comp_ferov2));
	comp_ferov2.set_nr_garnituri_disponibile(comp_ferov1.get_nr_garnituri_disponibile());
	assert(comp_ferov1 == comp_ferov2);

	comp_ferov2.set_nr_garnituri_rezervate(200);
	assert(!(comp_ferov1 == comp_ferov2));
	comp_ferov2.set_nr_garnituri_rezervate(comp_ferov1.get_nr_garnituri_rezervate());
	assert(comp_ferov1 == comp_ferov2);
}

void TestCompanieFeroviara::testToStringDelimiter()
{
	CompanieFeroviara comp_ferov1("Regional", "Almstom", 100, 50, 50);
	assert(comp_ferov1.toStringDelimiter(" ") == "Regional Almstom 100 50 50");
	assert(comp_ferov1.toStringDelimiter(",") == "Regional,Almstom,100,50,50");
}
