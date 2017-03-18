#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void print_vector(vector<int> &vect) {
    vector<int>::iterator v_iter = vect.begin();
    while (v_iter != vect.end()) {
	cout << "Value of v_iter:" << *v_iter << endl;
	v_iter++;
    }
}

int main() {
    int i;
    vector<int> vect;

    cout << "Initial vect size:" << vect.size() << endl;

    vect.push_back(23);
    vect.push_back(76);
    vect.push_back(11);
    vect.push_back(83);
    vect.push_back(5);
    vect.push_back(17);
    vect.push_back(-456);
    vect.push_back(892);
    vect.push_back(64);
    vect.push_back(-5);

    cout << "Loaded vect size:" << vect.size() << endl;
    print_vector(vect);

    sort(vect.begin(), vect.end());

    cout << "Sorted:" << endl;
    print_vector(vect);

    return 0;
}

