// Leetcode : https://leetcode.com/problems/sentence-similarity-iii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Two Pointers + Vector + StringStream)
class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // If sentence1 is smaller than sentence2, then swap them
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        int m = sentence1.size(), n = sentence2.size();

        vector<string> v1, v2;

        // Split the sentence1 and sentence2 into words
        stringstream ss1(sentence1);
        string token;
        while (ss1 >> token)
            v1.push_back(token);

        stringstream ss2(sentence2);
        while (ss2 >> token)
            v2.push_back(token);

        int a = v1.size(), b = v2.size();
        int i = 0, j = a - 1;
        int k = 0, l = b - 1;

        // Skip the common words from the start
        while (i < a && k < b && v1[i] == v2[k])
            i++, k++;

        // Skip the common words from the end
        while (k <= l && v1[j] == v2[l])
            j--, l--;

        // If sentence2 is all covered, then return true
        return l < k;
    }
};

// Way - II (Two Pointers + Deque + StringStream)
class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        int m = sentence1.size(), n = sentence2.size();
        deque<string> deq1, deq2;
        stringstream ss1(sentence1);
        string token;
        while (ss1 >> token)
            deq1.push_back(token);

        stringstream ss2(sentence2);
        while (ss2 >> token)
            deq2.push_back(token);

        while (!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front())
            deq1.pop_front(), deq2.pop_front();

        while (!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back())
            deq1.pop_back(), deq2.pop_back();

        return deq2.empty();
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------------
// Way - I (Two Pointers + String[] + String.split())
class Solution 
{
    public boolean areSentencesSimilar(String sentence1, String sentence2) 
    {
        String[] s1 = sentence1.split(" ");
        String[] s2 = sentence2.split(" ");
        int m = s1.length, n = s2.length;
        int i = 0, j = m - 1;
        int k = 0, l = n - 1;
        
        while (i < m && k < n && s1[i].equals(s2[k]))
        {
            i++;
            k++;
        }
        
        while (k <= l && s1[j].equals(s2[l]))
        {
            j--;
            l--;
        }
        
        return l < k;   
    }
}

// Way - II (Two Pointers + Deque + String[] + String.split())
class Solution 
{
    public boolean areSentencesSimilar(String sentence1, String sentence2) 
    {
        String[] s1 = sentence1.split(" ");
        String[] s2 = sentence2.split(" ");
        int m = s1.length, n = s2.length;
        Deque<String> deq1 = new LinkedList<>();
        Deque<String> deq2 = new LinkedList<>();
        
        for (String s : s1)
            deq1.add(s);
        
        for (String s : s2)
            deq2.add(s);
        
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekFirst().equals(deq2.peekFirst()))
        {
            deq1.pollFirst();
            deq2.pollFirst();
        }
        
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekLast().equals(deq2.peekLast()))
        {
            deq1.pollLast();
            deq2.pollLast();
        }
        
        return deq2.isEmpty();
    }
}