#pragma once
#include <vector>
#include "CompanieFeroviara.h"
class TestsService {
private:
   
    void testLogin();
    void testGetAllTXT();
    void testGetAllCSV();
    void testAddTrenTXT();
    void testAddTrenCSV();
    void testUpdateTrenTXT();
    void testUpdateTrenCSV();
    void testDeleteTrenCSV();
    void testDeleteTrenTXT();

public:


    TestsService();
    ~TestsService();
    void testAll();
};