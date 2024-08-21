// GFG : https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/*
* Initialize answer with -1.
1. If input val is greater than current root's value, move to the right subtree.
2. If input val is smaller than current root's value, update the answer with current value and move to the left subtree.
*/
// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    Node *mover = root;
    int ans = -1;
    while (mover)
    {
        if (mover->data == input)
            return input;
        if (input > mover->data)
            mover = mover->right;
        else
        {
            ans = mover->data;
            mover = mover->left;
        }
    }
    return ans;
}

// Way - II (Recursive)
void solve(Node *root, int input, int &ans)
{
    if (root == NULL)
        return;

    if (root->data == input)
    {
        ans = input;
        return;
    }
    if (input > root->data)
        return solve(root->right, input, ans);
    else
    {
        ans = root->data;
        return solve(root->left, input, ans);
    }
}

int findCeil(Node *root, int input)
{
    int ans = -1;
    solve(root, input, ans);
    return ans;
}

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
class Tree
{
    int findCeil(Node root, int input)
    {
        if (root == null)
            return -1;

        Node mover = root;
        int ans = -1;
        while (mover != null)
        {
            if (mover.data == input)
                return input;
            if (input > mover.data)
                mover = mover.right;
            else
            {
                ans = mover.data;
                mover = mover.left;
            }
        }
        return ans;
    }
}

// Way - II (Recursive)
class Tree
{
    void solve(Node root, int input, int[] ans)
    {
        if (root == null)
            return;

        if (root.data == input)
        {
            ans[0] = input;
            return;
        }
        if (input > root.data)
            solve(root.right, input, ans);
        else
        {
            ans[0] = root.data;
            solve(root.left, input, ans);
        }
    }

    int findCeil(Node root, int input)
    {
        int[] ans = new int[1];
        ans[0] = -1;
        solve(root, input, ans);
        return ans[0];
    }
}