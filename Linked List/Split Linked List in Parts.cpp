// Leetcode : https://leetcode.com/problems/split-linked-list-in-parts/description/

/* 
Divide the length of the linked list with k, that'll be the complete parts and then take modulus to get the remaining parts.
The remaining parts are to be added to the starting portions with keeping the difference between parts <= 1.
Then iterate through the linked list and keep adding the parts to the answer array.
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *mover = head, *prev = nullptr;
        int length = 0;
        // Count the Length of Linked List
        while (mover)
        {
            length++;
            mover = mover->next;
        }
        // Get the total parts and remaining parts
        int parts = length / k, remParts = length % k;
        vector<ListNode *> ans(k, nullptr);
        mover = head;
        // Keep moving until k parts are done or the linked list is finished
        for (int i = 0; mover && i < k; i++)
        {
            ans[i] = mover;
            // If remaining parts are more than 1, then add 1 to the starting parts
            for (int j = 0; j < parts + (remParts > 0) ? 1 : 0; j++)
            {
                prev = mover;
                mover = mover->next;
            }
            prev->next = nullptr;   // Break the link
            remParts--; // Decrement the remaining parts as one part is done each time
        }
        return ans;
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
    public ListNode[] splitListToParts(ListNode head, int k) 
    {
        ListNode mover = head, prev = null;
        int length = 0;
        while(mover != null)
        {
            length++;
            mover = mover.next;
        }
        int parts = length / k, remParts = length % k;
        ListNode[] ans = new ListNode[k];
        mover = head;
        for(int i = 0; mover != null && i < k; i++)
        {
            ans[i] = mover;
            for(int j = 0; j < parts + (remParts > 0 ? 1 : 0); j++)
            {
                prev = mover;
                mover = mover.next;
            }
            prev.next = null;
            remParts--;
        }
        return ans;
        
    }
}