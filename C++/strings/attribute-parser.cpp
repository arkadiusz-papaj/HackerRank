#include <iostream>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // Ignore newline after numbers

    map<string, string> attributes;
    stack<string> tagStack;
    
    // Read HRML input
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        ss >> word;

        if (word[1] == '/') { 
            // Closing tag (e.g., </tag1>)
            tagStack.pop();
        } else { 
            // Opening tag (e.g., <tag1 name="value">)
            word = word.substr(1); // Remove '<'
            if (word.back() == '>') word.pop_back(); // Remove '>'
            
            string currentTag = tagStack.empty() ? word : tagStack.top() + "." + word;
            tagStack.push(currentTag);

            string attr, eq, value;
            while (ss >> attr >> eq >> value) {
                if (value.back() == '>') value.pop_back(); // Remove '>'
                value = value.substr(1, value.length() - 2); // Remove quotes
                attributes[currentTag + "~" + attr] = value;
            }
        }
    }

    // Process Queries
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        
        if (attributes.find(query) != attributes.end()) {
            cout << attributes[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}