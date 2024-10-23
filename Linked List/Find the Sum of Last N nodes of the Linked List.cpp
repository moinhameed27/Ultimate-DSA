// GFG : https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node *head, int n)
    {
        int count = 0, sum = 0;
        Node *mover = head;
        while (mover)
        {
            count++;
            mover = mover->next;
        }
        // Skip first non-required nodes
        int skips = count - n;
        mover = head;
        while (mover)
        {
            skips--;
            if (skips < 0)
                sum += mover->data;
            mover = mover->next;
        }
        return sum;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
/*
Node class is as follows:

class Node {
    int data;
    Node next;

    public Node (int data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution 
{
    // Return the sum of last k nodes
    public int sumOfLastN_Nodes(Node head, int n) 
    {
        int count = 0, sum = 0;
        Node mover = head;
        while (mover != null) 
        {
            count++;
            mover = mover.next;
        }
        // Skip first non-required nodes
        int skips = count - n;
        mover = head;
        while (mover != null) 
        {
            skips--;
            if (skips < 0)
                sum += mover.data;
            mover = mover.next;
        }
        return sum;
    }
}