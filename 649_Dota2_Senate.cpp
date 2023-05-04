#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        int activeR = 0;
        int activeD = 0;
        for(int i = 0; i < senate.size(); ++i)
        {
            if(senate[i] == 'R')
                ++activeR;
            else
                ++activeD;
        }

        vector<bool> active(senate.size(), true);
        int banQuotaofR = 0;
        int banQuotaofD = 0;

        while(activeR > 0 && activeD > 0)
        {
            for(int i = 0; i < senate.size(); ++i)
            {
                if(active[i])
                {
                    if(senate[i] == 'R')
                    {
                        if(banQuotaofR > 0)
                        {
                            active[i] = false;
                            --activeR;
                            --banQuotaofR;
                        }
                        else
                        {
                            ++banQuotaofD;
                        }                                    
                    }

                    if(senate[i] == 'D')
                    {
                        if(banQuotaofD > 0)
                        {
                            active[i] = false;
                            --activeD;
                            --banQuotaofD;
                        }
                        else
                        {
                            ++banQuotaofR;
                        }                                    
                    }                    
                }
            }            

        }

        return activeR > 0 ? "Radiant" : "Dire";     
    }
};