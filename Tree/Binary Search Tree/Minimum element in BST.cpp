// GFG : https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/* Left most element in the BST will be the minimum element. */
// [C++]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
class Solution
{
public:
    int minValue(Node *root)
    {
        Node *mover = root;
        while (mover->left)
            mover = mover->left;
        return mover->data;
    }
};

// Way - II (Recursive)
class Solution
{
public:
    int minValue(Node *root)
    {
        if (!root->left)
            return root->data;
        return minValue(root->left);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Iterative)
class Tree
{
    int minValue(Node node)
    {
        Node mover = node;
        while (mover.left != null)
            mover = mover.left;
        return mover.data;
    }
}

// Way - II (Recursive)
class Tree
{
    int minValue(Node node)
    {
        if (node.left == null)
            return node.data;
        return minValue(node.left);
    }
}