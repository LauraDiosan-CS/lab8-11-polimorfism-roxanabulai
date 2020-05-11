#include "CompanieFeroviara.h"
#include<string.h>
#include<iostream>
using namespace std;
//constructor implicit
CompanieFeroviara::CompanieFeroviara() {
	this->nr_vagoane = 0;
	this->nr_garnituri_disponibile = 0;
	this->nr_garnituri_rezervate = 0;
}
//constructor general cu parametri
CompanieFeroviara::CompanieFeroviara(string nume_model, string nume_producator, int nr_vagoane, int nr_garnituri_disponibile, int nr_garnituri_rezervate) {
	this->nume_model = nume_model;
	this->nume_producator = nume_producator;
	this->nr_vagoane = nr_vagoane;
	this->nr_garnituri_disponibile = nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = nr_garnituri_rezervate;
}
//constructor de copiere
CompanieFeroviara::CompanieFeroviara(const CompanieFeroviara& comp_ferov) {
	this->nume_model = comp_ferov.nume_model;
	this->nume_producator = comp_ferov.nume_producator;
	this->nr_vagoane = comp_ferov.nr_vagoane;
	this->nr_garnituri_disponibile = comp_ferov.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = comp_ferov.nr_garnituri_rezervate;
}
//getteri
string CompanieFeroviara::get_nume_model() {
	return this->nume_model;
}
string CompanieFeroviara::get_nume_producator() {
	return this->nume_producator;
}
int CompanieFeroviara::get_nr_vagoane() {
	return this->nr_vagoane;
}
int CompanieFeroviara::get_nr_garnituri_disponibile() {
	return this->nr_garnituri_disponibile;
}
int CompanieFeroviara::get_nr_garnituri_rezervate() {
	return this->nr_garnituri_rezervate;
}
//setteri
void CompanieFeroviara::set_nume_model(string new_nume_model) {
	this->nume_model = new_nume_model;
}
void CompanieFeroviara::set_nume_producator(string new_nume_producator) {
	this->nume_producator = new_nume_producator;
}
void CompanieFeroviara::set_nr_vagoane(int new_nr_vagoane) {
	this->nr_vagoane = new_nr_vagoane;
}
void CompanieFeroviara::set_nr_garnituri_disponibile(int new_nr_garnituri_disponibile) {
	this->nr_garnituri_disponibile = new_nr_garnituri_disponibile;
}
void CompanieFeroviara::set_nr_garnituri_rezervate(int new_nr_garnituri_rezervate) {
	this->nr_garnituri_rezervate = new_nr_garnituri_rezervate;
}
//operator =
CompanieFeroviara& CompanieFeroviara::operator=(const CompanieFeroviara& comp_fer)
{
	this->nume_model = comp_fer.nume_model;
	this->nume_producator = comp_fer.nume_producator;
	this->nr_vagoane = comp_fer.nr_vagoane;
	this->nr_garnituri_disponibile = comp_fer.nr_garnituri_disponibile;
	this->nr_garnituri_rezervate = comp_fer.nr_garnituri_rezervate;
	return *this;
}
//operator ==
bool CompanieFeroviara::operator==(const CompanieFeroviara& comp_ferov)
{
	return (this->nume_model == comp_ferov.nume_model) and (this->nume_producator == comp_ferov.nume_producator) and (this->nr_vagoane == comp_ferov.nr_vagoane)
		and (this->nr_garnituri_disponibile == comp_ferov.nr_garnituri_disponibile) and (this->nr_garnituri_rezervate == comp_ferov.nr_garnituri_rezervate);
}

string CompanieFeroviara::toStringDelimiter(string delim)
{
	return this->nume_model + delim + this->nume_producator + delim + to_string(this->nr_vagoane) + delim + to_string(this->nr_garnituri_disponibile) + delim + to_string(this->nr_garnituri_disponibile);
}
//clone
CompanieFeroviara* CompanieFeroviara::clone()
{
	return new CompanieFeroviara(this->nume_model, this->nume_producator, this->nr_vagoane, this->nr_garnituri_disponibile, this->nr_garnituri_rezervate);
}
//destructor
CompanieFeroviara::~CompanieFeroviara() {

}