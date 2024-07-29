// Divide and Merge
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(v[i] <= v[j])
            temp.push_back(v[i++]);
        else
            temp.push_back(v[j++]);
    }

    // If any elements remain in the left side
    while(i <= mid)
            temp.push_back(v[i++]);

    // If any elements remain in the right side
    while(j <= high)
            temp.push_back(v[j++]);

    // Store the elements in original array [Remember, k - low is important, because low will not always be 0]
    for(int k = low; k <= high; k++)
        v[k] = temp[k - low];
}

void Merge_Sort(vector<int> &v, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    // Divide the left side [0 - mid]
    Merge_Sort(v, low, mid);
    // Divide the right side [(mid + 1) - n]
    Merge_Sort(v, mid + 1, high);
    // Merge the divided sides with respect to increasing order
    Merge(v, low, mid, high);
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    Merge_Sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}

/*
Time Complexity:
Best Case = Worst Case = Average Case = O(nlog(n))
Space Complexity = O(n)
*/