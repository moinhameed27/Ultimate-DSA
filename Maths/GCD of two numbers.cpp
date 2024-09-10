// GFG : https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Inbuilt function)
class Solution
{
public:
    int gcd(int a, int b)
    {
        return __gcd(a, b);
    }
};

// Way - II (Simple Method)
class Solution
{
public:
    int gcd(int a, int b)
    {
        int ans = min(a, b);
        while (ans)
        {
            if (a % ans == 0 && b % ans == 0)
                break;
            ans--;
        }
        return ans;
    }
};

// Way - III (Euclidean Algorithm)
class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Inbuilt function)
class Solution 
{
    public int gcd(int a, int b) 
    {
        return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
    }
}

// Way - II (Simple Method)
class Solution
{
    public int gcd(int a, int b)
    {
        int ans = Math.min(a, b);
        while (ans > 0)
        {
            if (a % ans == 0 && b % ans == 0)
                break;
            ans--;
        }
        return ans;
    }
}

// Way - III (Euclidean Algorithm)
class Solution
{
    public int gcd(int a, int b)
    {
        while (b > 0)
        {
            a = a % b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }
}
