#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    static const int oneByte = 0b10000000;
    static const int andWithOneByte = 0b00000000;
    static const int twoByte = 0b11100000;
    static const int andWithTwoByte = 0b11000000;
    static const int threeByte = 0b11110000;
    static const int andWithThreeByte = 0b11100000;
    static const int fourByte = 0b11111000;
    static const int andWithFourByte = 0b11110000;
    static const int follow = 0b11000000;
    static const int andWithFollow = 0b10000000;

    static bool checkTest(const int input, const int target, const int ans)
    {
        return (input & target) == ans;
    }

    static int checkByte(const int input)
    {
        if(checkTest(input, oneByte, andWithOneByte))
        {
            return 0;
        }

        if(checkTest(input, twoByte, andWithTwoByte))
        {
            return 1;
        }

        if(checkTest(input, threeByte, andWithThreeByte))
        {
            return 2;
        }

        if(checkTest(input, fourByte, andWithFourByte))
        {
            return 3;
        }

        return -1;
    }

    bool validUtf8(vector<int>& data) 
    {
        int counter = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            if(counter > 0)
            {
                if(!checkTest(data[i], follow, andWithFollow))
                    return false;
                --counter;
            }
            else
            {
                counter = checkByte(data[i]);
                if(counter < 0)
                    return false;
            }
        }

        return (counter == 0);
    }
};



int main()
{    
    return 0;
}
