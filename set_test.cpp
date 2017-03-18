#include <set>
#include <iostream>


using namespace std;

int main() {
    set<string> s;

    cout << "Initial set size:" << s.size() << endl;

    s.insert("Land Cruiser");
    s.insert("Miata");
    s.insert("Tacoma");
    s.insert("S2000");
    s.insert("4Runner");

    cout << "Loaded set size:" << s.size() << endl;

    set<string>::iterator s_iter = s.begin();
    while(s_iter != s.end()) {
	cout << "s_iter value:" << *s_iter << endl;
	s_iter++;
    }


    if (s.find("Diablo") != s.end())
	cout << "Found Diablo in the set" << endl;
    else
	cout << "Did not find Diablo in the set" << endl;
	
    if (s.find("Miata") != s.end())
	cout << "Found Miata in the set" << endl;
    else
	cout << "Did not find Miata in the set" << endl;


    return 0;
}
