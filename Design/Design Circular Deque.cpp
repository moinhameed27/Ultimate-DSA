// Leetcode : https://leetcode.com/problems/design-circular-deque/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// Way - I (Using Vector)
class MyCircularDeque
{
    vector<int> Deque;
    int front, back, size, k;

public:
    MyCircularDeque(int k) : front(0), back(k - 1), size(0)
    {
        Deque.resize(k);
        this->k = k;
    }

    bool insertFront(int value)
    {
        if (size == k)
            return false;
        front = (front == 0) ? k - 1 : front - 1;
        Deque[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == k)
            return false;
        back = (back == k - 1) ? 0 : back + 1;
        Deque[back] = value;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (size == 0)
            return false;
        front = (front == k - 1) ? 0 : front + 1;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
        back = (back == 0) ? k - 1 : back - 1;
        size--;
        return true;
    }

    int getFront()
    {
        return (size == 0) ? -1 : Deque[front];
    }

    int getRear()
    {
        return (size == 0) ? -1 : Deque[back];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == k;
    }
};

// Way - II (Using List)
// Doubly Linked List Node
struct Node
{
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

class MyCircularDeque
{
    Node *front, *back;
    int size, k;

public:
    MyCircularDeque(int k) : size(0), k(k) { front = back = nullptr; }

    bool insertFront(int value)
    {
        if (size == k)
            return false;
        Node *newNode = new Node(value);
        if (size == 0)
        {
            front = back = newNode;
            front->next = front->prev = front; 
        }
        else
        {
            newNode->prev = back, newNode->next = front;
            front->prev = newNode, back->next = newNode;
            front = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == k)
            return false;
        Node *newNode = new Node(value);
        if (size == 0)
        {
            front = back = newNode;
            front->next = front->prev = front;
        }
        else
        {
            newNode->next = front, newNode->prev = back;
            front->prev = newNode, back->next = newNode;
            back = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (size == 0)
            return false;
        Node *toDelete = front;
        if (size == 1)
            front = back = nullptr;
        else
        {
            front = front->next;
            back->next = front, front->prev = back;
        }
        delete toDelete;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
        Node *toDelete = back;
        if (size == 1)
            front = back = nullptr;
        else
        {
            back = back->prev;
            back->next = front, front->prev = back;
        }
        delete toDelete;
        size--;
        return true;
    }

    int getFront() { return (size == 0) ? -1 : front->data; }

    int getRear() { return (size == 0) ? -1 : back->data; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == k; }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
// Way - I (Using Array)
class MyCircularDeque
{
    int[] deque;
    int front, back, size, k;

    public MyCircularDeque(int k)
    {
        deque = new int[k];
        front = 0;
        back = k - 1;
        size = 0;
        this.k = k;
    }

    public boolean insertFront(int value)
    {
        if (size == k)
            return false;
        front = (front == 0) ? k - 1 : front - 1;
        deque[front] = value;
        size++;
        return true;
    }

    public boolean insertLast(int value)
    {
        if (size == k)
            return false;
        back = (back == k - 1) ? 0 : back + 1;
        deque[back] = value;
        size++;
        return true;
    }

    public boolean deleteFront()
    {
        if (size == 0)
            return false;
        front = (front == k - 1) ? 0 : front + 1;
        size--;
        return true;
    }

    public boolean deleteLast()
    {
        if (size == 0)
            return false;
        back = (back == 0) ? k - 1 : back - 1;
        size--;
        return true;
    }

    public int getFront() { return (size == 0) ? -1 : deque[front]; }

    public int getRear() { return (size == 0) ? -1 : deque[back]; }

    public boolean isEmpty() { return size == 0; }

    public boolean isFull() { return size == k; }
}

// Way - II (Using List)
// Doubly Linked List Node
class Node
{
    int data;
    Node next, prev;

    Node()
    {
        data = 0;
        next = prev = null;
    }

    Node(int x)
    {
        data = x;
        next = prev = null;
    }

    Node(int x, Node next, Node prev)
    {
        data = x;
        this.next = next;
        this.prev = prev;
    }
}

class MyCircularDeque
{
    Node front, back;
    int size, k;

    public MyCircularDeque(int k)
    {
        size = 0;
        this.k = k;
        front = back = null;
    }

    public boolean insertFront(int value)
    {
        if (size == k)
            return false;
        Node newNode = new Node(value);
        if (size == 0)
        {
            front = back = newNode;
            front.next = front.prev = front;
        }
        else
        {
            newNode.prev = back;
            newNode.next = front;
            front.prev = newNode;
            back.next = newNode;
            front = newNode;
        }
        size++;
        return true;
    }

    public boolean insertLast(int value)
    {
        if (size == k)
            return false;
        Node newNode = new Node(value);
        if (size == 0)
        {
            front = back = newNode;
            front.next = front.prev = front;
        }
        else
        {
            newNode.next = front;
            newNode.prev = back;
            front.prev = newNode;
            back.next = newNode;
            back = newNode;
        }
        size++;
        return true;
    }

    public boolean deleteFront()
    {
        if (size == 0)
            return false;
        Node toDelete = front;
        if (size == 1)
            front = back = null;
        else
        {
            front = front.next;
            back.next = front;
            front.prev = back;
        }
        size--;
        return true;
    }

    public boolean deleteLast()
    {
        if (size == 0)
            return false;
        Node toDelete = back;
        if (size == 1)
            front = back = null;
        else
        {
            back = back.prev;
            back.next = front;
            front.prev = back;
        }
        size--;
        return true;
    }

    public int getFront() { return (size == 0) ? -1 : front.data; }

    public int getRear() { return (size == 0) ? -1 : back.data; }

    public boolean isEmpty() { return size == 0; }

    public boolean isFull() { return size == k; }
}