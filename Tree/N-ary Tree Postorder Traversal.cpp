// Leetcode : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Way - I (Recursive)
class Solution
{
    void solve(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        for (Node *&x : root->children)
            solve(x, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Way - II (Iterative)
class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            for (Node *&x : temp->children)
                st.push(x);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Way - I (Recursive)
class Solution
{
    public List<Integer> postorder(Node root)
    {
        List<Integer> ans = new ArrayList<>();
        solve(root, ans);
        return ans;
    }

    private void solve(Node root, List<Integer> ans)
    {
        if (root == null)
            return;
        for (Node x : root.children)
            solve(x, ans);
        ans.add(root.val);
    }
}

// Way - II (Iterative)
class Solution
{
    public List<Integer> postorder(Node root)
    {
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        Stack<Node> st = new Stack<>();
        st.push(root);
        while (!st.isEmpty())
        {
            Node temp = st.pop();
            ans.add(temp.val);
            for (Node x : temp.children)
                st.push(x);
        }
        Collections.reverse(ans);
        return ans;
    }
}