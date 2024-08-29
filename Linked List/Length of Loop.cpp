// GFG : https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// [C++]-----------------------------------------------------------------------------------------------------------------------
/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
    
// Way - I (Brute Force [Map])
class Solution
{
public:
    int countNodesinLoop(struct Node *head)
    {
        int count = 0;
        // Map to store the Node and it's place
        unordered_map<Node *, int> mp;
        Node *temp = head;
        while (temp)
        {
            count++;
            // If node is found again, means it's the first node of cycle
            if (mp.find(temp) != mp.end())
                return count - mp[temp];
            mp[temp] = count;
            temp = temp->next;
        }
        // If there is no cycle, return 0
        return 0;
    }
};

// Way - II (Two Pointers)
class Solution
{
public:
    int countNodesinLoop(struct Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            // If there's a cycle, keep slow at the meeting point
            if (slow == fast)
            {
                int count = 1;
                fast = fast->next;
                // Keep moving the fast one step until it meets slow
                while (slow != fast)
                {
                    fast = fast->next;
                    count++;
                }
                // The length of cycle will be counted as the meeting point will come again after some n count
                return count;
            }
        }
        // If there's no cycle
        return 0;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/*
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/

// Way - I (Brute Force [Map])
class Solution
{
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head)
    {
        int count = 0;
        // Map to store the Node and it's place
        HashMap<Node, Integer> mp = new HashMap<>();
        Node temp = head;
        while (temp != null)
        {
            count++;
            // If node is found again, means it's the first node of cycle
            if (mp.containsKey(temp))
                return count - mp.get(temp);
            mp.put(temp, count);
            temp = temp.next;
        }
        // If there is no cycle, return 0
        return 0;
    }
}

// Way - II (Two Pointers)
class Solution
{
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head)
    {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            // If there's a cycle, keep slow at the meeting point
            if (slow == fast)
            {
                int count = 1;
                fast = fast.next;
                // Keep moving the fast one step until it meets slow
                while (slow != fast)
                {
                    fast = fast.next;
                    count++;
                }
                // The length of cycle will be counted as the meeting point will come again after some n count
                return count;
            }
        }
        // If there's no cycle
        return 0;
    }
}