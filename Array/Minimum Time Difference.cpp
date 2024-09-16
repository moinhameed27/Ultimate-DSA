// Leetcode : https://leetcode.com/problems/minimum-time-difference/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> minutes(n); // For conversion of time to minutes
        string hour, mins;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            hour = timePoints[i].substr(0, 2);
            mins = timePoints[i].substr(3);
            // total minutes = hours * 60 + minutes
            minutes[i] = stoi(hour) * 60 + stoi(mins);
        }

        sort(minutes.begin(), minutes.end());   

        // Find the minimum difference between two consecutive minutes
        for (int i = 1; i < n; i++)
            ans = min(ans, minutes[i] - minutes[i - 1]);

        // Check the difference between the last and the first minute (for the circular nature of the clock)
        ans = min(ans, 1440 - minutes[n - 1] + minutes[0]);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution 
{
    public int findMinDifference(List<String> timePoints) 
    {
        int n = timePoints.size();
        int[] minutes = new int[n]; // For conversion of time to minutes
        String hour, mins;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) 
        {
            hour = timePoints.get(i).substring(0, 2);
            mins = timePoints.get(i).substring(3);
            // total minutes = hours * 60 + minutes
            minutes[i] = Integer.parseInt(hour) * 60 + Integer.parseInt(mins);
        }

        Arrays.sort(minutes);

        // Find the minimum difference between two consecutive minutes
        for (int i = 1; i < n; i++)
            ans = Math.min(ans, minutes[i] - minutes[i - 1]);

        // Check the difference between the last and the first minute (for the circular nature of the clock)
        ans = Math.min(ans, 1440 - minutes[n - 1] + minutes[0]);
        return ans;
    }
}