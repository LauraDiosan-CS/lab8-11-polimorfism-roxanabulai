#include<iostream>
#include "Tests_CompanieFeroviara.h"
#include "Tests_TrenDePersoane.h"
#include "Tests_TrenDeMarfa.h"
#include "TestRepoFile.h"
using namespace std;
int main()
{
	TestCompanieFeroviara teste_companie_feroviara;
	teste_companie_feroviara.testAll();
	cout << "Teste ptr clasa CompanieFeroviara: SUCCES";
	cout << endl;
	TestTrenDeMarfa teste_tren_marfa;
	teste_tren_marfa.testAll();
	cout << "Teste ptr clasa TrenDeMarfa: SUCCES";
	cout << endl;
	TestTrenDePersoane teste_tren_persoane;
	teste_tren_persoane.testAll();
	cout << "Teste ptr clasa TrenDePersoane: SUCCES";
	cout << endl;
	TestRepoFile teste_repo;
	teste_repo.testAll();
	cout << "Teste ptr RepoFile: SUCCES";
	cout << endl;
	cout << "Gata!";
	
	return 0;

}