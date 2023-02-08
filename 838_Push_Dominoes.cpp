#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    string pushDominoes(string dominoes) {
        string temp;
        do
        {
            temp = dominoes;
            
            for(int i = 0; i < dominoes.length(); ++i)
            {
                if(dominoes[i] == '.')
                {
                    bool left = false;
                    bool right = false;
                    if(i-1 >= 0 && temp[i-1] == 'R')
                        left = true;
                    if(i+1 < dominoes.length() && temp[i+1] == 'L')
                        right = true;

                    if(left && !right)
                        dominoes[i] = 'R';
                    else if(!left && right)
                        dominoes[i] = 'L';

                    //cout << left << right << dominoes[i] << "\n";
                }
            }
        }while(temp != dominoes);        
        return dominoes;
    }
};




class Solution2 {
public:
    string pushDominoes(string dominoes) {
        string temp;
        do
        {
            temp = dominoes;
            
            for(int i = 0; i < dominoes.length(); ++i)
            {
                if(dominoes[i] == '.')
                {
                    bool left = false;
                    bool right = false;
                    if(i-1 >= 0 && temp[i-1] == 'R')
                        left = true;
                    if(i+1 < dominoes.length() && temp[i+1] == 'L')
                        right = true;

                    if(left && !right)
                        dominoes[i] = 'R';
                    else if(!left && right)
                        dominoes[i] = 'L';

                    //cout << left << right << dominoes[i] << "\n";
                }
            }
        }while(temp != dominoes);        
        return dominoes;
    }
};


int main()
{
    Solution a = Solution();

    cout << a.pushDominoes("R.") << "\n";



    return 0;

}