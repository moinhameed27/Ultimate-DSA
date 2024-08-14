// GFG : https://www.geeksforgeeks.org/problems/binary-tree-representation/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution
{
public:
    void create_tree(node *root0, vector<int> &vec)
    {
        root0->left = newNode(vec[1]);
        root0->right = newNode(vec[2]);

        root0->left->left = newNode(vec[3]);
        root0->left->right = newNode(vec[4]);

        root0->right->left = newNode(vec[5]);
        root0->right->right = newNode(vec[6]);
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
class Solution
{
public
    static void createTree(Node root0, ArrayList<Integer> v)
    {
        root0.left = new Node(v.get(1));
        root0.right = new Node(v.get(2));
        root0.left.left = new Node(v.get(3));
        root0.left.right = new Node(v.get(4));
        root0.right.left = new Node(v.get(5));
        root0.right.right = new Node(v.get(6));
    }
}