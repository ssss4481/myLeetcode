#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef std::pair<int, long long> RoomAndEnd;

class Solution 
{
public:
    int mostBooked(int n, std::vector<std::vector<int>>& meetings)
    {   
        std::vector<int> meetCount(n, 0);

        auto meetCmp = [](const std::vector<int>& m1, const std::vector<int>& m2)
        {
            return m1[0] < m2[0];
        };
        std::sort(meetings.begin(), meetings.end(), meetCmp);

        auto PQCmp = [](const RoomAndEnd& rae1, const RoomAndEnd rae2)
        {
            if(rae1.second == rae2.second)
            {
                return rae1.first > rae2.first;
            }
            return rae1.second > rae2.second;
        };
        std::priority_queue<RoomAndEnd, std::vector<RoomAndEnd>, decltype(PQCmp)> PQOfRoomAndEnd(PQCmp);
        std::priority_queue<int, std::vector<int>, std::greater<int>> validRoom;

        for(int i = 0; i < n; ++i)
        {
            validRoom.push(i);
        }

        for(auto& meet: meetings)
        {  
            int nextMeetStart = meet[0];
            int nextMeetEnd = meet[1];  
            int meetRoom;

            if(!PQOfRoomAndEnd.empty() && PQOfRoomAndEnd.top().second <= nextMeetStart)
            {
                while(!PQOfRoomAndEnd.empty() && PQOfRoomAndEnd.top().second <= nextMeetStart)
                {
                    int newValidRoom = PQOfRoomAndEnd.top().first;
                    validRoom.push(newValidRoom);
                    PQOfRoomAndEnd.pop();
                }
            }

            if(!validRoom.empty())
            {
                meetRoom = validRoom.top();
                PQOfRoomAndEnd.push({meetRoom, nextMeetEnd});
                validRoom.pop();
            }            
            else
            {
                meetRoom = PQOfRoomAndEnd.top().first;
                long long previousEnd = PQOfRoomAndEnd.top().second;
                PQOfRoomAndEnd.pop();
                PQOfRoomAndEnd.push({meetRoom, previousEnd+nextMeetEnd-nextMeetStart});
            }
            ++meetCount[meetRoom];
        }

        return static_cast<int>(std::max_element(meetCount.begin(), meetCount.end())-meetCount.begin());
    }
};