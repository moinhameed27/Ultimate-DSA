// Leetcode : https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
class CustomStack
{
    vector<int> stack;
    int top, size;

public:
    CustomStack(int maxSize)
    {
        stack.resize(maxSize);
        top = 0, size = maxSize;
    }

    void push(int x)
    {
        if (top < size)
            stack[top++] = x;
    }

    int pop()
    {
        return (top != 0) ? stack[--top] : -1;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < min(k, size); i++)
            stack[i] += val;
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// [Java]-----------------------------------------------------------------------------------------------------------------------
class CustomStack 
{
    private int [] stack;
    private int top, size;

    public CustomStack(int maxSize) 
    {
        stack = new int[maxSize];
        size = maxSize;
        top = 0;
    }
    
    public void push(int x) 
    {
        if(top < size)
            stack[top++] = x;
    }
    
    public int pop() 
    {
        return (top != 0) ? stack[--top] : -1;
    }
    
    public void increment(int k, int val) 
    {
        for(int i = 0; i < Math.min(k, size); i++)
            stack[i] += val;
    }
}
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */