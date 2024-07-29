// Select the minimum and swap [Push minimum to the start]
#include <iostream>
#include <vector>
using namespace std;

void Selection_Sort(vector<int> &v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[mini])
                mini = j;
        }
        swap(v[i], v[mini]);
    }
}

int main()
{
    vector<int> v = {2, 3, 1, 4, 5};
    int n = v.size();
    Selection_Sort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}

/*
Time Complexity:
Best Case = Worst Case = Average Case = O(n2) [n(n + 1) / 2]
*/