// GFG : https://www.geeksforgeeks.org/problems/xor-linked-list/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data)
{
    Node *node = new Node(data);
    node->npx = head;
    return node;
}

vector<int> getList(struct Node *head)
{
    vector<int> list;
    while (head)
    {
        list.push_back(head->data);
        head = head->npx;
    }
    return list;
}

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// class Node {
//     int data;
//     Node npx;

//     Node(int x) {
//         data = x;
//         npx = null;
//     }
// }
class Solution 
{
    // function should insert the data to the front of the list
    static Node insert(Node head, int data) 
    {
        Node node = new Node(data);
        node.npx = head;
        return node;
    }

    // function to print the linked list
    static ArrayList<Integer> getList(Node head) 
    {
        ArrayList list = new ArrayList<>();
        while(head != null)
        {
            list.add(head.data);
            head = head.npx;
        }
        return list;
    }
}