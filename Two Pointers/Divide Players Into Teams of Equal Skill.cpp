// Leetcode : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Sorting + Two Pointer) : O(nlogn) time and O(1) space
/* Making pairs of highest and lowest skill elements. */
class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        int i = 0, j = n - 1;
        int team = skill[i] + skill[j];
        long long chemistry = 0;
        while (i < j)
        {
            int currTeam = skill[i] + skill[j];
            // If the sum of skills of two players is not equal, return -1
            if (currTeam != team)
                return -1;

            chemistry += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        return chemistry;
    }
};

// Way - II (Frequency Count of Skills) : O(n) time and O(1000) space
class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        long long sum = 0;
        vector<int> skillFreq(1001, 0);

        // Calculating sum of all skills and frequency of each skill
        for (int num : skill)
        {
            sum += num;
            skillFreq[num]++;
        }

        int teams = n / 2;  // Number of teams
        // If sum of all skills is not divisible by number of teams, return -1
        if (sum % teams != 0)
            return -1;
        int target = sum / teams;   // Target sum of skills for each team
        long long chemistry = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = skill[i];
            int rem = target - curr;
            if (skillFreq[rem] == 0)
                return -1;
            chemistry += (long long)(curr) * (long long)(rem);
            skillFreq[rem]--;
        }
        // As we have counted chemistry twice, divide it by 2
        return chemistry / 2;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Sorting + Two Pointer) : O(nlogn) time and O(1) space
class Solution 
{
    public long dividePlayers(int[] skill) 
    {
        int n = skill.length;
        Arrays.sort(skill);
        
        int i = 0, j = n - 1;
        int team = skill[i] + skill[j];
        long chemistry = 0;
        while(i < j) 
        {
            int currTeam = skill[i] + skill[j];
            // If the sum of skills of two players is not equal, return -1
            if(currTeam != team) return -1;
            
            chemistry += (long)(skill[i]) * (long)(skill[j]);
            i++;
            j--;
        }
        return chemistry;
    }
}

// Way - II (Frequency Count of Skills) : O(n) time and O(1000) space
class Solution 
{
    public long dividePlayers(int[] skill) 
    {
        int n = skill.length;
        long sum = 0;
        int[] skillFreq = new int[1001];
        
        // Calculating sum of all skills and frequency of each skill
        for(int num : skill) 
        {
            sum += num;
            skillFreq[num]++;
        }
        
        int teams = n / 2;  // Number of teams
        // If sum of all skills is not divisible by number of teams, return -1
        if(sum % teams != 0) return -1;
        int target = (int)(sum / teams);   // Target sum of skills for each team
        long chemistry = 0;
        
        for(int i = 0; i < n; i++) 
        {
            int curr = skill[i];
            int rem = target - curr;
            if(skillFreq[rem] == 0) return -1;
            chemistry += (long)(curr) * (long)(rem);
            skillFreq[rem]--;
        }
        // As we have counted chemistry twice, divide it by 2
        return chemistry / 2;
    }
}