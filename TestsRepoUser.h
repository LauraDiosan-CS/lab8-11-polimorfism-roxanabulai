#pragma once
#include "RepoUser.h"

class TestRepoUser {
private:

    vector<User*> useri;

    void testAddUser();
    void testUpdateUser();
    void testDeleteUser();

public:
    TestRepoUser();
    ~TestRepoUser();
    void testAll();
};