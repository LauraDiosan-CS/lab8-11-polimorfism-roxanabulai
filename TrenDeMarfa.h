#pragma once
#include "CompanieFeroviara.h"
#include <string>

class TrenDeMarfa : public CompanieFeroviara {
private:
	string marfa;

public:
	TrenDeMarfa();//constructor implicit
	TrenDeMarfa(string, string, int, string, int, int);//constructor general cu parametri
	TrenDeMarfa(const TrenDeMarfa&);//constructor de copiere
	~TrenDeMarfa(); //destructor

	//get
	string get_marfa();

	//set
	void set_marfa(string);

	TrenDeMarfa& operator=(const TrenDeMarfa&);
	bool operator==(const TrenDeMarfa&);

	CompanieFeroviara* clone();

	string toStringDelimiter(string);
};
