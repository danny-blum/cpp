#include <queue>
#include <iostream>

using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty()) {
	cout << "Queue pop:" << q.front() << endl;
	q.pop();
    }

    return 0;
}
