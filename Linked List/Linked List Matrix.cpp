// GFG : https://www.geeksforgeeks.org/problems/linked-list-matrix/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/* structure of the node of the linked list is as
struct Node
{
    int data;
    Node *right, *down;

    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

    // function must return the pointer to the first element of the in linked list i.e. that
    // should be the element at arr[0][0]
    class Solution
{
public:
    Node *constructLinkedMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        vector<vector<Node *>> nodes(m, vector<Node *>(n));

        // Creating a matrix of Node *
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                nodes[i][j] = new Node(mat[i][j]);
        }

        // Linking the nodes
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nodes[i][j]->right = (j + 1 == n) ? nullptr : nodes[i][j + 1];
                nodes[i][j]->down = (i + 1 == m) ? nullptr : nodes[i + 1][j];
            }
        }
        return nodes[0][0];
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// User function Template for Java

/*class Node
{
   int data;
   Node right, down;

   Node(int data){
       this.data = data;
       right = null;
       down = null;
   }
}
*/

/* Function should return the head of the 2D Linked List. */
class Solution 
{
    static Node construct(int arr[][]) 
    {
        int m = arr.length, n = arr[0].length;

        Node nodes[][] = new Node[m][n];
        
        // Creating nodes for each element
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
                nodes[i][j] = new Node(arr[i][j]);
        }

        // Linking the nodes
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                nodes[i][j].right = (j + 1 == n) ? null : nodes[i][j + 1];  
                nodes[i][j].down = (i + 1 == m) ? null : nodes[i + 1][j];  
            }
        }
        
        return nodes[0][0];
    }
}