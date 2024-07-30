// LeetCode : https://leetcode.com/problems/count-number-of-teams/description/

// Way - I (Brute Force)
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int teams = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
                        rating[i] > rating[j] && rating[j] > rating[k])
                        teams++;
                }
            }
        }
        return teams;
    }
};

// Way - II (Better [Counting Left and Right])
/* 
1. Take the middle element as j.
2. Count the number of elements smaller than j on the left side and the number of elements larger than j on the left side.
3. Count the number of elements smaller than j on the right side and the number of elements larger than j on the right side.
4. The number of teams will be product of countSmallerLeft * countLargerRight + countLargerLeft * countSmallerRight.
*/
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size(), ans = 0;

        for (int j = 1; j < n - 1; j++)
        {
            int countSmallerLeft = 0, countLargerLeft = 0;
            int countSmallerRight = 0, countLargerRight = 0;

            for (int i = 0; i < j; i++)
            {
                if (rating[i] < rating[j])
                    countSmallerLeft++;
                else if (rating[i] > rating[j])
                    countLargerLeft++;
            }

            for (int k = j + 1; k < n; k++)
            {
                if (rating[k] < rating[j])
                    countSmallerRight++;
                else if (rating[k] > rating[j])
                    countLargerRight++;
            }

            ans += (countSmallerLeft * countLargerRight) + (countLargerLeft * countSmallerRight);
        }
        return ans;
    }
};