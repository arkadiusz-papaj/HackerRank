#include <iostream>
#include <string>
using namespace std;

int main() {
	string a("");
    string b("");
    
    cin >> a;
    cin >> b;
    
    cout << a.length() << " " << b.length() <<endl;
    cout << a+b <<endl;
    std::swap(a.at(0), b.at(0));
    cout << a << " " << b <<endl;
  
    return 0;
}