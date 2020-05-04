#pragma once
#include "RepoFile.h"

class RepoFileCSV : public RepoFile {
public:
	RepoFileCSV(); //contructor implicit
	RepoFileCSV(string fileName); //constructor general cu parametri
	~RepoFileCSV(); //destructor

	void loadFromFile();
	void saveToFile();
};