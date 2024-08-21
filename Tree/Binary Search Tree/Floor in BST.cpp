// GFG : https://www.geeksforgeeks.org/problems/floor-in-bst/1

/*
* Initialize answer with -1.
1. If input val is less than current root's value, move to the left subtree.
2. If input val is greater than current root's value, update the answer with current value and move to the right subtree.
*/
// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
class Solution
{

public:
    int floor(Node *root, int x)
    {
        int ans = -1;
        Node *mover = root;
        while (mover)
        {
            if (mover->data == x)
                return x;
            if (x < mover->data)
                mover = mover->left;
            else
            {
                ans = mover->data;
                mover = mover->right;
            }
        }
        return ans;
    }
};

// Way - II (Recursive)
class Solution
{
    void solve(Node *root, int x, int &ans)
    {
        if (root == nullptr)
            return;

        if (root->data == x)
        {
            ans = x;
            return;
        }
        else if (x < root->data)
            return solve(root->left, x, ans);
        else
        {
            ans = root->data;
            return solve(root->right, x, ans);
        }
    }

public:
    int floor(Node *root, int x)
    {
        int ans = -1;
        solve(root, x, ans);
        return ans;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
class Solution {
    public static int floor(Node root, int x)
    {
        int ans = -1;
        Node mover = root;
        while (mover != null)
        {
            if (mover.data == x)
                return x;
            if (x < mover.data)
                mover = mover.left;
            else
            {
                ans = mover.data;
                mover = mover.right;
            }
        }
        return ans;
    }
}

// Way - II (Recursive)
class Solution
{
    void solve(Node root, int x, int[] ans)
    {
        if (root == null)
            return;

        if (root.data == x)
        {
            ans[0] = x;
            return;
        }
        else if (x < root.data)
            solve(root.left, x, ans);
        else
        {
            ans[0] = root.data;
            solve(root.right, x, ans);
        }
    }

    int floor(Node root, int x)
    {
        int[] ans = new int[1];
        ans[0] = -1;
        solve(root, x, ans);
        return ans[0];
    }
}