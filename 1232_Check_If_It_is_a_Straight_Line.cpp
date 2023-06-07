#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>
using namespace std;


class Solution 
{
private:
    const double inf = std::numeric_limits<double>::infinity();
    double standardSlope = 0;
    bool infSlope = false;

public:

    bool sameSlope(double& slopeSample)
    {
        if(this->infSlope)        
            return abs(slopeSample) == this->inf;
        
        return this->standardSlope == slopeSample;       
    }

    double calculcateSlope(vector<int>& p1, vector<int>& p2)
    {        
        return double(p1.at(1)-p2.at(1)) / (p1.at(0)-p2.at(0));
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        const int n = coordinates.size();
        this->standardSlope = calculcateSlope(coordinates.at(0), coordinates.at(1));

        if(abs(this->standardSlope) == this->inf)
            this->infSlope = true;    

        for(int i = 1; i < n-1; ++i)
        {            
            double m2 = calculcateSlope(coordinates.at(i), coordinates.at(i+1));
            if(!this->sameSlope(m2))
                return false;
        }   
            
        return true;        
    }
};



class Solution_
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        const int n = coordinates.size();
        const double inf = std::numeric_limits<double>::infinity();
        double m1 = double(coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0]);
        if(abs(m1) != inf)
        {
            for(int i = 1; i < n-1; ++i)
            {            
                double m2 = double(coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]);
                if(m1 != m2)
                    return false;
            }
        }
        else
        {
            for(int i = 1; i < n-1; ++i)
            {            
                double m2 = double(coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]);
                if(inf != abs(m2))
                    return false;
            }          
        }
            
        return true;        
    }
};


int main(int argc, char const *argv[])
{
    double a = std::numeric_limits<double>::infinity();
    cout << a;
    return 0;
}
