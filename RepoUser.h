#pragma once
#include "User.h"
#include <vector>

class RepoUser {
private:
	vector<User*> useri;
public:
	RepoUser(); //constructor implicit

	vector<User*> getAll();

	int getSize();
	int find(User*);

	void addUser(User*);
	void updateUser(User*, User*);
	void deleteUser(User*);

	User* getUser(int);

	~RepoUser();
};

