// Leetcode : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

// C++----------------------------------------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Way - I (Brute Force [Reverse List])
class Solution
{
    ListNode *reverseList(ListNode *head)
    {
        ListNode *nextNode = head, *prevNode = nullptr;
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
    ListNode *doubleIt(ListNode *head)
    {
        head = reverseList(head);
        ListNode *mover = head, *prev = nullptr;
        int carry = 0;
        while (mover)
        {
            // Multiply by 2 and add carry
            int newValue = mover->val * 2 + carry;
            // Update the value of the node
            mover->val = newValue % 10;
            // Update the carry
            if (newValue >= 10)
                carry = 1;
            else
                carry = 0;
            prev = mover;
            mover = mover->next;
        }
        // If carry is still left
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return reverseList(head);
    }
};

// Way - II (Stack)
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        stack<int> st;
        int val = 0;
        // Push all the values in the stack
        while (head)
        {
            st.push(head->val);
            head = head->next;
        }
        ListNode *mover = nullptr;
        // Pop the values from the stack and double them and add to the new list
        while (!st.empty() || val != 0)
        {
            // Create a new node and point it's next to the previous node
            mover = new ListNode(0, mover);
            if (!st.empty())
            {
                val += st.top() * 2;
                st.pop();
            }
            mover->val = val % 10; // Value of node
            val /= 10;             // Carry
        }
        return mover;
    }
};

// Way - III (Prev and Current Pointers)
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *mover = head, *prev = nullptr;
        while (mover)
        {
            int newValue = mover->val * 2;
            if (newValue < 10)
                mover->val = newValue;
            // If the value is greater than 10 then add the carry to the previous node
            else if (prev)
            {
                mover->val = newValue % 10;
                prev->val++;
            }
            // If prev is null, means we are standing at the head node
            else
            {
                ListNode *newHead = new ListNode(1, mover);
                mover->val = newValue % 10;
                head = newHead;
            }
            prev = mover;
            mover = mover->next;
        }
        return head;
    }
};

// Java----------------------------------------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// Way - I (Brute Force [Reverse List])
class Solution
{
public
    ListNode reverseList(ListNode head)
    {
        ListNode nextNode = head, prevNode = null;
        while (head != null)
        {
            nextNode = head.next;
            head.next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

public
    ListNode doubleIt(ListNode head)
    {
        head = reverseList(head);
        ListNode mover = head, prev = null;
        int carry = 0;
        while (mover != null)
        {
            // Multiply by 2 and add carry
            int newValue = mover.val * 2 + carry;
            // Update the value of the node
            mover.val = newValue % 10;
            // Update the carry
            if (newValue >= 10)
                carry = 1;
            else
                carry = 0;
            prev = mover;
            mover = mover.next;
        }
        // If carry is still left
        if (carry == 1)
        {
            ListNode newNode = new ListNode(1);
            prev.next = newNode;
        }
        return reverseList(head);
    }
}

// Way - II (Stack)
class Solution
{
public
    ListNode doubleIt(ListNode head)
    {
        Stack<Integer> st = new Stack<>();
        int val = 0;
        // Push all the values in the stack
        while (head != null)
        {
            st.push(head.val);
            head = head.next;
        }
        ListNode mover = null;
        // Pop the values from the stack and double them and add to the new list
        while (!st.isEmpty() || val != 0)
        {
            // Create a new node and point it's next to the previous node
            mover = new ListNode(0, mover);
            if (!st.isEmpty())
            {
                val += st.pop() * 2;
            }
            mover.val = val % 10; // Value of node
            val /= 10;            // Carry
        }
        return mover;
    }
}

// Way - III (Prev and Current Pointers)
class Solution
{
public
    ListNode doubleIt(ListNode head)
    {
        ListNode mover = head, prev = null;
        while (mover != null)
        {
            int newValue = mover.val * 2;
            if (newValue < 10)
                mover.val = newValue;
            // If the value is greater than 10 then add the carry to the previous node
            else if (prev != null)
            {
                mover.val = newValue % 10;
                prev.val++;
            }
            // If prev is null, means we are standing at the head node
            else
            {
                ListNode newHead = new ListNode(1, mover);
                mover.val = newValue % 10;
                head = newHead;
            }
            prev = mover;
            mover = mover.next;
        }
        return head;
    }
}