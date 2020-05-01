#include "TrenDeMarfa.h"
#include<vector>
#include<sstream>

//constructor implicit
TrenDeMarfa::TrenDeMarfa(): CompanieFeroviara() {
	marfa = 0;
	nr_garnituri_disponibile = 0;
	nr_garnituri_rezervate = 0;
}
//conctructor cu param
TrenDeMarfa::TrenDeMarfa(string nume_model, string nume_producator, int nr_vagoane, int marfa, int nr_garnituri_disponibile, int nr_garnituri_rezervate) :
	CompanieFeroviara(nume_model, nume_producator, nr_vagoane) {
	this->marfa = marfa;
	this->nr_garnituri_disponibile = nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = nr_garnituri_rezervate;
}
//constructor de copiere
TrenDeMarfa::TrenDeMarfa(const TrenDeMarfa& tren_marfa) :CompanieFeroviara(tren_marfa) {
	this->marfa = tren_marfa.marfa;
	this->nr_garnituri_disponibile = tren_marfa.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = tren_marfa.nr_garnituri_rezervate;
}
//getteri
int TrenDeMarfa::get_marfa() {
	return this->marfa;
}
int TrenDeMarfa::get_nr_garnituri_disponibile() {
	return this->nr_garnituri_disponibile;
}
int TrenDeMarfa::get_nr_garnituri_rezervate() {
	return this->nr_garnituri_rezervate;
}
//setteri
void TrenDeMarfa::set_marfa(int new_marfa) {
	this->marfa = new_marfa;
}
void TrenDeMarfa::set_nr_garnituri_disponibile(int new_nr_garnituri_disponibile) {
	this->nr_garnituri_disponibile = new_nr_garnituri_disponibile;
}
void TrenDeMarfa::set_nr_garnituri_rezervate(int new_nr_garnituri_rezervate) {
	this->nr_garnituri_rezervate = new_nr_garnituri_rezervate;
}
TrenDeMarfa& TrenDeMarfa::operator=(const TrenDeMarfa& tren_marfa)
{
    CompanieFeroviara::operator=(tren_marfa);
	this->marfa = tren_marfa.marfa;
	this->nr_garnituri_disponibile = tren_marfa.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = tren_marfa.nr_garnituri_rezervate;
	return *this;
}
//clone
CompanieFeroviara* TrenDeMarfa::clone()
{
	return new TrenDeMarfa(this->nume_model, this->nume_producator, this->nr_vagoane, this->marfa, this->nr_garnituri_disponibile, this->nr_garnituri_rezervate);
}
//operator ==
bool TrenDeMarfa::operator==(const TrenDeMarfa& tren_marfa)
{
	return CompanieFeroviara::operator==(tren_marfa) and (this->marfa == tren_marfa.marfa) and (this->nr_garnituri_disponibile == tren_marfa.nr_garnituri_disponibile) and (this->nr_garnituri_rezervate == tren_marfa.nr_garnituri_rezervate);
}

string TrenDeMarfa::toStringDelimiter(string delim)
{
	return "TrenM" + delim + CompanieFeroviara::toStringDelimiter(delim) + delim + to_string(marfa) + delim + to_string(nr_garnituri_disponibile) + delim + to_string(nr_garnituri_rezervate);
}

//destructor
TrenDeMarfa::~TrenDeMarfa() {

}