#include <vector>
#define BIG 1
#define MEDIUM 2
#define SMALL 3

using namespace std;

class ParkingSystem 
{
private:
    int limit[4];
    vector<int> car;

public:
    ParkingSystem(int big, int medium, int small) 
    {
        this->limit[BIG] = big;
        this->limit[MEDIUM] = medium;
        this->limit[SMALL] = small;
        this->car = vector<int> (4, 0);
    }
    
    bool addCar(int carType) 
    {
        if(this->car[carType] >= this->limit[carType])
            return false;
        ++this->car[carType];
        return true;        
    }
};
