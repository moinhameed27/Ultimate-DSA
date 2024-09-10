// Leetcode : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

/*
For further approaches of finding GCD of two numbers, checkout https://github.com/moinhameed27/Ultimate-DSA/blob/main/Maths/GCD%20of%20two%20numbers.cpp
*/

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
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *mover = head;
        while (mover && mover->next)
        {
            int a = mover->val, b = mover->next->val;
            int gcd = __gcd(a, b);
            ListNode *nextNode = mover->next;
            ListNode *newNode = new ListNode(gcd, mover->next);
            mover->next = newNode;
            mover = nextNode;
        }
        return head;
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
class Solution 
{
    private int gcd(int a, int b)
    {
        while (b > 0)
        {
            a = a % b;
            int temp = a;
            a = b;
            b = temp;
        }
        return a;
    }
    public ListNode insertGreatestCommonDivisors(ListNode head) 
    {
        ListNode mover = head;
        while (mover != null && mover.next != null)
        {
            int a = mover.val, b = mover.next.val;
            int gcd = gcd(a, b);
            ListNode nextNode = mover.next;
            ListNode newNode = new ListNode(gcd, mover.next);
            mover.next = newNode;
            mover = nextNode;
        }
        return head;
    }
}