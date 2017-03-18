#include <list>
#include <iostream>

using namespace std;


void print_list(list<int> &l) {
    list<int>::iterator l_iter = l.begin();
    while (l_iter != l.end()) {
	cout << "Value of l_iter:" << *l_iter << endl;
	l_iter++;
    }
}


int main() {

    list<int> l;

    cout << "Initial list size:" << l.size() <<endl;

    l.push_front(4);
    l.push_front(2);
    l.push_front(9);
    l.push_front(-23);
    l.push_front(87);

    l.push_back(6);
    l.push_back(-54);
    l.push_back(32);
    l.push_back(68);
    l.push_back(-3);
    l.push_back(-91);

    cout << "loaded list size:" << l.size() <<endl;

    print_list(l);

    l.sort();

    cout << "sorted list:" << endl;

    print_list(l);

    return 0;
}
