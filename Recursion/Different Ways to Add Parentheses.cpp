// Leetcode : https://leetcode.com/problems/different-ways-to-add-parentheses/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    unordered_map<string, vector<int>> mp; // For Memoization

    vector<int> solve(string expression)
    {
        if (mp.find(expression) != mp.end())
            return mp[expression];

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++)
        {
            // If operator is found, split the expression into two parts and solve them recursively
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {

                vector<int> leftResult = solve(expression.substr(0, i));
                vector<int> rightResult = solve(expression.substr(i + 1));

                // Combine the results of left and right parts according to the operator
                for (int a : leftResult)
                {
                    for (int b : rightResult)
                    {
                        if (expression[i] == '+')
                            ans.push_back(a + b);
                        else if (expression[i] == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If no operator is found, the expression is a number، so return the number
        if (ans.empty())
            ans.push_back(stoi(expression));

        return mp[expression] = ans;
    }

public:
    vector<int> diffWaysToCompute(string expression)
    {
        return solve(expression);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
    Map<String, List<Integer>> mp = new HashMap<>();

    public List<Integer> diffWaysToCompute(String expression)
    {
        if (mp.containsKey(expression))
            return mp.get(expression);

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < expression.length(); i++)
        {
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*')
            {
                List<Integer> leftResult = diffWaysToCompute(expression.substring(0, i));
                List<Integer> rightResult = diffWaysToCompute(expression.substring(i + 1));

                for (int a : leftResult)
                {
                    for (int b : rightResult)
                    {
                        if (expression.charAt(i) == '+')
                            ans.add(a + b);
                        else if (expression.charAt(i) == '-')
                            ans.add(a - b);
                        else
                            ans.add(a * b);
                    }
                }
            }
        }

        if (ans.isEmpty())
            ans.add(Integer.parseInt(expression));

        mp.put(expression, ans);
        return ans;
    }
}