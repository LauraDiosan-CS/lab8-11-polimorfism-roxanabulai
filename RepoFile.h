#pragma once
#include "CompanieFeroviara.h"
#include <vector>

class RepoFile {
protected:
	vector<CompanieFeroviara*> trenuri; //punem * ptr polimorfism
	string fileName;
public:
	RepoFile(); //constructor implicit
	RepoFile(string fileName); //constructor general cu param
	~RepoFile(); //destructor

	void setFileName(string fileName);

	void emptyRepo();

	vector<CompanieFeroviara*> getAll();
	int getSize();
	CompanieFeroviara* getTren(int pos);
	void addTren(CompanieFeroviara* p);
	void updateTren(CompanieFeroviara* trenVechi, CompanieFeroviara* trenNou);
	void deleteTren(CompanieFeroviara* tren);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;

	//virtual void getAll_garnituri_marfa() = 0;
	//virtual void getAll_garnituri_persoane() = 0;
};

//folosim polimorfism de 2 ori
//class Service() {
	//RepoFile* repofile;
//}