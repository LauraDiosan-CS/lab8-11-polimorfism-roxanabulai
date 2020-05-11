#include <Windows.h>
#include "UI.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include <iostream>
#include <fstream>
#include "Exceptionh.h"
#include "TrenDeMarfa.h"
#include <vector>
#include <string>
using namespace std;


int UI::login()
{	
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);

	cout << "User: ";
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	cin >> user;

	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	cout << "Parola:";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	cin >> pass;
	
	return s.login(user, pass);//-1 daca nu il gaseste
}
void UI::choise_file(int& ok)
{
	RepoFile* repoFile;
	RepoUser* repoUser = new RepoUser();
	s.setUsers(repoUser);
	s.initUser(repoUser);
	
	const string fileNameInTxt = "Trenuri.txt";
	const string fileNameInCsv = "Trenuri.csv";
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	cout << "Doriti sa lucrati cu TXT sau CSV?" << endl;
	string opt;
	cout << " Fisier: ";
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	cin >> opt;
	if (opt == "TXT")
	{
		repoFile = new RepoFileTXT(fileNameInTxt);
		s.setRepo(repoFile);
		s.initRepo(fileNameInTxt);
		ok = 1;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << endl;
		cout << "Ati ales fisier TXT." << endl;
		cout << "Va rugam sa va logati!" << endl;
		//s.setDelim(" ");
	}
	if (opt == "CSV")
		{

			repoFile = new RepoFileCSV(fileNameInCsv);
			s.setRepo(repoFile);
			s.initRepo(fileNameInCsv);
			ok = 2;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE);
			cout << endl;
			cout << "Ati ales fisier CSV." << endl;
			cout << "Va rugam sa va logati!" << endl;
			//s.setDelim(",");
		}
	
	if (opt != "TXT" and opt != "CSV")
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Ati introudus gresit tipul fisierului! " << endl;
	}

}
void UI::logout() {
	s.logout(u.getUserName(), u.getPassword());
	cout << "La revedere!";
}
UI::UI(Service& s)
{
	s = s;
}
UI::UI() {

}
void UI::adauga_garnitura_marfa_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "Dati nr vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "Dati marfa: ";
	string marfa;
	cin >> marfa;
	cout << "Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDeMarfa* tren_marfa = new TrenDeMarfa(nume_model, nume_producator, nr_vagoane, marfa, nr_garnituri_disponibile, nr_garnituri_rezervate);
	try {
		s.addGarnitura(tren_marfa);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost adaugata! " << endl;
	}
	catch (MyException &ex) {
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << ex.getMessage() << endl;
	}
	
	cout << endl;
}
void UI::adauga_garnitura_persoane_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "Dati nr vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "Dati numarul locurilor: ";
	int nr_locuri;
	cin >> nr_locuri;
	cout << "Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDePersoane* tren_persoane=new TrenDePersoane(nume_model, nume_producator, nr_vagoane, nr_locuri, nr_garnituri_disponibile, nr_garnituri_rezervate);
	try {
		s.addGarnitura(tren_persoane);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost adaugata! " << endl;
	}
	catch (MyException &ex) {
		cout << ex.getMessage() << endl;
	}
}
void UI::delete_garnitura_marfa_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "Dati nr vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "Dati marfa: ";
	string marfa;
	cin >> marfa;
	cout << "Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDeMarfa* tren_marfa = new TrenDeMarfa(nume_model, nume_producator, nr_vagoane, marfa, nr_garnituri_disponibile, nr_garnituri_rezervate);
	
	try {
		s.deleteGarnitura(tren_marfa);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost stearsa! " << endl;
	}
	catch (MyException& ex) {
		cout << ex.getMessage() << endl;
	}
}

void UI::delete_garnitura_persoane_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Introduceti garnitura pe care doriti sa o stergeti: " << endl;
	cout << "   Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "   Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "   Dati nr vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "   Dati numarul locurilor: ";
	int nr_locuri;
	cin >> nr_locuri;
	cout << "   Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "   Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDePersoane* tren_persoane = new TrenDePersoane(nume_model, nume_producator, nr_vagoane, nr_locuri, nr_garnituri_disponibile, nr_garnituri_rezervate);
	try {
		s.deleteGarnitura(tren_persoane);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost stearsa! " << endl;
	}
	catch (MyException& ex) {
		cout << ex.getMessage() << endl;
	}
	
}

void UI::update_garnitura_persoane_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Introduceti garnitura pe care doriti sa o actualizati: " << endl;
	cout << "   Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "   Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "   Dati nr vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "   Dati numarul locurilor: ";
	int nr_locuri;
	cin >> nr_locuri;
	cout << "   Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "   Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDePersoane* tren_persoane = new TrenDePersoane(nume_model, nume_producator, nr_vagoane, nr_locuri, nr_garnituri_disponibile, nr_garnituri_rezervate);

	cout << "Introduceti caracteristicile garniturii actualizate: " << endl;
	cout << "   Dati numele modelului actualizat: ";
	string new_nume_model;
	cin >> new_nume_model;
	cout << "   Dati numele producatorului: ";
	string new_nume_producator;
	cin >> new_nume_producator;
	cout << "   Dati nr vagoanelor actualizat: ";
	int new_nr_vagoane;
	cin >> new_nr_vagoane;
	cout << "   Dati numarul locurilor actualizat: ";
	int new_nr_locuri;
	cin >> new_nr_locuri;
	cout << "   Dati nr garn disponibile actuzaliat: ";
	int new_nr_garnituri_disponibile;
	cin >> new_nr_garnituri_disponibile;
	cout << "   Dati nr garn rezervate actualzait: ";
	int new_nr_garnituri_rezervate;
	cin >> new_nr_garnituri_rezervate;
	TrenDePersoane* new_tren_persoane = new TrenDePersoane(new_nume_model, new_nume_producator, new_nr_vagoane, new_nr_locuri, new_nr_garnituri_disponibile, new_nr_garnituri_rezervate);


	try {
		s.updateGarnitura(tren_persoane, new_tren_persoane);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost actualizata! " << endl;
	}
	catch (MyException& ex) {
		cout << ex.getMessage() << endl;
	}
}

