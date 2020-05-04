#pragma once
#include "RepoFile.h"

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT(); //constructor implicit
	RepoFileTXT(string fileName); //constructor general cu parametri
	~RepoFileTXT(); //destructor

	void loadFromFile();
	void saveToFile();
};