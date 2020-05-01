#pragma once
#include "CompanieFeroviara.h"

class TrenDeMarfa : public CompanieFeroviara {
private:
	int marfa;
	int nr_garnituri_disponibile;
	int nr_garnituri_rezervate;
public:
	TrenDeMarfa();//constructor implicit
	TrenDeMarfa(string, string, int, int, int, int);//constructor general cu parametri
	TrenDeMarfa(const TrenDeMarfa&);//constructor de copiere
	~TrenDeMarfa(); //destructor

	//getteri
	int get_marfa();
	int get_nr_garnituri_disponibile();
	int get_nr_garnituri_rezervate();
	//setteri
	void set_marfa(int);
	void set_nr_garnituri_disponibile(int);
	void set_nr_garnituri_rezervate(int);

	TrenDeMarfa& operator=(const TrenDeMarfa&);
	bool operator==(const TrenDeMarfa&);

	CompanieFeroviara* clone();

	string toStringDelimiter(string);
};
