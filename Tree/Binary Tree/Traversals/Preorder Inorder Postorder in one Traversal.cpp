/* struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
}; */

/*
1. Preorder: Root, Left, Right
2. Inorder: Left, Root, Right
3. Postorder: Left, Right, Root
4. Take a stack, store the node and its state in the stack.
5. State 1: Preorder, State 2: Inorder, State 3: Postorder
6. If state is 1, push the node in preorder vector and move to left child (if exists).
7. If state is 2, push the node in inorder vector and move to right child (if exists).
8. If state is 3, push the node in postorder vector.
*/

// [C++]-----------------------------------------------------------------------------------------------------------------------
vector<vector<int>> preInPostTraversal(Node *root)
{
    vector<int> pre, in, post;

    if (root == NULL)
        return {};

    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }

        else
            post.push_back(it.first->data);
    }

    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

// [Java]-----------------------------------------------------------------------------------------------------------------------
public List<List<Integer>> preInPostTraversal(Node root)
{
    List<Integer> pre = new ArrayList<>();
    List<Integer> in = new ArrayList<>();
    List<Integer> post = new ArrayList<>();

    if (root == null)
        return new ArrayList<>();

    Stack<Pair<Node, Integer>> st = new Stack<>();
    st.push(new Pair<>(root, 1));

    while (!st.isEmpty())
    {
        Pair<Node, Integer> it = st.pop();

        if (it.getValue() == 1)
        {
            pre.add(it.getKey().data);
            it.setValue(2);
            st.push(it);
            if (it.getKey().left != null)
                st.push(new Pair<>(it.getKey().left, 1));
        }

        else if (it.getValue() == 2)
        {
            in.add(it.getKey().data);
            it.setValue(3);
            st.push(it);
            if (it.getKey().right != null)
                st.push(new Pair<>(it.getKey().right, 1));
        }

        else
            post.add(it.getKey().data);
    }

    List<List<Integer>> result = new ArrayList<>();
    result.add(pre);
    result.add(in);
    result.add(post);
    return result;
}