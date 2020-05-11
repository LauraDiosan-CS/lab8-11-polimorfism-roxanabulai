#include "TrenDePersoane.h"
#include<vector>
#include<sstream>

//constructor implicit
TrenDePersoane::TrenDePersoane() : CompanieFeroviara() {
	nr_locuri = 0;
}
//conctructor general cu parametri
TrenDePersoane::TrenDePersoane(string nume_model, string nume_producator, int nr_vagoane, int nr_locuri, int nr_garnituri_disponibile, int nr_garnituri_rezervate) :
	CompanieFeroviara(nume_model, nume_producator, nr_vagoane, nr_garnituri_disponibile, nr_garnituri_rezervate) {
	this->nr_locuri = nr_locuri;
}
//constructor de copiere
TrenDePersoane::TrenDePersoane(const TrenDePersoane& tren_persoane) : CompanieFeroviara(tren_persoane) {
	this->nr_locuri = tren_persoane.nr_locuri;

}
//get
int TrenDePersoane::get_nr_locuri() {
	return this->nr_locuri;
}
//set
void TrenDePersoane::set_nr_locuri(int new_nr_locuri) {
	this->nr_locuri = new_nr_locuri;
}

//operator =
TrenDePersoane& TrenDePersoane::operator=(const TrenDePersoane& tren_persoane)
{
	CompanieFeroviara::operator=(tren_persoane);
	this->nr_locuri = tren_persoane.nr_locuri;
	return *this;
}
//operator ==
bool TrenDePersoane::operator==(const TrenDePersoane& tren_persoane)
{
	return CompanieFeroviara::operator==(tren_persoane) and (this->nr_locuri == tren_persoane.nr_locuri);

}

string TrenDePersoane::toStringDelimiter(string delim)
{
	return "TrenP" + delim + this->nume_model + delim + this->nume_producator + delim + to_string(this->nr_vagoane) + delim + to_string(this->nr_locuri) + delim +
		to_string(this->nr_garnituri_disponibile) + delim + to_string(this->nr_garnituri_rezervate);
}
//clone
CompanieFeroviara* TrenDePersoane::clone() {
	return new TrenDePersoane(this->nume_model, this->nume_producator, this->nr_vagoane, this->nr_locuri, this->nr_garnituri_disponibile, this->nr_garnituri_rezervate);
}
//destructor
TrenDePersoane::~TrenDePersoane() {

}