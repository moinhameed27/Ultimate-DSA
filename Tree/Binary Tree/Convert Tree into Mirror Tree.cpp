// GFG : https://www.geeksforgeeks.org/problems/mirror-tree/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
// function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Way - I (DFS)
class Solution
{
public:
    void mirror(Node *node)
    {
        if (node == nullptr)
            return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
};

// Way - II (BFS)
class Solution
{
public:
    void mirror(Node *node)
    {
        if (node == nullptr)
            return;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            swap(front->left, front->right);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// FUNCTION CODE
/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
   Node(int item)
   {
        data = item;
        left = right = null;
    }
} */

// Way - I (DFS)
class Solution
{
    void mirror(Node node)
    {
        if (node == null)
            return;
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
        mirror(node.left);
        mirror(node.right);
    }
}

// Way - II (BFS)
class Solution
{
    void mirror(Node node)
    {
        if (node == null)
            return;
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        while (!q.isEmpty())
        {
            Node front = q.poll();
            Node temp = front.left;
            front.left = front.right;
            front.right = temp;
            if (front.left != null)
                q.add(front.left);
            if (front.right != null)
                q.add(front.right);
        }
    }
}