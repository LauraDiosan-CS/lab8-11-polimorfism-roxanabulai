#include "TestsRepoUser.h"
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;
void TestRepoUser::testAll() {
	this->testAddUser();
	this->testDeleteUser();
	this->testUpdateUser();
}

void TestRepoUser::testAddUser()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("Alex", "12abc");
	User* u2 = new User("Alina", "134cd");
	repo->addUser(u1);
	repo->addUser(u2);
	assert(repo->getSize() == 2);
	assert(repo->find(u1) ==0);
	repo->deleteUser(u2);
	assert(repo->find(u2) == -1);
	assert(*repo->getUser(0) == *u1->clone());

}

void TestRepoUser::testUpdateUser()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("Alex", "12abc");
	User* u2 = new User("Alina", "134cd");
	repo->addUser(u1);
	assert(*repo->getUser(0) == *u1->clone());
	repo->updateUser(u1, u2);
	assert(*repo->getUser(0) == *u2->clone());

}

void TestRepoUser::testDeleteUser()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("Alex", "12abc");
	repo->addUser(u1);
	assert(repo->getSize() == 1);
	repo->deleteUser(u1);
	assert(repo->getSize() == 0);

}

TestRepoUser::TestRepoUser()
{
	User* u1 = new User("Ana", "11abc");
	User* u2 = new User("Bianca", "12acd");
	this->useri.push_back(u1);
	this->useri.push_back(u2);
}

TestRepoUser::~TestRepoUser()
{
}
