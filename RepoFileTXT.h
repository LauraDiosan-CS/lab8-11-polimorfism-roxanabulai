#pragma once
#include "RepoFile.h"

class RepoFileTXT : public RepoFile {
private:
	//vector<TrenDeMarfa*> trenuri_marfa;
public:
	RepoFileTXT(); //constructor implicit
	RepoFileTXT(string fileName); //constructor general cu parametri
	~RepoFileTXT(); //destructor

	void loadFromFile();
	void saveToFile();

	void getAll_garnituri_marfa();
	//void getAll_garnituri_persoane();
};