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

CompanieFeroviara* RepoFile::getTren(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->trenuri[pos]->clone();
	}
	return new CompanieFeroviara();
}

void RepoFile::addTren(CompanieFeroviara* p)
{
	this->trenuri.push_back(p->clone());
	this->saveToFile();
}

void RepoFile::updateTren(CompanieFeroviara* trenVechi, CompanieFeroviara* trenNou)
{
	for (int i = 0; i < this->trenuri.size(); i++)
	{
		if (*(this->getTren(i)) == *trenVechi)
		{
			delete this->trenuri[i];
			this->trenuri[i] = trenNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteTren(CompanieFeroviara* p)
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
