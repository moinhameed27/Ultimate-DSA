/*
Divide and Conquer
1. Pick a pivot[Any element in the array] and place it in it's correct order.
2. Put smaller elements on the left of pivot and larger on the right.
*/
#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &v, int low, int high)
{
    int i = low, j = high;
    // Pivot can be the starting element of ongoing array
    int pivot = v[low];
    while (i < j)
    {
        // Keep going until an element comes which is greater than pivot
        while (v[i] <= pivot && i <= high)
            i++;
        // Keep going until an element comes which is smaller than pivot
        while (v[j] > pivot && i >= low)
            j--;
        // If elements has not crossed each other, swap their values
        if (i < j)
            swap(v[i], v[j]);
    }
    // At the end of loop, j will be correct place for the pivot and when the loop will end, pivot will be at the correct place and 
    // it will have the smaller elements on the left side and greater elements on the right side
    swap(v[low], v[j]);
    return j;
}

void Quick_Sort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    // Pick a pivot and place it in it's correct order
    int partitionIndex = Partition(v, low, high);
    // Apply Quick sort on the left side of pivot
    Quick_Sort(v, low, partitionIndex - 1);
    // Apply Quick sort on the right side of pivot
    Quick_Sort(v, partitionIndex + 1, high);
}

int main()
{
    vector<int> v = {5, 4, 3, 3, 2, 4, 1, 5, 1};
    int n = v.size();
    Quick_Sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}

/*
Time Complexity:
Best Case = Worst Case = Average Case = O(nlog(n))
Space Complexity = O(1)
*/