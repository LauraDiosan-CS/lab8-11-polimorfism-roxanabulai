#include "RepoUser.h"
#include <vector>
#include <algorithm>
RepoUser::RepoUser()
{
}

vector<User*> RepoUser::getAll()
{

	return this->useri;
}

int RepoUser::getSize()
{
	return this->useri.size();
}

int RepoUser::find(User* user)
{
	//auto it = std::find(useri.begin(), useri.end(), user);
	//if (it != useri.end()) 
		//	return distance(useri.begin(), it); //daca il gaseste
	//return -1; //daca nu il gaseste

	int k = this->useri.size();
	for (int i = 0; i < k; i++)
	{
		if (*(this->getUser(i)) == *user)
			return 0; //0 daca il gaseste
	}
	return -1; //-1 daca nu il gaseste
}

void RepoUser::addUser(User* user)
{
	this->useri.push_back(user->clone());
}

void RepoUser::updateUser(User* user_vechi, User* user_nou)
{
	//std::replace(useri.begin(), useri.end(), user_vechi, user_nou);

	int k = this->useri.size();
	for (int i = 0; i < k; i++)
	{
		if (*(this->getUser(i)) == *user_vechi)
		{
			delete this->useri[i];
			this->useri[i] = user_nou->clone();
			return;
		}
	}
}

void RepoUser::deleteUser(User* user)
{
	/*auto last = std::remove(useri.begin(), useri.end(), user);
	if (last != useri.end()) {
		useri.erase(last, useri.end());
		return 0;
	}
	return -1;*/
	int k = this->useri.size();
	for (int i = 0; i < k; i++)
	{
		if (**(this->useri.begin() + i) == *user)
		{
			delete this->useri[i];
			this->useri.erase(this->useri.begin() + i);
			return;
		}
	}
}


User* RepoUser::getUser(int pos) {

	if (pos >= 0 && pos < this->getSize())
	{
		return this->useri[pos]->clone();
	}
	return new User();

}
RepoUser::~RepoUser() {

}