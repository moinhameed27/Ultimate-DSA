// GFG : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// [C++]----------------------------------------------------------------------------------------------------------------------------

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

// Way - I (Brute Force) --> O(3n)
/*
As we can't traverse backward so, reverse the linked list. Add 1 to it's head and if it's sum is 10, then replace it with zero and keep
adding the one to it's next node until the sum is less than 10. At the last node if sum is 10, make a new node having 1 and point it to head.
*/
class Solution
{
    // Reversing a linked list
    Node *reverseList(Node *head)
    {
        Node *prevNode = nullptr, *nextNode = head;
        while (head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

public:
    Node *addOne(Node *head)
    {
        head = reverseList(head);
        Node *mover = head;
        int carry = 1;
        while (mover)
        {
            mover->data += carry;
            // If sum is less than 10, no need to traverse and see other nodes
            if (mover->data < 10)
            {
                carry = 0;
                break;
            }
            // If there is carry for the current node, replace it's data with 0 and mark the carry
            else
                mover->data = 0, carry = 1;
            mover = mover->next;
        }
        // If the last node was made 10 after adding a carry, means there's still a carry, make a new node having 1 and point it to head
        if (carry)
        {
            Node *newNode = new Node(1);
            head = reverseList(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseList(head);
        return head;
    }
};

// Way - II (Optimal [Recursive]) --> O(n)
class Solution
{
    int add(Node *head)
    {
        // Base case
        if (head == nullptr)
            return 1;
        // Get carry from the last node
        int carry = add(head->next);
        // Add carry to current data
        head->data += carry;
        // If data is less than 10 after adding 1, return carry as 0
        if (head->data < 10)
            return 0;
        // Else replace data with 0 and return carry as 1
        head->data = 0;
        return 1;
    }

public:
    Node *addOne(Node *head)
    {
        int carry = add(head);
        // If the last node was made 10 after adding a carry, means there's still a carry, make a new node having 1 and point it to head
        if (carry)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

// [Java]----------------------------------------------------------------------------------------------------------------------------
/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/
// Way - I (Brute Force) --> O(3n)
class Solution
{
    // Reverse the linked list
    private Node reverseList(Node head)
    {
        Node prevNode = null;
        Node nextNode = head;
        while (head != null)
        {
            nextNode = head.next;
            head.next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    // Add one to the number represented by the linked list
    public Node addOne(Node head)
    {
        head = reverseList(head);
        Node mover = head;
        int carry = 1;
        while (mover != null)
        {
            mover.data += carry;
            // If sum is less than 10, no need to traverse further
            if (mover.data < 10)
            {
                carry = 0;
                break;
            }
            // If there is carry for the current node, replace its data with 0
            else
            {
                mover.data = 0;
            }
            carry = 1;
            mover = mover.next;
        }
        // If there is still a carry after processing all nodes
        if (carry == 1)
        {
            Node newNode = new Node(1);
            head = reverseList(head);
            newNode.next = head;
            return newNode;
        }
        head = reverseList(head);
        return head;
    }
}

// Way - II (Optimal [Recursive]) --> O(n)
class Solution
{
    // Add one to the number represented by the linked list
    private int add(Node head)
    {
        // Base case
        if (head == null)
            return 1;
        // Get carry from the last node
        int carry = add(head.next);
        // Add carry to current data
        head.data += carry;
        // If data is less than 10 after adding 1, return carry as 0
        if (head.data < 10)
            return 0;
        // Else replace data with 0 and return carry as 1
        head.data = 0;
        return 1;
    }

    public Node addOne(Node head)
    {
        int carry = add(head);
        // If there is still a carry after processing all nodes
        if (carry == 1)
        {
            Node newNode = new Node(1);
            newNode.next = head;
            head = newNode;
        }
        return head;
    }
}
