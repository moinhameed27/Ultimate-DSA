// Leetcode : https://leetcode.com/problems/combination-sum/

// C++----------------------------------------------------------------------------------------------------------------------------
class Solution
{
    void solve(vector<int> &candidates, int target, vector<int> &curr, vector<vector<int>> &ans, int idx)
    {
        // Only positive numbers, so whenever target becomes negative, return
        if (target < 0)
            return;
        // If target becomes 0, add the current combination to the answer
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);                           // Include the current number
            solve(candidates, target - candidates[i], curr, ans, i); // Recur with the remaining target
            curr.pop_back();                                         // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        vector<vector<int>> ans;

        solve(candidates, target, curr, ans, 0);
        return ans;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    List<List<Integer>> combinationSum(int[] candidates, int target)
    {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();

        solve(candidates, target, curr, ans, 0);
        return ans;
    }

    void solve(int[] candidates, int target, List<Integer> curr, List<List<Integer>> ans, int idx)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int i = idx; i < candidates.length; i++)
        {
            curr.add(candidates[i]);
            solve(candidates, target - candidates[i], curr, ans, i);
            curr.remove(curr.size() - 1);
        }
    }
}