// GFG : https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution 
{
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) 
    {

        int count = 0;
        Node *mover = head;
        while(mover)
        {
            count++;
            mover = mover->next;
        }
        return count;
    }
};


// [Java]-----------------------------------------------------------------------------------------------------------------------------
/*Complete the function below*/
/*
class Node{
    int data;
    Node next;
    Node(int a){  data = a; next = null; }
}*/

class Solution 
{
    // Function to count nodes of a linked list.
    public int getCount(Node head) 
    {
        int count = 0;
        Node mover = head;
        while(mover != null)
        {
            count++;
            mover = mover.next;
        }
        return count;
    }
}