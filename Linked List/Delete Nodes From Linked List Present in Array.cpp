// Leetcode : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

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
// Way - I (Brute Force [Set])
/* Insert all elements into set, whenever any nodes value exist in the set, delete it. */
class Solution
{
    void deleteNode(ListNode *&head, ListNode *&node, ListNode *&prev)
    {
        if (head == node)
        {
            head = head->next;
            delete node;
            node = head;
        }
        else
        {
            prev->next = node->next;
            delete node;
            node = prev->next;
        }
    }

public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);

        ListNode *mover = head, *prev = nullptr;
        while (mover)
        {
            if (st.find(mover->val) != st.end())
                deleteNode(head, mover, prev);
            else
            {
                prev = mover;
                mover = mover->next;
            }
        }
        return head;
    }
};

// Way - II (Two Pass)
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        // Remove all the nodes from the beginning of the list
        ListNode *mover = head, *prev = nullptr;
        while (mover && st.count(mover->val))
        {
            head = mover->next;
            mover = head;
        }

        while (mover)
        {
            // If the node is present in the set, delete it
            if (st.count(mover->val))
            {
                prev->next = mover->next;
                mover = prev->next;
            }
            // Else move the pointers
            else
            {
                prev = mover;
                mover = mover->next;
            }
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
// Way - I (Brute Force [Set])
/* Insert all elements into set, whenever any nodes value exist in the set, delete it. */
class Solution
{
    public ListNode modifiedList(int[] nums, ListNode head)
    {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums)
            set.add(num); 

        ListNode mover = head, prev = null;
        while (mover != null)
        {
            if (set.contains(mover.val))
            {
                if (prev == null)
                    head = mover.next;
                else
                    prev.next = mover.next;
            }
            else
                prev = mover;

            mover = mover.next;
        }
        return head;
    }
}

// Way - II (Two Pass)
class Solution
{
    public ListNode modifiedList(int[] nums, ListNode head)
    {
        HashSet<Integer> set = new HashSet<>(Arrays.stream(nums).boxed().collect(Collectors.toList()));

        // Remove all the nodes from the beginning of the list
        ListNode mover = head, prev = null;
        while (mover != null && set.contains(mover.val))
        {
            head = mover.next;
            mover = head;
        }

        while (mover != null)
        {
            // If the node is present in the set, delete it
            if (set.contains(mover.val))
            {
                prev.next = mover.next;
                mover = prev.next;
            }
            // Else move the pointers
            else
            {
                prev = mover;
                mover = mover.next;
            }
        }
        return head;
    }
}