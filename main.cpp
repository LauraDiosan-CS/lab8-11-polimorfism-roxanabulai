#include <iostream>
#include <Windows.h>
#include "TestsCompanieFeroviara.h"
#include "TestsTrenDeMarfa.h"
#include "TestsTrenDePersoane.h"
#include "TestsRepoFile.h"
#include "TestsUser.h"
#include "TestsRepoUser.h"
#include "TestsService.h"
#include "UI.h"
#include "RepoUser.h"
#include "RepoFile.h"
#include "Service.h"
#include "Teste_live.h"

//EXCEPTII????

/*void work() {
	CompanieFeroviara* tren;
	try {


		tren = new TrenDeMarfa();
		if (tren->get_nume_model().size()==0)
			throw "Tren fara numele modelului !!!";
		if (tren->get_nume_producator().size() ==0)
			throw "Tren fara numele producatorului !!!";
		if (tren->get_nr_vagoane() == 0)
			throw "Tren fara numarul vagoanelor !!!";
		if (tren->get_nr_garnituri_disponibile() == 0)
			throw "Tren fara numarul garniturilor disponibile !!!";
		if (tren->get_nr_garnituri_rezervate() == 0)
			throw "Tren fara numaru darniturilor rezervate ";
		delete tren;

	}
	catch (...) {
		cout << "name exception : " << endl;
		
		throw;
	}
}*/

using namespace std;
int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);

	cout << "  Testele pentru clasa COMPANIE FEROVIARA: ";
	TestCompanieFeroviara teste_companie_feroviara;
	teste_companie_feroviara.testAll();
	cout << "au trecut cu succes!" << endl;

	cout << "  Testele pentru clasa TREN DE MARFA     : ";
	TestTrenDeMarfa teste_tren_marfa;
	teste_tren_marfa.testAll();
	cout << "au trecut cu succes!" << endl;

	cout << "  Testele pentru clasa TREN DE PERSOANE  : ";
	TestTrenDePersoane teste_tren_persoane;
	teste_tren_persoane.testAll();
	cout << "au trecut cu succes!" << endl;

	cout << "  Testele pentru Repo                    : ";
	TestRepoFile teste_repo;
	teste_repo.testAll();
	cout << "au trecut cu succes!" << endl;

	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	cout << endl;
	cout << "GATAAA TEMA PTR LAB 10!!!" << endl;
	cout << endl;

	SetConsoleTextAttribute(h, FOREGROUND_GREEN);
	cout << "  Testele pentru clasa USER              : ";
	TestsUser teste_user;
	teste_user.testAll();
	cout << "au trecut cu succes!"<<endl;

	cout << "  Testele pentru clasa REPO USER         : ";
	TestRepoUser teste_user_repo;
	teste_user_repo.testAll();
	cout << "au trecut cu succes!" << endl;

	/*cout << "  Testele pentru clasa Service+Exceptii  : ";
	TestsService teste_service;
	teste_service.testAll();
	cout << "au trecut cu succes!" << endl;
	cout << endl;*/

	teste_live();
	cout << endl;
	cout << "TESTE LIVE" << endl;

	/*SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << endl;
	cout << "               ***** Buna ziua! Bine ati venit la aceasta companie feroviara! *****" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	RepoFile* repo ;
	Service serv;
	UI ui(serv);
	ui.showMenu();*/
	return 0;
}
