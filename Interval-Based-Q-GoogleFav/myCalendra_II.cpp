#include <iostream>
#include <vector>
#include <utility>   // For std::pair
#include <algorithm> // For std::max and std::min
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vySZ_KfjiRU
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/my-calendar-ii
*/
//*Approach-1 : Simle and straight forward
//T.C : O(n)
//S.C : O(n)
class MyCalendarTwo
{
public:
    vector<pair<int, int>> doubleOverlappedRegion;
    vector<pair<int, int>> overallBookings;

    bool checkOverlap(int start1, int end1, int start2, int end2)
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2)
    {
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        // Check if triple booking is being created or not
        for (pair<int, int> region : doubleOverlappedRegion)
        {
            if (checkOverlap(region.first, region.second, start, end))
            {
                return false; // Triple booking created
            }
        }

        // Check if it is creating double bookings
        for (pair<int, int> booking : overallBookings)
        {
            if (checkOverlap(booking.first, booking.second, start, end))
            {
                doubleOverlappedRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
            }
        }

        overallBookings.push_back({start, end});
        return true;
    }
};

int main()
{
    MyCalendarTwo myCalendar;

    // Test cases
    cout << "Booking (10, 20): " << (myCalendar.book(10, 20) ? "Successful" : "Failed") << endl; // Should succeed
    cout << "Booking (15, 25): " << (myCalendar.book(15, 25) ? "Successful" : "Failed") << endl; // Should succeed
    cout << "Booking (20, 30): " << (myCalendar.book(20, 30) ? "Successful" : "Failed") << endl; // Should succeed
    cout << "Booking (5, 15): " << (myCalendar.book(5, 15) ? "Successful" : "Failed") << endl;   // Should succeed
    cout << "Booking (10, 30): " << (myCalendar.book(10, 30) ? "Successful" : "Failed") << endl; // Should fail (triple booking)

    return 0;
}