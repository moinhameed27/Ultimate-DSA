// GFG :

// Way - I (Counting)
class Solution
{
public:
    Node *insertInMiddle(Node *head, int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
            return newNode;
        int count = 0;
        Node *mover = head;
        // Count the Nodes
        while (mover)
            count++, mover = mover->next;

        // If nodes are even, divide by 2, otherwise divide by 2 and add 1
        count = (count % 2 == 0) ? (count / 2) : (count / 2) + 1;
        mover = head;
        // Traverse to the required node
        while (--count)
            mover = mover->next;
        newNode->next = mover->next;
        mover->next = newNode;
        return head;
    }
};

// Way - II (Two Pointer)
class Solution
{
public:
    Node *insertInMiddle(Node *head, int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
            return newNode;
        // Doing fast->next will move it to the perfect required middle node
        Node *fast = head->next, *slow = head;
        while (fast && fast->next && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
        return head;
    }
};