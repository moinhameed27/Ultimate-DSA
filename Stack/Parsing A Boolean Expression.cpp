// Leetcode : https://leetcode.com/problems/parsing-a-boolean-expression/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Solve SubExpr [any_of]) : O(n) time and O(n) space
class Solution
{
    char solveSubExpr(vector<char> &values, char op)
    {
        if (op == '!')
            return values[0] == 't' ? 'f' : 't';
        // If minimum one value is f, whole expression will be f
        else if (op == '&')
            return any_of(values.begin(), values.end(), [](char &ch) { return ch == 'f'; }) ? 'f' : 't';
        // If minimum one value is t, whole expression will be t
        else    // '|
            return any_of(values.begin(), values.end(), [](char &ch) { return ch == 't'; }) ? 't' : 'f';
    }

public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        for (char ch : expression)
        {
            if (ch == ',')  // No use of ','
                continue;
            // An expression is completed and is required to solve
            else if (ch == ')')
            {
                vector<char> values;
                // Pop all values of the sub-expression
                while (st.top() != '(')
                {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();   // Pop '('
                char op = st.top(); // Pop operator
                st.pop();
                // Solve the sub-expression and push the result
                st.push(solveSubExpr(values, op));
            }
            // Push the character
            else
                st.push(ch);
        }
        // Return the final result
        return st.top() == 't';
    }
};

// Way - II (Set to Solve SubExpr) : O(n) time and O(n) space
class Solution
{
    char solveSubExpr(unordered_set<char> values, char op)
    {
        if (op == '!')
            return *values.begin() == 't' ? 'f' : 't';
        // If minimum one value is f, whole expression will be f
        else if (op == '&')
            return values.count('f') ? 'f' : 't';
        // If minimum one value is t, whole expression will be t
        else    // '|'
            return values.count('t') ? 't' : 'f';
    }

public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        for (char ch : expression)
        {
            if (ch == ',')  // No use of ','
                continue;
            // An expression is completed and is required to solve
            else if (ch == ')')
            {
                unordered_set<char> values;
                // Pop all values of the sub-expression
                while (st.top() != '(')
                {
                    values.insert(st.top());
                    st.pop();
                }
                st.pop();   // Pop '('
                char op = st.top(); // Pop operator
                st.pop();
                // Solve the sub-expression and push the result
                st.push(solveSubExpr(values, op));
            }
            // Push the character
            else
                st.push(ch);
        }
        // Return the final result
        return st.top() == 't';
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Solve SubExpr [anyMatch]) : O(n) time and O(n) space
class Solution 
{
    public boolean parseBoolExpr(String expression) 
    {
        Stack<Character> st = new Stack<>();
        for (char ch : expression.toCharArray()) 
        {
            if (ch == ',')  // No use of ','
                continue;
            // An expression is completed and is required to solve
            else if (ch == ')') 
            {
                List<Character> values = new ArrayList<>();
                // Pop all values of the sub-expression
                while (st.peek() != '(') 
                    values.add(st.pop());
                
                st.pop();   // Pop '('
                char op = st.pop(); // Pop operator
                // Solve the sub-expression and push the result
                st.push(solveSubExpr(values, op));
            }
            // Push the character
            else
                st.push(ch);
        }
        // Return the final result
        return st.peek() == 't';
    }

    private char solveSubExpr(List<Character> values, char op) 
    {
        if (op == '!')
            return values.get(0) == 't' ? 'f' : 't';
        // If minimum one value is f, whole expression will be f
        else if (op == '&')
            return values.stream().anyMatch(ch -> ch == 'f') ? 'f' : 't';
        // If minimum one value is t, whole expression will be t
        else    // '|
            return values.stream().anyMatch(ch -> ch == 't') ? 't' : 'f';
    }
}

// Way - II (Set to Solve SubExpr) : O(n) time and O(n) space
class Solution 
{
    public boolean parseBoolExpr(String expression) 
    {
        Stack<Character> st = new Stack<>();
        for (char ch : expression.toCharArray()) 
        {
            if (ch == ',')  // No use of ','
                continue;
            // An expression is completed and is required to solve
            else if (ch == ')') 
            {
                Set<Character> values = new HashSet<>();
                // Pop all values of the sub-expression
                while (st.peek() != '(') 
                    values.add(st.pop());
                
                st.pop();   // Pop '('
                char op = st.pop(); // Pop operator
                // Solve the sub-expression and push the result
                st.push(solveSubExpr(values, op));
            }
            // Push the character
            else
                st.push(ch);
        }
        // Return the final result
        return st.peek() == 't';
    }

    private char solveSubExpr(Set<Character> values, char op) 
    {
        if (op == '!')
            return values.iterator().next() == 't' ? 'f' : 't';
        // If minimum one value is f, whole expression will be f
        else if (op == '&')
            return values.contains('f') ? 'f' : 't';
        // If minimum one value is t, whole expression will be t
        else    // '|
            return values.contains('t') ? 't' : 'f';
    }
}