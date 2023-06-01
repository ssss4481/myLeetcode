#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, int> startStationAndCheckinTime;
typedef pair<int, int> totalTravelTimeAndCustomerCounter;

class UndergroundSystem 
{
private:
    unordered_map<int, startStationAndCheckinTime> checkinIDAndInfo;
    //id to startStation and check in time
    unordered_map<string, unordered_map<string, totalTravelTimeAndCustomerCounter>> timeRecord;
    //(startStation) to (endStation) to (total time and counter). Changed when checkout happens.
public:
    UndergroundSystem() 
    {        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        this->checkinIDAndInfo[id] = make_pair(stationName, t);        
    }
    
    void checkOut(int id, string stationName, int t) 
    {   
        startStationAndCheckinTime& info = this->checkinIDAndInfo[id];

        if(this->timeRecord.count(info.first) == 0)        
            this->timeRecord[info.first] = unordered_map<string, totalTravelTimeAndCustomerCounter>();        

        if(this->timeRecord[info.first].count(stationName) == 0)                
            this->timeRecord[info.first][stationName] = make_pair(0, 0);        

        this->timeRecord[info.first][stationName].first += (t - info.second);//accumulation of travel time
        ++this->timeRecord[info.first][stationName].second;//++counter

        this->checkinIDAndInfo.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        return double(this->timeRecord[startStation][endStation].first) / this->timeRecord[startStation][endStation].second;
    }
};






int main(int argc, char const *argv[])
{
    unordered_map<int, int> test;
    test[1] = 2;
    cout << test[1] << "\n";
    ++test[1];
    cout << test[1] << "\n";  

    totalTravelTimeAndCustomerCounter a = make_pair(0, 0);
    ++a.second;
    cout << a.second << "\n";

   
    return 0;
}



