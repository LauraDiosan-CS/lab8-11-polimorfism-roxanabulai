#include <iostream>
#include <Windows.h>
#include "TestsCompanieFeroviara.h"
#include "TestsTrenDeMarfa.h"
#include "TestsTrenDePersoane.h"
#include "TestsRepoFile.h"
#include "Teste_live.h"
using namespace std;
int main() {
	/*HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);

	cout<<"  Testele pentru clasa COMPANIE FEROVIARA: ";
	TestCompanieFeroviara teste_companie_feroviara;
	teste_companie_feroviara.testAll();
	cout << "au trecut cu succes!" << endl;

	cout <<"  Testele pentru clasa TREN DE MARFA     : ";
	TestTrenDeMarfa teste_tren_marfa;
	teste_tren_marfa.testAll();
	cout << "au trecut cu succes!" << endl;

	cout <<"  Testele pentru clasa TREN DE PERSOANE  : ";
	TestTrenDePersoane teste_tren_persoane;
	teste_tren_persoane.testAll();
	cout << "au trecut cu succes!" << endl;

	cout <<"  Testele pentru Repo                    : ";
	TestRepoFile teste_repo;
	teste_repo.testAll();
	cout << "au trecut cu succes!" << endl;

	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	cout << endl;
	cout <<"GATAAA TEMA PTR LAB 10!!!" << endl;
	*/
	teste_live();
	cout << "gataa";
	return 0;
}