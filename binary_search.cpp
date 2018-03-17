#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &v, int n, int min, int max)
{
    int mid = (max - min)/2 + min;
    
    if (n == v[mid])
        return mid;
    if (n > v[mid])
    {
        if (mid == max)
            return -1;
        else
            return binary_search(v, n, mid+1, max);
    }
    else
    {
        if (mid == min)
            return -1;
        else
            return binary_search(v, n, min, mid-1);
    }
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9, 10, 14, 17, 21, 43, 56, 67, 87, 98, 123, 126, 456, 4567};
    
    int pos = binary_search(v, 14, 0, v.size()-1);

    cout << pos << endl;
    
    return 0;
}
