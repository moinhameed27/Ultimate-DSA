// GFG : https://www.geeksforgeeks.org/problems/square-root/1

// C++----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-In)
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long int ans = sqrt(x);
        return ans;
    }
};

// Way - II (Linear Search)
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long ans = 0;
        for (long long int i = 0; i <= x; i++)
        {
            if (i * i <= x)
                ans = i;
            else
                break;
        }
        return ans;
    }
};

// Way - III (Binary Search)
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long int left = 0, mid, right = x, ans = 0;
        while (left <= right)
        {
            // Find the middle of the range
            mid = left + (right - left) / 2;
            // If square of middle is <= given number, store it and terminate the left side
            if (mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            // Otherwise terminate the right side
            else
                right = mid - 1;
        }
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
// Way - I (Built-In)
class Solution
{
    long floorSqrt(long x)
    {
        long ans = (long)Math.sqrt(x);
        return ans;
    }
}

// Way - II (Linear Search)
class Solution
{
    long floorSqrt(long x)
    {
        long ans = 0;
        for (long i = 0; i <= x; i++)
        {
            if (i * i <= x)
                ans = i;
            else
                break;
        }
        return ans;
    }
}

// Way - III (Binary Search)
class Solution
{
    long floorSqrt(long x)
    {
        long left = 0, mid, right = x, ans = 0;
        while (left <= right)
        {
            // Find the middle of the range
            mid = left + (right - left) / 2;
            // If square of middle is <= given number, store it and terminate the left side
            if (mid * mid <= x)
            {
                ans = mid;
                left = mid + 1;
            }
            // Otherwise terminate the right side
            else
                right = mid - 1;
        }
        return ans;
    }
}