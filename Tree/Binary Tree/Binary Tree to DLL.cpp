// GFG : https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

public:
    Node *bToDLL(Node *root)
    {
        vector<int> ans;
        inorder(root, ans);
        Node *head = new Node(ans[0]);
        Node *mover = head;

        for (int i = 1; i < ans.size(); i++)
        {
            Node *newNode = new Node(ans[i]);
            mover->right = newNode;     // Next of current node is newNode
            newNode->left = mover;      // Previous of newNode is current node
            mover = mover->right;
        }
        return head;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
//User function Template for Java

/* class Node
class Node
{
	Node left, right;
	int data;
	
	Node(int d)
	{
		data = d;
		left = right = null;
	}
	
}*/

//This function should return head to the DLL

class Solution
{
    void inorder(Node root, ArrayList<Integer> ans)
    {
        if (root == null)
            return;
        inorder(root.left, ans);
        ans.add(root.data);
        inorder(root.right, ans);
    }

    Node bToDLL(Node root)
    {
        ArrayList<Integer> ans = new ArrayList<>();
        inorder(root, ans);
        Node head = new Node(ans.get(0));
        Node mover = head;

        for (int i = 1; i < ans.size(); i++)
        {
            Node newNode = new Node(ans.get(i));
            mover.right = newNode;     // Next of current node is newNode
            newNode.left = mover;      // Previous of newNode is current node
            mover = mover.right;
        }
        return head;
    }
}