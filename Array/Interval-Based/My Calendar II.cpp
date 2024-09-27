// Leetcode : https://leetcode.com/problems/my-calendar-ii/description/

// [C++]-----------------------------------------------------------------------------------------------------------------------
/* 
1. First, we check if the booking overlaps with any of the double bookings. If it does, we return false.
2. If it doesn't, we check if it overlaps with any of the single bookings. If it does, we add the overlapping interval to the 
   double bookings.
3. Finally, we add the booking to the single bookings.
*/

class MyCalendarTwo
{
    vector<pair<int, int>> allBookings, doubleBookings;
    bool checkOverlapping(int start1, int end1, int start2, int end2)
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlapping(int start1, int end1, int start2, int end2)
    {
        return {max(start1, start2), min(end1, end2)};
    }

public:
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        for (auto [s, e] : doubleBookings)
        {
            if (checkOverlapping(start, end, s, e))
                return false;
        }

        for (auto [s, e] : allBookings)
        {
            if (checkOverlapping(start, end, s, e))
                doubleBookings.push_back(findOverlapping(start, end, s, e));
        }
        allBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// [Java]-----------------------------------------------------------------------------------------------------------------------
/*
1. First, we check if the booking overlaps with any of the double bookings. If it does, we return false.
2. If it doesn't, we check if it overlaps with any of the single bookings. If it does, we add the overlapping interval to the 
   double bookings.
3. Finally, we add the booking to the single bookings.
*/
class MyCalendarTwo 
{
    List<int[]> allBookings = new ArrayList<>(), doubleBookings = new ArrayList<>();
    public MyCalendarTwo() {}
    
    public boolean book(int start, int end) 
    {
        for (int[] interval : doubleBookings)
        {
            if (Math.max(start, interval[0]) < Math.min(end, interval[1]))
                return false;
        }
        
        for (int[] interval : allBookings)
        {
            if (Math.max(start, interval[0]) < Math.min(end, interval[1]))
                doubleBookings.add(new int[]{Math.max(start, interval[0]), Math.min(end, interval[1])});
        }
        allBookings.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */