// LeetCode : https://leetcode.com/problems/middle-of-the-linked-list/

// GFG : https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
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

// Way - I (Brute Force)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;

        // Count the number of nodes
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        // Get the middle of the size
        int mid = count / 2 + 1;

        temp = head;
        // Traverse until mid is reached
        while (mid--)
        {
            if (mid > 0)
                temp = temp->next;
        }
        return temp;
    }
};

// Way - II (Optimal) [Tortoise and Hare Algo]
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
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
// Way - I (Brute Force)
class Solution
{
    public ListNode middleNode(ListNode head)
    {
        ListNode temp = head;
        int count = 0;

        // Count the number of nodes
        while (temp != null)
        {
            count++;
            temp = temp.next;
        }

        // Get the middle of the size
        int mid = count / 2 + 1;

        temp = head;
        // Traverse until mid is reached
        while (mid-- > 0)
        {
            if (mid > 0)
                temp = temp.next;
        }
        return temp;
    }
}

// Way - II (Optimal) [Tortoise and Hare Algo]
class Solution
{
    public ListNode middleNode(ListNode head)
    {
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}