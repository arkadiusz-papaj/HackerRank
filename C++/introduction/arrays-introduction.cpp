#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int* arr;
    int n = 0;
    cin >> n;
    arr = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = n; i>0; i--)
    {
        cout << arr[i-1] <<" ";
    }
    
    delete [] arr;   
    return 0;
}