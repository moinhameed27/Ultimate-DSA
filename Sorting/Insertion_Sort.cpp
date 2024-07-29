// Take an element and insert it in it's correct order
#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
            swap(v[j - 1], v[j]), j--;
    }
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    Insertion_Sort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}

/*
Time Complexity:
Best Case = O(n) [Array is already Sorted]
Worst Case = Average Case = O(n2) [n(n + 1) / 2]
*/