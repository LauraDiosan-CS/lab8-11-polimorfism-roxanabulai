#pragma once
#ifndef TREN_DE_PERSOANE
#define TREN_DE_PERSOANE

#include "CompanieFeroviara.h"
class TrenDePersoane :public CompanieFeroviara {
private:
	int nr_locuri;
	int nr_garnituri_disponibile;
	int nr_garnituri_rezervate;
public:
	TrenDePersoane();//constructor implicit
	TrenDePersoane(string, string, int, int, int, int);//constructor general cu parametri
	TrenDePersoane(const TrenDePersoane&);//constructor de copiere

	//getteri
	int get_nr_locuri();
	int get_nr_garnituri_disponibile();
	int get_nr_garnituri_rezervate();
	//setteri
	void set_nr_locuri(int);
	void set_nr_garnituri_disponibile(int);
	void set_nr_garnituri_rezervate(int);

	TrenDePersoane& operator=(const TrenDePersoane&);
	bool operator==(const TrenDePersoane&);

	string toStringDelimiter(string);

	CompanieFeroviara* clone();

	~TrenDePersoane(); //destructor
};
#endif 