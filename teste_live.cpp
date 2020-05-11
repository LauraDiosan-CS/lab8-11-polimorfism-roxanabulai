#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"
#include "Service.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoUser.h"
#include <assert.h>
#include "Teste_live.h"
#include "Exceptionh.h"
#include "Exception2.h"
#include "Exception3.h"
void teste_live() {
	RepoFile* repoFileTXT = new RepoFileTXT();
	RepoUser* repo_user = new RepoUser();

	Service serv(repoFileTXT, repo_user);
	serv.initRepoTXT("Teste_live.txt");
	TrenDeMarfa* g1 = new TrenDeMarfa("104", "Fleishmann", 8, "carbuni", 10, 20);
	TrenDePersoane* g2 = new TrenDePersoane("749", "Neumann", 10, 200, 4, 30);
	TrenDeMarfa* g3 = new TrenDeMarfa("951", "Aron", 11, "benzina", 9, 12);
	TrenDePersoane* g4 = new TrenDePersoane("104", "Alonso", 20, 300, 2, 10);
	TrenDeMarfa* g5 = new TrenDeMarfa("354", "Fierra", 12, "lemn", 11, 13);
	
	serv.addGarnitura(g1);
	serv.addGarnitura(g2);
	serv.addGarnitura(g3);
	try {
		serv.updateGarnitura(g2, g4);
		assert(serv.getAllGarnituri().size() == 3);
		assert(*serv.getAllGarnituri()[0] == *g1);
		assert(*serv.getAllGarnituri()[1] == *g4);
		assert(*serv.getAllGarnituri()[2] == *g3);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Nu exista niciun tren cu acest nume") != 0);
		assert(false);
	}
	catch (MyException2& ex)
	{
		assert(strcmp(ex.getMessage(), "Trenul vechi si trenul nou acelasi nume") != 0);
	}
	catch (MyException3& ex)
	{
		assert(strcmp(ex.getMessage(), "Exista mai multe trenuri cu acest model") != 0);
		assert(false);
	}
	try {
		TrenDeMarfa* tren = new TrenDeMarfa();
		tren->set_nume_model("770");
		serv.updateGarnitura(tren , g4);
		assert(serv.getAllGarnituri().size() == 3);
		assert(*serv.getAllGarnituri()[0] == *g1);
		assert(*serv.getAllGarnituri()[1] == *g4);
		assert(*serv.getAllGarnituri()[2] == *g3);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Nu exista niciun tren cu acest nume") == 0);
		
	}
	catch (MyException2& ex)
	{
		assert(strcmp(ex.getMessage(), "Trenul vechi si trenul nou acelasi nume") != 0);
	}
	catch (MyException3& ex)
	{
		assert(strcmp(ex.getMessage(), "Exista mai multe trenuri cu acest model") != 0);
		assert(false);
	}

	try {
		serv.updateGarnitura(g1, g4);
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Nu exista niciun tren cu acest nume") == 0);
		assert(false);

	}
	catch (MyException2& ex)
	{
		assert(strcmp(ex.getMessage(), "Trenul vechi si trenul nou acelasi nume") == 0);
		assert(serv.getAllGarnituri().size() == 3);
		assert(*serv.getAllGarnituri()[0] == *g1);
		assert(*serv.getAllGarnituri()[1] == *g4);
		assert(*serv.getAllGarnituri()[2] == *g3);
	}
	catch (MyException3& ex)
	{
		assert(strcmp(ex.getMessage(), "Exista mai multe trenuri cu acest model") == 0);
		
	}
	
	try {
		TrenDeMarfa* tren1 = new TrenDeMarfa();
		tren1->set_nume_model("770");
		serv.updateGarnitura(tren1, g5);
		//assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Nu exista niciun tren cu acest nume") != 0);
		assert(false);

	}
	catch (MyException2& ex)
	{
		assert(strcmp(ex.getMessage(), "Trenul vechi si trenul nou acelasi nume") != 0);
		assert(false);
	}
	catch (MyException3& ex)
	{
		assert(strcmp(ex.getMessage(), "Exista mai multe trenuri cu acest model") == 0);
		
	}

	try {
		serv.updateGarnitura(g1, g5);
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Nu exista niciun tren cu acest nume") == 0);
		assert(false);

	}
	catch (MyException2& ex)
	{
		assert(strcmp(ex.getMessage(), "Trenul vechi si trenul nou acelasi nume") != 0);
		assert(false);
	}
	catch (MyException3& ex)
	{
		assert(strcmp(ex.getMessage(), "Exista mai multe trenuri cu acest model") == 0);

	}
	
}
