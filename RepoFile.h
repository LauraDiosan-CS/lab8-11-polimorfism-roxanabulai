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
	CompanieFeroviara* getCompanieFeroviara(int pos);
	void addCompanieFeroviara(CompanieFeroviara* p);
	void updateCompanieFeroviara(CompanieFeroviara* trenVechi, CompanieFeroviara* trenNou);
	void deleteCompanieFeroviara(CompanieFeroviara* tren);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};

//folosim polimorfism de 2 ori
//class Service() {
	//RepoFile* repofile;
//}