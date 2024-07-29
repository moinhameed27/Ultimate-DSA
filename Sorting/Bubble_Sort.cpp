// Select the maximum and swap [Push maximum to the end by adjacent swaps]
#include <iostream>
#include <vector>
using namespace std;

void Bubble_Sort(vector<int> &v, int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        bool didSwap = false;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]), didSwap = true;
        }
        // If array is already sorted, break
        if (!didSwap)
            break;
    }
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    Bubble_Sort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}

/*
Time Complexity:
Best Case = O(n) [Array is already Sorted]
Worst Case = Average Case = O(n2) [n(n + 1) / 2]
*/