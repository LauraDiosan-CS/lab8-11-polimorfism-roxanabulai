#pragma once
#ifndef TREN_DE_PERSOANE
#define TREN_DE_PERSOANE

#include "CompanieFeroviara.h"
#include <string>
class TrenDePersoane :public CompanieFeroviara {
private:
	int nr_locuri;
public:
	TrenDePersoane();//constructor implicit
	TrenDePersoane(string, string, int, int, int, int);//constructor general cu parametri
	TrenDePersoane(const TrenDePersoane&);//constructor de copiere

	//getteri
	int get_nr_locuri();

	//setteri
	void set_nr_locuri(int);

	TrenDePersoane& operator=(const TrenDePersoane&);
	bool operator==(const TrenDePersoane&);

	string toStringDelimiter(string);

	CompanieFeroviara* clone();

	~TrenDePersoane(); //destructor
};
#endif 