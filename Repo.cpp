#include "RepoFile.h"

//constructor implicit
RepoFile::RepoFile() {

}
//constructor general vu param
RepoFile::RepoFile(string fileName) {
	this->fileName = fileName;
}

void RepoFile::setFileName(string fileName) {
	this->fileName = fileName;
}
//destructor
RepoFile::~RepoFile() {

}

vector<CompanieFeroviara*> RepoFile::getAll()
{
	return this->trenuri;
}

int RepoFile::getSize()
{
	return this->trenuri.size();
}

CompanieFeroviara* RepoFile::getCompanieFeroviara(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->trenuri[pos]->clone();
	}
	return new CompanieFeroviara();
}

void RepoFile::addCompanieFeroviara(CompanieFeroviara* p)
{
	if (this->trenuri.size() == 0)
		this->trenuri.push_back(p->clone());
	else {
		CompanieFeroviara* ult_tren = this->getCompanieFeroviara(trenuri.size() - 1)->clone();
		deleteCompanieFeroviara(ult_tren);
		trenuri.push_back(p->clone());
		trenuri.push_back(ult_tren);
	}
	this->saveToFile();

}

void RepoFile::updateCompanieFeroviara(CompanieFeroviara* trenVechi, CompanieFeroviara* trenNou)
{
	for (int i = 0; i < this->trenuri.size(); i++)
	{
		if (*(this->getCompanieFeroviara(i)) == *trenVechi)
		{
			delete this->trenuri[i];
			this->trenuri[i] = trenNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteCompanieFeroviara(CompanieFeroviara* p)
{
	for (int i = 0; i < this->trenuri.size(); i++)
	{
		// this->produse.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
		if (**(this->trenuri.begin() + i) == *p)
		{
			delete this->trenuri[i];
			//este necesar un iterator pt. metoda erase
			this->trenuri.erase(this->trenuri.begin() + i);
			this->saveToFile();
			return;
		}
	}
}


void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->trenuri[i];
	}
	this->trenuri.clear();
}
