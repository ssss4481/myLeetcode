#include <vector>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) 
    {
        int sti = 0;
        int sai = 0;
        std::vector<int> Q;

        while(true)
        {
            while (sti < students.size())
            {
                if(students[sti] == sandwiches[sai])
                {
                    ++sai;
                }
                else
                {
                    Q.push_back(students[sti]);
                }
                ++sti;
            }
            if(Q.size() == students.size())
            {
                break;
            }
            sti = 0;
            students.swap(Q);
            Q.clear();
        }

        return static_cast<int> (sandwiches.size()-sai);
    }
};