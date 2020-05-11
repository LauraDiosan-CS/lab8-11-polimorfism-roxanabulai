#include <assert.h>
#include "TestsRepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"

void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addTren(new CompanieFeroviara());
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenDeMarfa* tren_marfa = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDePersoane* tren_persoane = new TrenDePersoane("Aburi", "Alstom", 300, 222, 150, 150);
	repoFile->addTren(tren_marfa);
	repoFile->addTren(tren_persoane);
	vector<CompanieFeroviara*> trenuri = repoFile->getAll();
	assert(*trenuri[0] == *tren_marfa->clone());
	assert(*trenuri[1] == *tren_persoane->clone());
}

void TestRepoFile::testGetTren()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenDeMarfa* t = new TrenDeMarfa("Accelerat", "Alstom", 700, "carbune", 45, 55);
	repoFile->addTren(t);
	assert(*repoFile->getTren(0) == *t->clone());
	assert(*repoFile->getTren(-1) == *(new CompanieFeroviara()));
	assert(*repoFile->getTren(1) == *(new CompanieFeroviara()));
}

void TestRepoFile::testAddTren()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenDeMarfa* t = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 20);
	repoFile->addTren(t);
	assert(*repoFile->getTren(0) == *t->clone());
}

void TestRepoFile::testUpdateTren()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenDeMarfa* t1 = new TrenDeMarfa("Accelerat", "Alstom", 100, "carbune", 45, 55);
	repoFile->addTren(t1);
	TrenDeMarfa* t2 = new TrenDeMarfa("Aburi", "Alstom", 250, "carbune", 150, 55);
	TrenDeMarfa* t3 = new TrenDeMarfa("Regional", "Alstom", 125, "carbune", 70, 55);
	repoFile->updateTren(t3, t2);
	assert(*repoFile->getTren(0) == *t1);
	repoFile->updateTren(t1, t2);
	assert(*repoFile->getTren(0) == *t2);
}

void TestRepoFile::testDeleteTren()
{
	RepoFile* repoFile = new RepoFileTXT();
	TrenDeMarfa* t1 = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	repoFile->addTren(t1);
	TrenDeMarfa* t2 = new TrenDeMarfa("Cu aburi", "Alstom", 100, "carbune", 5, 95);
	repoFile->addTren(t2);
	repoFile->deleteTren(t2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getTren(0) == *t1);
	repoFile->deleteTren(t1);
	assert(repoFile->getSize() == 0);
}

void TestRepoFile::testLoadFromFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == 2);
	assert(trenuriIn.size() == 2);
	assert(repoFile->getSize() == this->trenuriIn.size());
	assert(*repoFile->getTren(0) == *this->trenuriIn[0]);
	assert(*repoFile->getTren(1) == *this->trenuriIn[1]);
}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->trenuriIn.size());
	assert(*repoFile->getTren(0) == *this->trenuriIn[0]);
	assert(*repoFile->getTren(1) == *this->trenuriIn[1]);
}

void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameInTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	TrenDeMarfa* newTren = new TrenDeMarfa("Accelerat", "Alstom", 100, "carbune", 45, 55);
	repoFile->addTren(newTren);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->trenuriIn.size() + 1);
	vector<CompanieFeroviara*> trenuri = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*trenuri[i] == *this->trenuriIn[i]);
	}
	assert(*trenuri[trenuri.size() - 1] == *newTren);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCSV);
	TrenDeMarfa* newTren = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	repoFile->addTren(newTren);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->trenuriIn.size() + 1);
	vector<CompanieFeroviara*> trenuri = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*trenuri[i] == *this->trenuriIn[i]);
	}
	assert(*trenuri[trenuri.size() - 1] == *newTren);
}

TestRepoFile::TestRepoFile()
{
	TrenDeMarfa* t1 = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDePersoane* t2 = new TrenDePersoane("Aburi", "Alstom", 100, 900, 45, 55);
	this->trenuriIn.push_back(t1);
	this->trenuriIn.push_back(t2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetTren();
	this->testAddTren();
	this->testUpdateTren();
	this->testDeleteTren();
	this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();
}
