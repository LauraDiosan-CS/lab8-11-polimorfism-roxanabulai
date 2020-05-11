#include "TestsService.h"
#include "Service.h"
#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include <assert.h>
#include <vector>
#include "Exceptionh.h"

void TestsService::testGetAllTXT()
{
	RepoFile* repoFileTXT=new RepoFileTXT();
	RepoUser* repo_user = new RepoUser();

	User* u=new User("Ana", "222abcd");
	repo_user->addUser(u);

	Service serv(repoFileTXT, repo_user);
	serv.initRepoTXT("TestsService.txt");

	TrenDeMarfa* tren_marfa = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDePersoane* tren_persoane = new TrenDePersoane("Aburi", "Alstom", 300, 222, 150, 150);
	try { serv.addGarnitura(tren_marfa);
		assert(serv.getAllGarnituri().size() == 2);
	}
	catch (MyException &ex)
	{
		
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}

	try { serv.addGarnitura(tren_persoane);
		assert(serv.getAllGarnituri().size() == 3);
		assert(*serv.getAllGarnituri()[1] == *tren_marfa->clone());
		assert(*serv.getAllGarnituri()[2] == *tren_persoane->clone());
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}

	
	

}

void TestsService::testGetAllCSV() {
	RepoFile* repoFileCSV= new RepoFileCSV();
	RepoUser* repo_user=new RepoUser();

	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileCSV, repo_user);
	serv.initRepoCSV("TestsService.csv");

	TrenDeMarfa* tren_marfa = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 55);
	TrenDePersoane* tren_persoane = new TrenDePersoane("Aburi", "Alstom", 300, 222, 150, 150);
	try {
		serv.addGarnitura(tren_marfa);
		assert(serv.getAllGarnituri().size() == 1);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	try { serv.addGarnitura(tren_persoane); 
		assert(serv.getAllGarnituri().size() == 2);
		assert(*serv.getAllGarnituri()[0] == *tren_marfa->clone());
		assert(*serv.getAllGarnituri()[1] == *tren_persoane->clone());
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	

	
}

void TestsService::testAddTrenTXT()
{
	RepoFile* repoFileTXT = new RepoFileTXT();
	RepoUser* repo_user=new RepoUser();
	
	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileTXT, repo_user);
	serv.initRepoTXT("TestsService.txt");

	TrenDeMarfa* t = new TrenDeMarfa("Regional", "Alstom", 100, "lemne", 95, 270);
	try { serv.addGarnitura(t); 
		assert(serv.getAllGarnituri().size() == 4);
		assert(*serv.getAllGarnituri()[3] == *t->clone());
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	

}
void TestsService::testAddTrenCSV() {
	RepoFile* repoFileCSV=new RepoFileCSV();
	RepoUser* repo_user = new RepoUser();

	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileCSV, repo_user);
	serv.initRepoCSV("TestsService.csv");

	TrenDeMarfa* t = new TrenDeMarfa("Regional", "Alstom", 100, "carbune", 45, 20);
	try { serv.addGarnitura(t);
		assert(serv.getAllGarnituri().size() == 3);
		assert(*serv.getAllGarnituri()[2] == *t->clone());
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	

}

void TestsService::testUpdateTrenTXT()
{
	RepoFile* repoFileTXT=new RepoFileTXT();
	RepoUser* repo_user = new RepoUser();

	User* u=new User("Ana", "1456abcd");
	repo_user->addUser(u);

	Service serv(repoFileTXT, repo_user);
	serv.initRepoTXT("TestsService.txt");

	TrenDeMarfa* t1 = new TrenDeMarfa("Aaaaaaa", "bbbbbbb", 100, "carbune", 45, 55);
	try { serv.addGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t2 = new TrenDeMarfa("Aburi", "mmmmm", 250, "carbune", 1500, 595);
	try { serv.addGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t3 = new TrenDeMarfa("Regional", "ttttt", 125, "carbune", 70, 75);
	try { serv.updateGarnitura(t2, t3); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(*serv.getAllGarnituri()[5] == *t3->clone());
	try { serv.updateGarnitura(t1, t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(*serv.getAllGarnituri()[4] == *t2->clone());

}
void TestsService::testUpdateTrenCSV() {
	RepoFile* repoFileCSV = new RepoFileCSV();
	RepoUser* repo_user =new RepoUser();

	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileCSV, repo_user);
	serv.initRepoCSV("TestsService.csv");
	TrenDeMarfa* t1 = new TrenDeMarfa("Accelerat", "Alstom", 100, "carbune", 45, 55);
	try { serv.addGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t2 = new TrenDeMarfa("Aburi", "Alstom", 250, "carbune", 150, 55);
	try { serv.addGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t3 = new TrenDeMarfa("Regional", "Alstom", 125, "carbune", 70, 55);
	try { serv.updateGarnitura(t2,t3); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(*repoFileCSV->getTren(4) == *t3->clone());
	try { serv.updateGarnitura(t1, t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(*repoFileCSV->getTren(3) == *t2->clone());
}

void TestsService::testDeleteTrenCSV()
{
	RepoFile* repoFileCSV=new RepoFileCSV();
	RepoUser* repo_user = new RepoUser();

	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileCSV, repo_user);
	serv.initRepoCSV("TestsService.csv");
	TrenDeMarfa* t1 = new TrenDeMarfa("Rrrrrrrrrrr", "Alstommm", 100, "carbune", 45, 55);
	try { serv.addGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t2 = new TrenDeMarfa("Cu aburiiiiiiiiii", "Alstom", 100, "carbune", 5, 95);
	try { serv.addGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	assert(serv.getAllGarnituri().size() == 7);
	try { serv.deleteGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(repoFileCSV->getSize() == 6);
	assert(*serv.getAllGarnituri()[5] == *t1->clone());
	try { serv.deleteGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(serv.getAllGarnituri().size() == 5);

}

void TestsService::testDeleteTrenTXT() {
	RepoFile* repoFileTXT=new RepoFileTXT();
	RepoUser* repo_user=new RepoUser();

	User* u=new User("Ana", "123abcd");
	repo_user->addUser(u);

	Service serv(repoFileTXT, repo_user);
	serv.initRepoTXT("TestsService.txt");
	TrenDeMarfa* t1 = new TrenDeMarfa("Rrrrrrrrr", "Alstom", 100, "carbune", 45, 55);
	try { serv.addGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	TrenDeMarfa* t2 = new TrenDeMarfa("Cu aburiiiiii", "Alstom", 100, "carbune", 5, 95);
	try { serv.addGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren existent deja!!") != 0);
	}
	assert(serv.getAllGarnituri().size() == 8);
	try { serv.deleteGarnitura(t2); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(serv.getAllGarnituri().size() == 7);
	assert(*serv.getAllGarnituri()[6] == *t1->clone());
	try { serv.deleteGarnitura(t1); }
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Ati introdus un tren care nu exista!!!!") != 0);
	}
	assert(serv.getAllGarnituri().size() == 6);
}
TestsService::TestsService() {

}
TestsService::~TestsService() {

}
void TestsService::testLogin() {
	RepoUser* repo_user = new RepoUser();
	RepoFile* repo = new RepoFileTXT();
	Service serv(repo, repo_user);
	
	assert(serv.login("Bogdan", "101rt") == -1);
	assert(serv.login("Anaa", "123ABC") == -1);

}
void TestsService::testAll()
{

	this->testGetAllTXT();
	this->testGetAllCSV();
	this->testAddTrenTXT();
	this->testAddTrenCSV();
	this->testUpdateTrenCSV();
	this->testUpdateTrenTXT();
	this->testDeleteTrenCSV();
	this->testDeleteTrenTXT();
	this->testLogin();
}
