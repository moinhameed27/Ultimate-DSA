// Leetcode : https://leetcode.com/problems/reverse-words-in-a-string/description/

// GFG : https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

// ************************************************************{Leetcode}************************************************************
// [C++]------------------------------------------------------------------------------------------------------------------------
// Way - I (String Stream)
/* String stream stores tokens on the basis of spaces */
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string token = "", ans = "";
        while (ss >> token)
            ans = token + " " + ans;
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};

// Way - II (Two Pointers) : O(n) time and O(n) space
/* Reverse every word beginning from the start, add it to answer and reverse the final answer */
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        string ans = "", temp = "";
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        while (i < n)
        {
            char ch = s[i];
            if (ch == ' ')
            {
                if (!temp.empty())
                {
                    reverse(temp.begin(), temp.end());
                    ans += temp + " ";
                    temp = "";
                }
                // Skip spaces in between words
                while (i < n && s[i] == ' ')
                    i++;
            }
            // If not space (alphanumeric character), add to temp
            else
            {
                temp += ch;
                i++;
            }
        }

        // At the end of the string, if temp is not empty, add it to ans
        if (!temp.empty())
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        // Remove trailing space
        if (ans.back() == ' ')
            ans.pop_back();
        // Reverse the final answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Way - III (Two Pointers) : O(n) time and O(1) space
/* Reverse the entire string, reverse each word and remove extra spaces */
class Solution
{
public:
    string reverseWords(string s)
    {
        // Reverse the string
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0, right = 0, i = 0;

        while (i < n)
        {
            // Keep moving with the alphanumeric characters
            while (i < n && s[i] != ' ')
                s[right++] = s[i++];

            // Reverse the word
            if (left < right)
            {
                reverse(s.begin() + left, s.begin() + right);
                s[right++] = ' ';
                left = right;
            }
            i++;
        }
        // Remove trailing space and unnecessary characters
        s = s.substr(0, right - 1);
        return s;
    }
};

// [Java]------------------------------------------------------------------------------------------------------------------------
// Way - I (Tokenizer)
/* Tokenize the string on the basis of spaces */
class Solution
{
    public String reverseWords(String s)
    {
        String[] words = s.split(" ");
        StringBuilder ans = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--)
        {
            if (!words[i].isEmpty())
                ans.append(words[i]).append(" ");
        }
        return ans.toString().trim();
    }
}

// Way - II (Two Pointers) : O(n) time and O(n) space
/* Reverse every word beginning from the start, add it to answer and reverse the final answer */
class Solution
{
    public String reverseWords(String s)
    {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        int i = 0;

        // Skip leading spaces
        while (i < n && s.charAt(i) == ' ')
            i++;

        while (i < n)
        {
            char ch = s.charAt(i);
            if (ch == ' ')
            {
                if (temp.length() > 0)
                {
                    ans.append(temp.reverse().toString()).append(" ");
                    temp.setLength(0);
                }
                // Skip spaces in between words
                while (i < n && s.charAt(i) == ' ')
                    i++;
            }
            // If not space (alphanumeric character), add to temp
            else
            {
                temp.append(ch);
                i++;
            }
        }

        // At the end of the string, if temp is not empty, add it to ans
        if (temp.length() > 0)
            ans.append(temp.reverse().toString());

        // Remove trailing space
        if (ans.length() > 0 && ans.charAt(ans.length() - 1) == ' ')
            ans.setLength(ans.length() - 1);

        // Reverse the final answer
        ans.reverse();
        return ans.toString();
    }
}

// Way - III (Two Pointers) : O(n) time and O(1) space
/* Reverse the entire string, reverse each word and remove extra spaces */
class Solution
{
    public String reverseWords(String s)
    {
        char[] arr = s.toCharArray();
        int n = arr.length;

        // Reverse the string
        reverse(arr, 0, n - 1);

        int left = 0, right = 0, i = 0;

        while (i < n)
        {
            // Keep moving with the alphanumeric characters
            while (i < n && arr[i] != ' ')
                arr[right++] = arr[i++];

            // Reverse the word
            if (left < right)
            {
                reverse(arr, left, right - 1);
                if (right < n)
                {
                    arr[right++] = ' ';
                }
                left = right;
            }
            i++;
        }
        // Remove trailing space and unnecessary characters
        if (right > 0 && arr[right - 1] == ' ')
            right--;

        return new String(arr, 0, right);
    }

