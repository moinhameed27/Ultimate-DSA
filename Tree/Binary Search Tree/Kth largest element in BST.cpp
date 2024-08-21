// GFG : https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

/* Reverse Inorder Traversal to get Descending elemnts in BST */
// [C++]-----------------------------------------------------------------------------------------------------------------------
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Way - I (Brute Force [Inorder Traversal (Vector)]) : O(n) time and O(n) space
class Solution
{
    void solve(Node *root, int k, vector<int> &v)
    {
        if (!root)
            return;
        solve(root->right, k, v);
        v.push_back(root->data);
        solve(root->left, k, v);
    }

public:
    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        solve(root, K, inorder);
        return inorder[K - 1];
    }
};

// Way - II (Count [Reverse Inorder]) : O(n) time and O(1) space
class Solution
{
    void solve(Node *root, int k, int &count, int &ans)
    {
        if (!root)
            return;
        solve(root->right, k, count, ans);
        count++;
        if (count == k)
        {
            ans = root->data;
            return;
        }
        solve(root->left, k, count, ans);
    }

public:
    int kthLargest(Node *root, int K)
    {
        int count = 0, ans = 0;
        solve(root, K, count, ans);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Brute Force [Inorder Traversal (Vector)]) : O(n) time and O(n) space
class Solution
{
    void solve(Node root, int k, List<Integer> v)
    {
        if (root == null)
            return;
        solve(root.right, k, v);
        v.add(root.data);
        solve(root.left, k, v);
    }

    public int kthLargest(Node root, int K)
    {
        List<Integer> inorder = new ArrayList<>();
        solve(root, K, inorder);
        return inorder.get(K - 1);
    }
}

// Way - II (Count [Reverse Inorder]) : O(n) time and O(1) space
class Solution
{
    void solve(Node root, int k, int []count, int []ans)
    {
        if (root == null)
            return;
        solve(root.right, k, count, ans);
        count[0]++;
        if (count[0] == k)
        {
            ans[0] = root.data;
            return;
        }
        solve(root.left, k, count, ans);
    }

    public int kthLargest(Node root, int K)
    {
        int []count = new int[1];
        count[0] = 0;
        int []ans = new int[1];
        ans[0] = 0;
        solve(root, K, count, ans);
        return ans[0];
    }
}