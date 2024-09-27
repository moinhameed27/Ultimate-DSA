// Leetcode : https://leetcode.com/problems/my-calendar-i/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// Way - I (Vector of pair)
class MyCalendar
{
    vector<pair<int, int>> calendar;

public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        for (auto [s, e] : calendar)
        {
            if (start < e && end > s)
                return false;
        }
        calendar.push_back({start, end});
        return true;
    }
};

// Way - II (Map)
class MyCalendar
{
    unordered_map<int, int> calendar;

public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        for (auto it : calendar)
        {
            if (start < it.second && end > it.first)
                return false;
        }
        calendar[start] = end;
        return true;
    }
};

// [Java]-----------------------------------------------------------------------------------------------------------------------
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
// Way - I (ArrayList of int[])
class MyCalendar
{
    List<int[]> calendar;

    public MyCalendar()
    {
        calendar = new ArrayList<>();
    }

    public boolean book(int start, int end)
    {
        for (int[] interval : calendar)
        {
            if (start < interval[1] && end > interval[0])
                return false;
        }
        calendar.add(new int[] {start, end});
        return true;
    }
}

// Way - II (Map)
class MyCalendar
{
    Map<Integer, Integer> calendar;

    public MyCalendar()
    {
        calendar = new HashMap<>();
    }

    public boolean book(int start, int end)
    {
        for (Map.Entry<Integer, Integer> entry : calendar.entrySet())
        {
            if (start < entry.getValue() && end > entry.getKey())
                return false;
        }
        calendar.put(start, end);
        return true;
    }
}