    private void reverse(char[] arr, int left, int right)
    {
        while (left < right)
        {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}


// ************************************************************{GFG}************************************************************
// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (String Stream)
/* String stream stores tokens on the basis of dots */
class Solution 
{
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) 
    {
        stringstream ss(str);
        string token, ans;
        while(getline(ss, token, '.'))
            ans = token + "." + ans;
        
        ans = ans.substr(0, ans.size() - 1);
        
        return ans;
    }
};

// Way - II (Two Pointers) : O(n) time and O(n) space
/* Reverse every word beginning from the start, add it to answer and reverse the final answer */
class Solution 
{
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) 
    {
        int n = str.size();
        string ans = "", temp = "";
        int i = 0;
        
        // Skip leading spaces
        while(i < n && str[i] == '.')
            i++;
        
        while(i < n)
        {
            char ch = str[i];
            if(ch == '.')
            {
                if(!temp.empty())
                {
                    reverse(temp.begin(), temp.end());
                    ans += temp + ".";
                    temp = "";
                }
                // Skip spaces in between words
                while(i < n && str[i] == '.')
                    i++;
            }
            // If not space (alphanumeric character), add to temp
            else
            {
                temp += ch;
                i++;
            }
        }
        
        // At the end of the string, if temp is not empty, add it to ans
        if(!temp.empty())
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        // Remove trailing space
        if(ans.back() == '.')
            ans.pop_back();
        // Reverse the final answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Way - III (Two Pointers) : O(n) time and O(1) space
/* Reverse the entire string, reverse each word and remove extra spaces */
class Solution 
{
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) 
    {
        // Reverse the string
        reverse(str.begin(), str.end());
        int n = str.size();
        int left = 0, right = 0, i = 0;
        
        while(i < n)
        {
            // Keep moving with the alphanumeric characters
            while(i < n && str[i] != '.')
                str[right++] = str[i++];
            
            // Reverse the word
            if(left < right)
            {
                reverse(str.begin() + left, str.begin() + right);
                str[right++] = '.';
                left = right;
            }
            i++;
        }
        // Remove trailing space and unnecessary characters
        str = str.substr(0, right - 1);
        return str;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Tokenizer)
/* Tokenize the string on the basis of dots */
class Solution 
{
    String reverseWords(String str)
    {
        String[] words = str.split("\\.");
        StringBuilder ans = new StringBuilder();
        for(int i = words.length - 1; i >= 0; i--)
        {
            if(!words[i].isEmpty())
                ans.append(words[i]).append(".");
        }
        return ans.toString().trim();
    }
}

// Way - II (Two Pointers) : O(n) time and O(n) space
/* Reverse every word beginning from the start, add it to answer and reverse the final answer */
class Solution 
{
    String reverseWords(String str)
    {
        int n = str.length();
        StringBuilder ans = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        int i = 0;
        
        // Skip leading spaces
        while(i < n && str.charAt(i) == '.')
            i++;
        
        while(i < n)
        {
            char ch = str.charAt(i);
            if(ch == '.')
            {
                if(temp.length() > 0)
                {
                    ans.append(temp.reverse().toString()).append(".");
                    temp.setLength(0);
                }
                // Skip spaces in between words
                while(i < n && str.charAt(i) == '.')
                    i++;
            }
            // If not space (alphanumeric character), add to temp
            else
            {
                temp.append(ch);
                i++;
            }
        }
        
        // At the end of the string, if temp is not empty, add it to ans
        if(temp.length() > 0)
            ans.append(temp.reverse().toString());
        
        // Remove trailing space
        if(ans.length() > 0 && ans.charAt(ans.length() - 1) == '.')
            ans.setLength(ans.length() - 1);
        
        // Reverse the final answer
        ans.reverse();
        return ans.toString();
    }
}

// Way - III (Two Pointers) : O(n) time and O(1) space
/* Reverse the entire string, reverse each word and remove extra spaces */
class Solution 
{
    String reverseWords(String str)
    {
        char[] arr = str.toCharArray();
        int n = arr.length;
        
        // Reverse the string
        reverse(arr, 0, n - 1);
        
        int left = 0, right = 0, i = 0;
        
        while(i < n)
        {
            // Keep moving with the alphanumeric characters
            while(i < n && arr[i] != '.')
                arr[right++] = arr[i++];
            
            // Reverse the word
            if(left < right)
            {
                reverse(arr, left, right - 1);
                if(right < n)
                {
                    arr[right++] = '.';
                }
                left = right;
            }
            i++;
        }
        // Remove trailing space and unnecessary characters
        if(right > 0 && arr[right - 1] == '.')
            right--;
        
        return new String(arr, 0, right);
    }
    
    private void reverse(char[] arr, int left, int right)
    {
        while(left < right)
        {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}