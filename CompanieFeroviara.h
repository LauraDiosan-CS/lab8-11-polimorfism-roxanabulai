#pragma once
#ifndef COMPANIE_FEROVIARA
#define COMPANIE_FEROVIARA

#include<string>
using namespace std;
class CompanieFeroviara {
protected:
	string nume_model;
	string nume_producator;
	int nr_vagoane;
	int nr_garnituri_disponibile;
	int nr_garnituri_rezervate;
public:
	CompanieFeroviara();//constructor implicit
	CompanieFeroviara(string, string, int, int, int);//constructor general cu parametri
	CompanieFeroviara(const CompanieFeroviara&);//constructor de copiere
	~CompanieFeroviara(); //destructor

	virtual CompanieFeroviara* clone();

	//getteri
	string get_nume_model();
	string get_nume_producator();
	int get_nr_vagoane();
	int get_nr_garnituri_disponibile();
	int get_nr_garnituri_rezervate();
	//setteri
	void set_nume_model(string);
	void set_nume_producator(string);
	void set_nr_vagoane(int);
	void set_nr_garnituri_disponibile(int);
	void set_nr_garnituri_rezervate(int);

	CompanieFeroviara& operator=(const CompanieFeroviara&);
	bool operator==(const CompanieFeroviara&);

	virtual string toStringDelimiter(string delim);

};
#endif 