// GFG : https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function

// Way - I (Brute Force [Counting])
class Solution
{
public:
    void deleteAlt(struct Node *head)
    {
        Node *mover = head, *prev = nullptr;
        int count = 0;
        while (mover)
        {
            count++;
            if (count % 2 == 0)
            {
                Node *toDelete = mover;
                mover = mover->next;
                prev->next = mover;
                delete toDelete;
            }
            else
            {
                prev = mover;
                mover = mover->next;
            }
        }
    }
};

// Way - II (Optimized)
class Solution
{
public:
    void deleteAlt(struct Node *head)
    {
        Node *mover = head, *next = head->next;
        while (next)
        {
            Node *toDelete = next;
            mover->next = next->next;
            mover = mover->next;
            next = next->next;
            if (next)
                next = next->next;
            delete toDelete;
        }
    }
};


// [Java]-----------------------------------------------------------------------------------------------------------------------------
/*
class Node {
    int data;
    Node next;

    public Node(int data){
        this.data = data;
    }
}
*/

// Way - I (Brute Force [Counting])
class Solution 
{
    public void deleteAlt(Node head) 
    {
        Node mover = head, prev = null;
        int count = 0;
        while(mover != null)
        {
            count++;
            if(count % 2 == 0)
            {
                Node toDelete = mover;
                mover = mover.next;
                prev.next = mover;
                toDelete = null;
            }
            else
            {
                prev = mover;
                mover = mover.next;
            }
        }
    }
}

// Way - II (Optimized)
class Solution 
{
    public void deleteAlt(Node head) 
    {
        Node mover = head, next = head.next;
        while(next != null)
        {
            Node toDelete = next;
            mover.next = next.next;
            mover = mover.next;
            next = next.next;
            if(next != null)
                next = next.next;
            toDelete = null;
        }
    }
}