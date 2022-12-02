#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    int tmp;
    vector<int> v;
    
    while(!ss.eof())
    {
        if (std::isspace(ss.peek())) ss >> std::ws;
        else if (ss.peek() == ',') ss.ignore();
        else
        {
            ss >> tmp;
            v.push_back(tmp);
        }
    }
    
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}