void UI::update_garnitura_marfa_UI() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "Introduceti garnitura pe care doriti sa o actualizati: " << endl;
	cout << "   Dati numele modelului: ";
	string nume_model;
	cin >> nume_model;
	cout << "   Dati numele producatorului: ";
	string nume_producator;
	cin >> nume_producator;
	cout << "   Dati numarul vagoanelor: ";
	int nr_vagoane;
	cin >> nr_vagoane;
	cout << "   Dati marfa: ";
	string marfa;
	cin >> marfa;
	cout << "   Dati nr garn disponibile: ";
	int nr_garnituri_disponibile;
	cin >> nr_garnituri_disponibile;
	cout << "   Dati nr garn rezervate: ";
	int nr_garnituri_rezervate;
	cin >> nr_garnituri_rezervate;
	TrenDeMarfa* tren_marfa = new TrenDeMarfa(nume_model, nume_producator, nr_vagoane, marfa, nr_garnituri_disponibile, nr_garnituri_rezervate);

	cout << "Introduceti caracteristicile garniturii actualizate: " << endl;
	cout << "   Dati numele modelului actualizat: ";
	string new_nume_model;
	cin >> new_nume_model;
	cout << "   Dati numele producatorului: ";
	string new_nume_producator;
	cin >> new_nume_producator;
	cout << "   Dati nr vagoanelor actualizat: ";
	int new_nr_vagoane;
	cin >> new_nr_vagoane;
	cout << "   Dati marfa actualizata: ";
	string new_marfa;
	cin >> new_marfa; 
	cout << "   Dati nr garn disponibile actualizat: ";
	int new_nr_garnituri_disponibile;
	cin >> new_nr_garnituri_disponibile;
	cout << "   Dati nr garn rezervate actualizat: ";
	int new_nr_garnituri_rezervate;
	cin >> new_nr_garnituri_rezervate;
	TrenDeMarfa* new_tren_marfa = new TrenDeMarfa(new_nume_model, new_nume_producator,new_nr_vagoane, new_marfa, new_nr_garnituri_disponibile, new_nr_garnituri_rezervate);

	try {
		s.updateGarnitura(tren_marfa, new_tren_marfa);
		cout << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		cout << "Garnitura a fost actualizata! " << endl;
	}
	catch (MyException& ex) {
		cout << ex.getMessage() << endl;
	}
}

void UI::get_all_garnituri_UI(string delim) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);
	cout << "  GARNITURI: ";
	cout << endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	vector<CompanieFeroviara*> all = s.getAllGarnituri();
	//int pos = 0;
	for (CompanieFeroviara* c : all)
		//cout << pos << ": ";
		cout<< c->toStringDelimiter(delim) << endl; 
		//pos++;
	cout << endl;
}



UI::~UI() {
}

void UI::showMenu()
{
	int ok = 0;
	string delim;
	choise_file(ok);
	if (ok == 1) delim = " ";
	else delim=",";
	bool gata = false;


	cout << endl;
	cout << "  AUTENTIFICARE" << endl;
	int rez = login();
	cout << endl;
	if (rez !=-1) {
		while (!gata) {
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, FOREGROUND_BLUE);
			cout << "OPTIUNI:" << endl;
			cout << "  1. Adauga garnitura de marfa" << endl;
			cout << "  2. Update garnitura de marfa" << endl;
			cout << "  3. Sterge garnitura de marfa" << endl;
			cout << "  4. Afisati toate garniturile de marfa" << endl;
			cout << "       ............................................." << endl;
			cout << "  5. Adauga garnitura de persoane" << endl;
			cout << "  6. Update garnitura de persoane" << endl;
			cout << "  7. Sterge garnitura de persoane" << endl;
			cout << "  8. Afisati toate garniturile de persoane" << endl;
			cout << "       .............................................." << endl;
			cout << "  9. Afisati toate garniturile de marfa si de persoane" << endl;
			cout << "  0. Logout" << endl;
			int opt;
			cout << endl;
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
			cout << endl;
			cout << "Dati optiunea: " << endl;
			cin >> opt;
			switch (opt) {
			case 1: {adauga_garnitura_marfa_UI(); break; }
			case 2: {update_garnitura_marfa_UI(); break; }
			case 3: {delete_garnitura_marfa_UI(); break; }
			//case 4: {get_all_garnituri_marfa_UI(); break; }
			case 5: {adauga_garnitura_persoane_UI(); break; }
			case 6: {update_garnitura_persoane_UI(); break; }
			case 7: {delete_garnitura_persoane_UI(); break; }
			//case 8: {get_all_garnituri_persoane_UI(); break; }
			case 9: {get_all_garnituri_UI(delim); break; }
			case 0: {logout(); gata = true; }
			}

		}
	}
	else
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Autentificare esuata!" << endl;
		cout << "Incercati din nou!" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
	}
		
	}
	


