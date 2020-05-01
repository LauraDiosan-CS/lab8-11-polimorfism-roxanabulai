#include "CompanieFeroviara.h"
#include<string.h>
#include<iostream>
using namespace std;
//constructor implicit
CompanieFeroviara::CompanieFeroviara() {
	this->nr_vagoane = 0;
}
//constructor cu parametri
CompanieFeroviara::CompanieFeroviara(string nume_model, string nume_producator, int nr_vagoane) {
	this->nume_model = nume_model;
	this->nume_producator = nume_producator;
	this->nr_vagoane = nr_vagoane;
}
//constructor de copiere
CompanieFeroviara::CompanieFeroviara(const CompanieFeroviara& comp_ferov) {
	this->nume_model = comp_ferov.nume_model;
	this->nume_producator = comp_ferov.nume_producator;
	this->nr_vagoane = comp_ferov.nr_vagoane;
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
CompanieFeroviara& CompanieFeroviara::operator=(const CompanieFeroviara& comp_fer)
{
	this->nume_model = comp_fer.nume_model;
	this->nume_producator = comp_fer.nume_producator;
	this->nr_vagoane = comp_fer.nr_vagoane;
	return *this;
}
//operator ==
bool CompanieFeroviara::operator==(const CompanieFeroviara& comp_ferov)
{
	return (this->nume_model == comp_ferov.nume_model) and (this->nume_producator == comp_ferov.nume_producator) and (this->nr_vagoane == comp_ferov.nr_vagoane);
}

string CompanieFeroviara::toStringDelimiter(string delim)
{
	return this->nume_model + delim + this->nume_producator + delim + to_string(this->nr_vagoane);
}
//clone
CompanieFeroviara* CompanieFeroviara::clone()
{
	return new CompanieFeroviara(this->nume_model, this->nume_producator, this->nr_vagoane);
}
//destructor
CompanieFeroviara::~CompanieFeroviara() {

}