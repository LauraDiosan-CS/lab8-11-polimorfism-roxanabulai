#pragma once
#include "CompanieFeroviara.h"
#include "RepoFileCSV.h"
#include "RepoUser.h"
#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include <vector>
class Service
{
private:
	RepoFile* repo;
	RepoUser* repo_user;

public:
	Service(); //constructor implicit
	Service(RepoFile*, RepoUser*); //constructor cu parametri


	void initRepoTXT(string fileName);
	void initRepoCSV(string fileName);
	void initRepo(string fileN);
	void setRepo(RepoFile*);
	void setUsers(RepoUser*);
	void initUser(RepoUser*);
	int login(string, string);
	void logout(string, string);
	

	//void updateGarnituraMarfa(TrenDeMarfa* tren_vechi, TrenDeMarfa* tren_nou);
	//void updateGarnituraPersoane(TrenDePersoane* tren_persoane, TrenDePersoane* tren_persoane);

	void addGarnitura(CompanieFeroviara*);
	void updateGarnitura(CompanieFeroviara*, CompanieFeroviara*);
	void deleteGarnitura(CompanieFeroviara*);
	vector<CompanieFeroviara*> getAllGarnituri();


	~Service(); //destructor
};

