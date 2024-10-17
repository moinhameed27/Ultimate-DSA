// Leetcode : https://leetcode.com/problems/maximum-swap/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution
{
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        int n = str.size();

        for (int i = 0; i < n - 1; i++)
        {
            int maxi = i;
            // Check for the maximum digit from the right side of the current digit
            for (int j = i + 1; j < n; j++)
            {
                if (str[j] >= str[maxi])
                    maxi = j;
            }

            // If the maximum digit is not the same as the current digit, then swap them and return the number
            if (str[maxi] != str[i])
            {
                swap(str[i], str[maxi]);
                break;
            }
        }

        return stoi(str);
    }
};

// Way - II (Preprocessing [Storing Right Max])
class Solution
{
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        int n = str.size();

        // Store the right maximum element and its index for each element
        vector<int> rightMax(n, -1);
        rightMax[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int rightMaxIdx = rightMax[i + 1];
            int rightMaxElement = str[rightMaxIdx];

            rightMax[i] = str[i] > rightMaxElement ? i : rightMaxIdx;
        }

        // Check for the maximum digit from the right side of the current digit
        for (int i = 0; i < n; i++)
        {
            int rightMaxIdx = rightMax[i];
            int rightMaxElement = str[rightMaxIdx];

            if (rightMaxElement > str[i])
            {
                swap(str[i], str[rightMaxIdx]);
                return stoi(str);
            }
        }
        return num;
    }
};

// Way - III (Optimized)
class Solution
{
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        int n = str.size();

        // Storing the Element along with it's latest index
        vector<int> rightMax(10, -1);
        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - '0';
            rightMax[idx] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int currDigit = str[i] - '0';
            // Check for the maximum digit from the right side of the current digit, if found swap and then return
            for (int digit = 9; digit > currDigit; digit--)
            {
                if (rightMax[digit] > i)
                {
                    swap(str[i], str[rightMax[digit]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force)
class Solution 
{
    public int maximumSwap(int num) 
    {
        char[] str = Integer.toString(num).toCharArray();
        int n = str.length;
        
        for(int i = 0; i < n - 1; i++)
        {
            int maxi = i;
            // Check for the maximum digit from the right side of the current digit
            for(int j = i + 1; j < n; j++)
            {
                if(str[j] >= str[maxi])
                    maxi = j;
            }
            
            // If the maximum digit is not the same as the current digit, then swap them and return the number
            if(str[maxi] != str[i])
            {
                char temp = str[i];
                str[i] = str[maxi];
                str[maxi] = temp;
                break;
            }
        }
        
        return Integer.parseInt(new String(str));
    }
}

// Way - II (Preprocessing [Storing Right Max])
class Solution 
{
    public int maximumSwap(int num) 
    {
        char[] str = Integer.toString(num).toCharArray();
        int n = str.length;
        
        // Store the right maximum element and its index for each element
        int[] rightMax = new int[n];
        rightMax[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--)
        {
            int rightMaxIdx = rightMax[i + 1];
            int rightMaxElement = str[rightMaxIdx];
            
            rightMax[i] = str[i] > rightMaxElement ? i : rightMaxIdx;
        }
        
        // Check for the maximum digit from the right side of the current digit
        for(int i = 0; i < n; i++)
        {
            int rightMaxIdx = rightMax[i];
            int rightMaxElement = str[rightMaxIdx];
            
            if(rightMaxElement > str[i])
            {
                char temp = str[i];
                str[i] = str[rightMaxIdx];
                str[rightMaxIdx] = temp;
                return Integer.parseInt(new String(str));
            }
        }
        return num;
    }
}

// Way - III (Optimized)
class Solution 
{
    public int maximumSwap(int num) 
    {
        char[] str = Integer.toString(num).toCharArray();
        int n = str.length;
        
        // Storing the Element along with it's latest index
        int[] rightMax = new int[10];
        Arrays.fill(rightMax, -1);
        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - '0';
            rightMax[idx] = i;
        }
        
        for(int i = 0; i < n; i++)
        {
            int currDigit = str[i] - '0';
            // Check for the maximum digit from the right side of the current digit, if found swap and then return
            for(int digit = 9; digit > currDigit; digit--)
            {
                if(rightMax[digit] > i)
                {
                    char temp = str[i];
                    str[i] = str[rightMax[digit]];
                    str[rightMax[digit]] = temp;
                    return Integer.parseInt(new String(str));
                }
            }
        }
        return num;
    }
}