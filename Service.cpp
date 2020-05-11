#include "Service.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "Exceptionh.h"
#include <string>
#include <iostream>
#include <vector>
#include "Exception2.h"
#include "Exception3.h"
using namespace std;

//constructor implicit
Service::Service() {

}
//constructor param
Service::Service(RepoFile* repo, RepoUser* repo_user)
{
	this->repo = repo;
	this->repo_user = repo_user;
	
	
}
void Service::initRepoTXT( string fileName)
{
	repo->setFileName(fileName);
	repo->loadFromFile();
	repo->saveToFile();
}
void Service::initRepoCSV(string fileName)
{
	repo->setFileName(fileName);
	repo->loadFromFile();
	repo->saveToFile();
}
void Service::initRepo(string fileN)
{
	repo->setFileName(fileN);
	repo->loadFromFile();
}
void Service::initUser(RepoUser* repoUser)
{
	User* u1 = new User("Roxi", "123ABC");
	User* u2 = new User("Bianca", "12ad");
	repo_user->addUser(u1);
	repo_user->addUser(u2);
	
}
void Service::setRepo(RepoFile* repoFile)
{
	this->repo = repoFile;
}
void Service::setUsers(RepoUser* repoUser)
{
	this->repo_user = repoUser;
}
//login
int Service::login(string u, string p)
{
	User* usr = new User(u, p);
	int m = repo_user->find(usr);//-1 daca nu il gaseste
	return m;//!=-1 daca il gaseste
}
//logout
void Service::logout(string u, string p) {
	User* user = new User(u, p);
	repo_user->deleteUser(user);

}
/*
void Service::updateGarnituraMarfa(TrenDeMarfa* tren_vechi, TrenDeMarfa* tren_nou)
{
	
	vector<TrenDeMarfa*> c = 
	int ok = 0;
	for (TrenDeMarfa* current : c)
	{
		if (current->operator==(*tren_vechi))
		{
			ok = 1;
		}

	}
	if (ok == 0)
	{
		throw MyException("Ati introdus un tren care nu exista!!!!");
	}
	else
	{
		repo->updateTren(tren_vechi, tren_nou);
	}

}*/
//add,update,delete
void Service::addGarnitura(CompanieFeroviara* comp_ferov) {
	vector<CompanieFeroviara*> c = repo->getAll();
	for (CompanieFeroviara* current : c)
	{
		if (current->operator==(*comp_ferov))
		{
			throw MyException("Ati introdus un tren existent deja!!");
		}
			
	}
	repo->addTren(comp_ferov);
}
void Service::updateGarnitura(CompanieFeroviara* comp_ferov, CompanieFeroviara* tren_nou) {
	vector<CompanieFeroviara*> c = repo->getAll();
	int ok1 = 0;
	int ok2 = 0;
	int nr = 0;
	for (CompanieFeroviara* current : c)
	{	
		if(current->get_nume_model()==comp_ferov->get_nume_model())
		{
			ok1 = 1; nr++;
		}
	
	}
	if (ok1 == 0 && nr==1)
	{
	throw MyException("Nu exista niciun tren cu acest nume");
	}
	
	else if (comp_ferov->get_nume_model()==tren_nou->get_nume_model())
	{
		throw MyException2("Trenul vechi si trenul nou acelasi nume");
	}
	
	else if (nr > 1)
	{
		throw MyException3("Exista mai multe trenuri cu acest model");
	}

	else
	{
		repo->updateTren(comp_ferov, tren_nou);
	}
	
}
void Service::deleteGarnitura(CompanieFeroviara* comp_ferov) {
	vector<CompanieFeroviara*> c = repo->getAll();
	int ok = 0;
	for (CompanieFeroviara* current : c)
	{
		if (current->get_nume_model()==comp_ferov->get_nume_model() and current->get_nume_producator()==comp_ferov->get_nume_producator() and current->get_nr_vagoane()==comp_ferov->get_nr_vagoane() and current->get_nr_garnituri_disponibile()==comp_ferov->get_nr_garnituri_disponibile() and current->get_nr_garnituri_rezervate()==comp_ferov->get_nr_garnituri_rezervate())
		{
			ok = 1;
			repo->deleteTren(comp_ferov);
		}

	}
	if (ok == 0)
	{
		throw MyException("Ati introdus un tren care nu exista!!!!");
	}

}

vector<CompanieFeroviara*> Service::getAllGarnituri() {
	return repo->getAll();
}

//destructor
Service::~Service() {

}