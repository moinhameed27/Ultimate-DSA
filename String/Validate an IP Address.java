// LeetCode + GFG

// GFG : https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

// C++---------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int isValid(string str)
    {
        int n = str.size(), number = 0, dots = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '.')
            {
                // Consecutive dots
                if (str[i + 1] == '.')
                    return false;
                // Number out of range
                if (number < 0 || number > 255)
                    return false;
                dots++;
                number = 0; // Reset number
            }
            else
            {
                // Leading zero
                if (i == 0 && str[i] == '0')
                    return false;
                int num = str[i] - '0';
                number = number * 10 + num;
            }
        }
        // Number out of range or 3 dots not present
        if (number < 0 || number > 255 || dots != 3)
            return false;
        return true;
    }
};
// Java---------------------------------------------------------------------------------------------------------------------
public
boolean isValid(String str)
{
    int n = str.length(), number = 0, dots = 0;
    for (int i = 0; i < n; i++)
    {
        if (str.charAt(i) == '.')
        {
            // Consecutive dots
            if (str.charAt(i + 1) == '.')
                return false;
            // Number out of range
            if (number < 0 || number > 255)
                return false;
            dots++;
            number = 0; // Reset number
        }
        else
        {
            // Leading zero
            if (i == 0 && str.charAt(i) == '0')
                return false;
            int num = str.charAt(i) - '0';
            number = number * 10 + num;
        }
    }
    // Number out of range or 3 dots not present
    if (number < 0 || number > 255 || dots != 3)
        return false;
    return true;
}

// Leetcode : https://leetcode.com/problems/validate-ip-address/

// C++---------------------------------------------------------------------------------------------------------------------
class Solution
{
    int n;

    bool validZero(string queryIP, int i)
    {
        // If the first character is zero or the last character is zero
        if ((i == 0) || (queryIP[i - 1] == '.') && (i + 1 == n || queryIP[i + 1] == '.'))
            return true;
        return false;
    }

    bool validV6Char(char c)
    {
        // If the character is a digit or a valid hexadecimal character
        return isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    }

    string validateIPv4(string queryIP)
    {
        int segments = 0;
        int i = 0;

        while (i < n)
        {
            int segmentSize = 0;
            string segment = "";

            while (i < n && queryIP[i] != '.')
            {
                segmentSize++;
                // If the character is not a digit
                if (queryIP[i] < '0' || queryIP[i] > '9')
                    return "Neither";
                segment += queryIP[i];
                i++;
            }

            // If the last character is a dot
            if (queryIP[i] == '.' && i + 1 == n)
                return "Neither";

            // If the segment size is zero or greater than 3 or the segment starts with zero
            if (segmentSize == 0 || segmentSize > 3 || (segment[0] == '0' && segmentSize > 1))
                return "Neither";

            int value = stoi(segment);
            // If the segment value is out of range
            if (value < 0 || value > 255)
                return "Neither";

            segments++;
            i++;
        }

        // If the number of segments is 4
        if (segments == 4)
            return "IPv4";
        return "Neither";
    }

    string validateIPv6(string queryIP)
    {
        int segments = 0, segmentChars = 0;

        for (int i = 0; i < n; i++)
        {
            if (queryIP[i] == ':')
            {
                // If the first character is a colon or the last character is a colon or the next character is a colon or the segment size is zero or greater than 4
                if (i == 0 || i == n - 1 || queryIP[i + 1] == ':' || segmentChars == 0 || segmentChars > 4)
                    return "Neither";

                segments++;
                segmentChars = 0;
            }
            // If the character is not a valid hexadecimal character
            else if (!validV6Char(queryIP[i]))
                return "Neither";
            else
                segmentChars++;
        }

        // If the segment size is zero or greater than 4 or the number of segments is not 7
        if (segmentChars == 0 || segmentChars > 4 || segments != 7)
            return "Neither";

        return "IPv6";
    }

public:
    string validIPAddress(string queryIP)
    {
        n = queryIP.size();
        if (queryIP.find('.') != string::npos)
            return validateIPv4(queryIP);
        else if (queryIP.find(':') != string::npos)
            return validateIPv6(queryIP);
        return "Neither";
    }
};

// Java---------------------------------------------------------------------------------------------------------------------
public class Solution 
{

    private int n;

    private boolean validZero(String queryIP, int i) 
    {
        if (i == 0 || (queryIP.charAt(i - 1) == '.' && (i + 1 == n || queryIP.charAt(i + 1) == '.'))) {
            return true;
        }
        return false;
    }

    private boolean validV6Char(char c) 
    {
        return Character.isDigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    }

    private String validateIPv4(String queryIP) 
    {
        int segments = 0;
        int i = 0;

        while (i < n) {
            int segmentSize = 0;
            StringBuilder segment = new StringBuilder();

            while (i < n && queryIP.charAt(i) != '.') {
                segmentSize++;
                char c = queryIP.charAt(i);
                if (c < '0' || c > '9')
                    return "Neither";
                segment.append(c);
                i++;
            }

            if (i < n && queryIP.charAt(i) == '.' && i + 1 == n)
                return "Neither";

            if (segmentSize == 0 || segmentSize > 3 || (segment.charAt(0) == '0' && segmentSize > 1))
                return "Neither";

            int value = Integer.parseInt(segment.toString());

            if (value < 0 || value > 255)
                return "Neither";

            segments++;
            i++;
        }

        return segments == 4 ? "IPv4" : "Neither";
    }

    private String validateIPv6(String queryIP) 
    {
        int segments = 0;
        int segmentChars = 0;

        for (int i = 0; i < n; i++) 
        {
            char c = queryIP.charAt(i);

            if (c == ':') {
                if (i == 0 || i == n - 1 || (i < n - 1 && queryIP.charAt(i + 1) == ':') || segmentChars == 0
                        || segmentChars > 4)
                    return "Neither";
                segments++;
                segmentChars = 0;
            } else if (!validV6Char(c))
                return "Neither";
            else
                segmentChars++;
        }

        if (segmentChars == 0 || segmentChars > 4 || segments != 7)
            return "Neither";

        return "IPv6";
    }

    public String validIPAddress(String queryIP) 
    {
        n = queryIP.length();
        if (queryIP.indexOf('.') != -1)
            return validateIPv4(queryIP);
        else if (queryIP.indexOf(':') != -1)
            return validateIPv6(queryIP);
        return "Neither";
    }
}
