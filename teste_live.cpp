#include "RepoFileCSV.h"
#include "RepoFile.h"
#include "CompanieFeroviara.h"
#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"
#include <assert.h>
void teste_live() {
	RepoFile* repo = new RepoFileCSV("fisier-111-1.csv");
	repo->loadFromFile();
	CompanieFeroviara* g1 = new TrenDeMarfa("KBT8", "Fleishmann", 8, "carbuni", 10, 20);
	CompanieFeroviara* g2 = new TrenDePersoane("A0JK", "Neumann", 10, 200, 4, 30);
	CompanieFeroviara* g3 = new TrenDeMarfa("B1xC", "Aron", 11, "benzina", 9, 12);
	CompanieFeroviara* g4 = new TrenDePersoane("DIJ9", "Stora", 9, 150, 5, 28);
	assert(repo->getSize() == 2);
	assert(*(repo->getCompanieFeroviara(0)) == *g2);
	assert(*(repo->getCompanieFeroviara(1)) == *g1);
	repo->addCompanieFeroviara(g3);
	assert(repo->getSize() == 3);
	assert(*(repo->getCompanieFeroviara(0)) == *g2);
	assert(*(repo->getCompanieFeroviara(1)) == *g3);
	assert(*(repo->getCompanieFeroviara(2)) == *g1);
	repo->addCompanieFeroviara(g4);
	assert(repo->getSize() == 4);
	assert(*(repo->getCompanieFeroviara(0)) == *g2);
	assert(*(repo->getCompanieFeroviara(1)) == *g3);
	assert(*(repo->getCompanieFeroviara(2)) == *g4);
	assert(*(repo->getCompanieFeroviara(3)) == *g1);
	
}