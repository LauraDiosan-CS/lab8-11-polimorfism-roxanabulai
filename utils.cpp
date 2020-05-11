#pragma once
#include "utils.h"
#include <string>
using namespace std;
int number(string str)
{//12S3
    int ok = 1;
    for (int i = 0; i < (str.length() - 1); i++) {
        ok = 0;
        if ((int)str[i] < 10)
        {
            ok = 1;
        }
        
        if (ok == 0) 
            return ok;
    }
    return 1;
}