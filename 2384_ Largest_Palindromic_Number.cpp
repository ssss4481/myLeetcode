#include <iostream>
#include <vector>
#include <string>



void printVec(std::vector<int> &table)
{
    int i = 0;
    for(int &c : table)
    {
        std::cout << i << " " << c << "\n";
        ++i;
    }

    std::cout << "\n";

}

class Solution {
public:
    static string largestPalindromic(string num){
    std::vector<int> table (10, 0);
    std::string output = "";
    std::string empty = "";
    bool flag = true;
    int middle = -1;
    char buf[1];
    //std::vector<bool> Btable (10, false);
    for(char &c : num)
    {
        buf[0] = c;
        ++table[atoi(buf)];
    }


    for(int i = 9; i >= 0; --i)
    {
        if(flag == true && table[i] % 2 == 1)
        {
            flag = false;
            middle = i;
            break;
        }
    }

    bool valid = false;
    //std::cout << "here 1" << std::endl;
    for(int i = 9; i >= 0; --i)
    {

        if(table[i] % 2 == 0)
        {
            for(int j = 0; j < table[i]/2 ; ++j)
            {
                if(i > 0)
                {
                    valid = true;
                }
                output += std::to_string(i);
            }
        }
        else
        {
            for(int j = 0; j < (table[i]-1)/2 ; ++j)
            {
                if(i > 0)
                {
                    valid = true;
                }
                output += std::to_string(i);
            }
        }
    }
    //std::cout << "here 2" << std::endl;
    if(middle >= 0)
    {
        output += std::to_string(middle);
        empty += std::to_string(middle);
    }


    if(output == empty || (valid == false && middle > 0))
    {
        return std::to_string(middle);
    }
    else if(valid == false)
    {
        return std::to_string(0);
    }


    //std::cout << "here 3" << std::endl;
    for(int i = 0; i <= 9; ++i)
    {
        if(table[i] % 2 == 0)
        {
            for(int j = 0; j < table[i]/2 ; ++j)
            {
                output += std::to_string(i);
            }
        }
        else
        {
            for(int j = 0; j < (table[i]-1)/2 ; ++j)
            {
                output += std::to_string(i);
            }
        }
    }
    //std::cout << "here 4" << std::endl;

    return output;


}
};



int main()
{

    std::string num = "444947137";
    std::string ans = Solution::largestPalindromic(num);
    std::cout << ans << "\n";

    return 0;
}