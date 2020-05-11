#include "TrenDePersoane.h"
#include<vector>
#include<sstream>

//constructor implicit
TrenDePersoane::TrenDePersoane() : CompanieFeroviara() {
	nr_locuri = 0;
	nr_garnituri_disponibile = 0;
	nr_garnituri_rezervate = 0;
}
//conctructor general cu parametri
TrenDePersoane::TrenDePersoane(string nume_model, string nume_producator, int nr_vagoane, int nr_locuri, int nr_garnituri_disponibile, int nr_garnituri_rezervate) :
	CompanieFeroviara(nume_model, nume_producator, nr_vagoane) {
	this->nr_locuri = nr_locuri;
	this->nr_garnituri_disponibile = nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = nr_garnituri_rezervate;
}
//constructor de copiere
TrenDePersoane::TrenDePersoane(const TrenDePersoane& tren_persoane) :CompanieFeroviara(tren_persoane) {
	this->nr_locuri = tren_persoane.nr_locuri;
	this->nr_garnituri_disponibile = tren_persoane.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = tren_persoane.nr_garnituri_rezervate;
}
//getteri
int TrenDePersoane::get_nr_locuri() {
	return this->nr_locuri;
}
int TrenDePersoane::get_nr_garnituri_disponibile() {
	return this->nr_garnituri_disponibile;
}
int TrenDePersoane::get_nr_garnituri_rezervate() {
	return this->nr_garnituri_rezervate;
}
//setteri
void TrenDePersoane::set_nr_locuri(int new_nr_locuri) {
	this->nr_locuri = new_nr_locuri;
}
void TrenDePersoane::set_nr_garnituri_disponibile(int new_nr_garnituri_disponibile) {
	this->nr_garnituri_disponibile = new_nr_garnituri_disponibile;
}
void TrenDePersoane::set_nr_garnituri_rezervate(int new_nr_garnituri_rezervate) {
	this->nr_garnituri_rezervate = new_nr_garnituri_rezervate;
}
//operator =
TrenDePersoane& TrenDePersoane::operator=(const TrenDePersoane& tren_persoane)
{
	CompanieFeroviara::operator=(tren_persoane);
	this->nr_locuri = tren_persoane.nr_locuri;
	this->nr_garnituri_disponibile = tren_persoane.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = tren_persoane.nr_garnituri_rezervate;
	return *this;
}
//operator ==
bool TrenDePersoane::operator==(const TrenDePersoane& tren_persoane)
{
	return CompanieFeroviara::operator==(tren_persoane) and (this->nr_locuri == tren_persoane.nr_locuri)
		and (this->nr_garnituri_disponibile == tren_persoane.nr_garnituri_disponibile) and (this->nr_garnituri_rezervate == tren_persoane.nr_garnituri_rezervate);

}

string TrenDePersoane::toStringDelimiter(string delim)
{
	return "TrenP" + delim + CompanieFeroviara::toStringDelimiter(delim) + delim + to_string(nr_locuri) + delim + to_string(nr_garnituri_disponibile) + delim + to_string(nr_garnituri_rezervate);
}
//clone
CompanieFeroviara* TrenDePersoane::clone() {
	return new TrenDePersoane(this->nume_model, this->nume_producator, this->nr_vagoane, this->nr_locuri, this->nr_garnituri_disponibile, this->nr_garnituri_rezervate);
}
//destructor
TrenDePersoane::~TrenDePersoane() {

}