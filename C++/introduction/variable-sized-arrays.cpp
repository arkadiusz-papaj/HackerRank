#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int noOfTables;
    int noOfQuerries;
    int** tables = nullptr;
    
    cin >> noOfTables >> noOfQuerries;
    tables = new int* [noOfTables];
    
    for(int i = 0; i < noOfTables; i++)
    {
        int size;
        cin >> size;
        tables[i] = new int[size];
        
        for(int j = 0; j < size; j++)
        {
            cin >> tables[i][j];
        }
    }
    
    int* tableOfQuarries = new int[noOfQuerries*2];
    for(int i = 0; i < noOfQuerries; i++)
    {
        cin >> tableOfQuarries[i*2] >> tableOfQuarries[(i*2)+1];
    }
    
    for(int i = 0; i < noOfQuerries; i++)
    {
        cout <<tables[tableOfQuarries[i*2]][tableOfQuarries[(i*2)+1]] << endl;
    }
    delete [] tableOfQuarries;
    
    for(int i = 0; i < noOfTables; i++) delete [] tables[noOfTables];
    delete [] tables;
    
    return 0;
}