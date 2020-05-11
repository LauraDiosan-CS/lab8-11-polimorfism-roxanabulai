#pragma once
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"

class TestRepoFile {
private:
    const string fileNameInTXT = "TestTrenuriIn.txt";
    const string fileNameOutTXT = "TestTrenuriOut.txt";
    const string fileNameInCSV = "TestTrenuriIn.csv";
    const string fileNameOutCSV = "TestTrenuriOut.csv";

    //folosit pt. a testa lucrul cu fisiere
    vector<CompanieFeroviara*> trenuriIn;

    void testGetSize();
    void testGetAll();
    void testGetCompanieFeroviara();
    void testAddCompanieFeroviara();
    void testUpdateCompanieFeroviara();
    void testDeleteCompanieFeroviara();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();
    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
    void teste_live();
};