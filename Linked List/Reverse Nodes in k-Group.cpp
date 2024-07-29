// LeetCode : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    // To reverse any part of the array
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode = nullptr;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int count = 0;
        ListNode *dummyNode = new ListNode(-1, head);
        // PrevNode will be pointing to the node before the start of the kth part and end will be traversing all the LL and will be at the end of each kth part
        ListNode *prevNode = dummyNode, *end = head;
        while (end)
        {
            count++;
            // When kth node is arrived
            if (count % k == 0)
            {
                // Start from the First element, preserve the next node of current last node to restore the link after breaking and reversing it
                ListNode *start = prevNode->next, *nextNode = end->next;
                // Breaking the link to reverse the part
                end->next = nullptr;
                // Storing the head in the first node after kth node
                prevNode->next = reverseList(start);
                // Restoring the broken link
                start->next = nextNode;
                // prevNode will go to the node before the start of next kth part
                prevNode = start;
                // End will move forward
                end = nextNode;
            }
            // If k-Group is not completed
            else
                end = end->next;
        }
        // Return the head of the Linked List
        return dummyNode->next;
    }
};