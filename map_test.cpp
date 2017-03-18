
#include <iostream>
#include <map>

using namespace std;

void print_map(map<string, int> m) {
    map<string, int>::iterator m_iter = m.begin();
    while(m_iter != m.end()) {
	cout << "m_iter key:" << m_iter->first << " value:" << m_iter->second << endl;
	m_iter++;
    } 
}


int main() {
    map<string, int> m;

    cout << "Initial map size:" << m.size() << endl;

    m["Tacos"] = 44;
    m["Nachos"] = 95;
    m["Burritos"] = -3;
    m["Steak"] = 32;
    m["Chips"] = 15;
    m["Fajitas"] = -2321;
    m["Sushi"] = 98;
    m["Sandwich"] = 0;
    m["Chocolate"] = 453;
    m["Cake"] = 8;
    m["Cookies"] = -1;
    m["Salad"] = 2;
    m["Almonds"] = 123;
    m["Oatmeal"] = -23;
    m["Bread"] = -45;

    cout << "Loaded map size:" << m.size() << endl;
    print_map(m);


//    cout << "Sorted:";
//    print_map(m);
}
