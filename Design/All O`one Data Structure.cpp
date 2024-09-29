// Leetcode : https://leetcode.com/problems/all-oone-data-structure/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

/*
1. A hashmap to store the key and its frequency.
2. Two Pairs maxKey and minKey to store the key with maximum and minimum frequency.
*/

class AllOne
{
    unordered_map<string, int> mp;
    pair<string, int> maxKey, minKey;

    void updateMinKey()
    {
        minKey.second = INT_MAX;
        for (auto &it : mp)
        {
            if (it.second < minKey.second)
                minKey.first = it.first, minKey.second = it.second;
        }
    }

    void updateMaxMinKey()
    {
        maxKey.second = INT_MIN, minKey.second = INT_MAX;
        for (auto &it : mp)
        {
            if (it.second >= maxKey.second)
                maxKey.first = it.first, maxKey.second = it.second;

            if (it.second <= minKey.second)
                minKey.first = it.first, minKey.second = it.second;
        }
    }

public:
    AllOne()
    {
        maxKey.second = INT_MIN;
        minKey.second = INT_MAX;
    }

    /* Whenever a key is incremented, increase it's frequency and update the minKey. */
    void inc(string key)
    {
        mp[key]++;
        if (mp[key] > maxKey.second)
            maxKey.first = key, maxKey.second = mp[key];
        updateMinKey();
    }

    /*
    Whenever a key is decremented:
    1. If the frequency of the key is greater than 1, decrement it's frequency and update the minKey.
    2. If the frequency of the key is 1, erase the key from the map.
    3. If the map is not empty, and current key is either maxKey or minKey, update the maxKey and minKey.
    4. If the map is empty, reset the maxKey and minKey.
    */
    void dec(string key)
    {
        if (mp[key] >= 2)
        {
            mp[key]--;
            if (mp[key] < minKey.second)
                minKey.first = key, minKey.second = mp[key];
        }
        else
            mp.erase(key);
        if (mp.size() > 0)
        {
            if (key == maxKey.first || key == minKey.first)
                updateMaxMinKey();
        }
        else
        {
            maxKey.first = "", minKey.first = "";
            maxKey.second = INT_MIN, minKey.second = INT_MAX;
        }
    }

    string getMaxKey() { return maxKey.first; }
    string getMinKey() { return minKey.first; }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
class AllOne
{
    Map<String, Integer> mp;
    String maxKey, minKey;
    int maxValue, minValue;

    public AllOne()
    {
        mp = new HashMap<>();
        maxKey = "";
        minKey = "";
        maxValue = Integer.MIN_VALUE;
        minValue = Integer.MAX_VALUE;
    }

    private void updateMinKey()
    {
        minKey = "";
        minValue = Integer.MAX_VALUE;
        for (Map.Entry<String, Integer> entry : mp.entrySet())
        {
            if (entry.getValue() < minValue)
            {
                minKey = entry.getKey();
                minValue = entry.getValue();
            }
        }
    }

    private void updateMaxMinKey()
    {
        maxKey = "";
        minKey = "";
        maxValue = Integer.MIN_VALUE;
        minValue = Integer.MAX_VALUE;

        for (Map.Entry<String, Integer> entry : mp.entrySet())
        {
            if (entry.getValue() >= maxValue)
            {
                maxKey = entry.getKey();
                maxValue = entry.getValue();
            }

            if (entry.getValue() <= minValue)
            {
                minKey = entry.getKey();
                minValue = entry.getValue();
            }
        }
    }

    public void inc(String key)
    {
        mp.put(key, mp.getOrDefault(key, 0) + 1);

        if (mp.get(key) > maxValue)
        {
            maxKey = key;
            maxValue = mp.get(key);
        }
        updateMinKey();
    }

    public void dec(String key)
    {
        if (mp.get(key) >= 2)
        {
            mp.put(key, mp.get(key) - 1);

            if (mp.get(key) < minValue)
            {
                minKey = key;
                minValue = mp.get(key);
            }
        }
        else
            mp.remove(key);

        if (mp.size() > 0)
        {
            if (key.equals(maxKey) || key.equals(minKey))
                updateMaxMinKey();
        }
        else
        {
            maxKey = "";
            minKey = "";
            maxValue = Integer.MIN_VALUE;
            minValue = Integer.MAX_VALUE;
        }
    }

    public String getMaxKey() { return maxKey; }

    public String getMinKey() { return minKey; }
}
