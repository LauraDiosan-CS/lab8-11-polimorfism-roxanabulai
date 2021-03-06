#include "RepoFileCSV.h"
#include "TrenDeMarfa.h"
#include "TrenDePersoane.h"
#include <fstream>
//constructor implicit
RepoFileCSV::RepoFileCSV() : RepoFile()
{
}
//constructor general cu parametri
RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}
//destructor
RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 5) == "TrenM")
			{
				linie = linie.erase(0, 6);

				int pos = linie.find(delim);
				string nume_model = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume_producator = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_vagoane = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string marfa = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_garnituri_disponibile = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_garnituri_rezervate = stoi(linie.substr(0, pos));

				TrenDeMarfa* tren_marfa = new TrenDeMarfa(nume_model, nume_producator, nr_vagoane, marfa, nr_garnituri_disponibile, nr_garnituri_rezervate);
				this->addTren(tren_marfa);
			}
			else if (linie.substr(0, 5) == "TrenP")
			{
				linie = linie.erase(0, 6);

				int pos = linie.find(delim);
				string nume_model = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string nume_producator = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_vagoane = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_locuri = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_garnituri_disponibile = stoi(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				int nr_garnituri_rezervate = stoi(linie.substr(0, pos));

				TrenDePersoane* tren_persoane = new TrenDePersoane(nume_model, nume_producator, nr_vagoane, nr_locuri, nr_garnituri_disponibile, nr_garnituri_rezervate);
				this->addTren(tren_persoane);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (CompanieFeroviara* elem : this->trenuri)
		{
			f << elem->toStringDelimiter(",") << endl;
		}
	}
}
