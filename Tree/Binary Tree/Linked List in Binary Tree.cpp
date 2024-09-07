// Leetcode : https://leetcode.com/problems/linked-list-in-binary-tree/description/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Way - I (DFS)
class Solution
{
public:
    bool solve(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;

        if (!root || root->val != head->val)
            return false;

        return solve(head->next, root->left) || solve(head->next, root->right);
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root)
            return false;
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

// Way - II (BFS)
/* Traverse normally and when head node is found, check the subtree if linked list exists or not. */
class Solution
{
    bool solve(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (!root || root->val != head->val)
            return false;
        return solve(head->next, root->left) || solve(head->next, root->right);
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == head->val && solve(head, front))
                return true;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        return false;
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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// Way - I (DFS)
class Solution
{
    public boolean isSubPath(ListNode head, TreeNode root)
    {
        if (root == null)
            return false;
        return solve(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    public boolean solve(ListNode head, TreeNode root)
    {
        if (head == null)
            return true;
        if (root == null || root.val != head.val)
            return false;
        return solve(head.next, root.left) || solve(head.next, root.right);
    }
}

// Way - II (BFS)
class Solution
{
    public boolean isSubPath(ListNode head, TreeNode root)
    {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty())
        {
            TreeNode front = q.poll();
            if (front.val == head.val && solve(head, front))
                return true;
            if (front.left != null)
                q.add(front.left);
            if (front.right != null)
                q.add(front.right);
        }
        return false;
    }

    public boolean solve(ListNode head, TreeNode root)
    {
        if (head == null)
            return true;
        if (root == null || root.val != head.val)
            return false;
        return solve(head.next, root.left) || solve(head.next, root.right);
    }
}