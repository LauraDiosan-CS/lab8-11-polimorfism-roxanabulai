#include "TrenDeMarfa.h"
#include<vector>
#include<sstream>

//constructor implicit
TrenDeMarfa::TrenDeMarfa() : CompanieFeroviara() {
}
//conctructor general cu parametri
TrenDeMarfa::TrenDeMarfa(string nume_model, string nume_producator, int nr_vagoane, string marfa, int nr_garnituri_disponibile, int nr_garnituri_rezervate) :
	CompanieFeroviara(nume_model, nume_producator, nr_vagoane, nr_garnituri_disponibile, nr_garnituri_rezervate) {
	this->marfa = marfa;
}
//constructor de copiere
TrenDeMarfa::TrenDeMarfa(const TrenDeMarfa& tren_marfa) : CompanieFeroviara(tren_marfa) {
	this->marfa = tren_marfa.marfa;
}
//get
string TrenDeMarfa::get_marfa() {
	return this->marfa;
}
//set
void TrenDeMarfa::set_marfa(string new_marfa) {
	this->marfa = new_marfa;
}

//operator =
TrenDeMarfa& TrenDeMarfa::operator=(const TrenDeMarfa& tren_marfa)
{
	CompanieFeroviara::operator=(tren_marfa);
	this->marfa = tren_marfa.marfa;
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
	return CompanieFeroviara::operator==(tren_marfa) and (this->marfa == tren_marfa.marfa);
}

string TrenDeMarfa::toStringDelimiter(string delim)
{
	return "TrenM" + delim + this->nume_model + delim + this->nume_producator + delim + to_string(this->nr_vagoane) + delim + this->marfa + delim +
		to_string(this->nr_garnituri_disponibile) + delim + to_string(this->nr_garnituri_rezervate);
}


//destructor
TrenDeMarfa::~TrenDeMarfa() {

}