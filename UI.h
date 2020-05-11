#pragma once
#include <string>
#include "Service.h"
#include "User.h"
using namespace std;

class UI
{
private:
	Service s;
	User u;
	int login();
	void choise_file(int& ok);
	void logout();
	//void choise_file();
	

	void adauga_garnitura_marfa_UI();
	void adauga_garnitura_persoane_UI();
	void update_garnitura_persoane_UI();
	void update_garnitura_marfa_UI();
	void get_all_garnituri_UI(string delim);
	void delete_garnitura_marfa_UI();
	void delete_garnitura_persoane_UI();
public:
	UI();

	UI(Service&);
	void showMenu();
	~UI();
	
};

