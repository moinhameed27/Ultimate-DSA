// Leetcode : https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

// [C++]-----------------------------------------------------------------------------------------------------------------------------
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        if (head && !head->next)
            return {head, nullptr};
        Node *head1 = head, *head2 = head->next;
        Node *mover1 = head1, *mover2 = head2;
        while (mover1 && mover2)
        {
            mover1->next = mover1->next ? mover1->next->next : nullptr;
            mover2->next = mover2->next ? mover2->next->next : nullptr;
            mover1 = mover1->next;
            mover2 = mover2->next;
        }
        return {head1, head2};
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
    Node[] alternatingSplitList(Node head)
    {
        if (head != null && head.next == null)
            return new Node[] {head, null};
        Node head1 = head, head2 = head.next;
        Node mover1 = head1, mover2 = head2;
        while (mover1 != null && mover2 != null)
        {
            mover1.next = mover1.next != null ? mover1.next.next : null;
            mover2.next = mover2.next != null ? mover2.next.next : null;
            mover1 = mover1.next;
            mover2 = mover2.next;
        }
        return new Node[] {head1, head2};
    }
}