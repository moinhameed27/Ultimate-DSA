// GFG : https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution
{
public:
    int count(struct Node *head, int key)
    {
        Node *mover = head;
        int count = 0;
        while (mover)
        {
            if (mover->data == key)
                count++;
            mover = mover->next;
        }
        return count;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}*/
// complete the below function
class Solution 
{
    public static int count(Node head, int key) 
    {
        Node mover = head;
        int count = 0;
        while (mover != null) 
        {
            if (mover.data == key) 
                count++;
            mover = mover.next;
        }
        return count;   
    }
}