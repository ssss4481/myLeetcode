#include <vector>
#include <numeric>
#include <iostream>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> ans;

        for(auto& asteroid: asteroids){
            if(asteroid > 0 || ans.empty() || ans.back() < 0){
                ans.push_back(asteroid);
            }else{               
                while(!ans.empty() && ans.back() > 0 && ans.back() < -asteroid){
                    ans.pop_back();
                }
                if(ans.empty() || ans.back() < 0){
                    ans.push_back(asteroid);
                }else if(ans.back() == -asteroid){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ret;

        for(int& asteroid: asteroids)
        {
            if(ret.size() == 0 || asteroid > 0)
            {
                ret.push_back(asteroid);
            }
            else if(ret.back() > 0 && asteroid < 0)
            {
                while(ret.size() > 0 && ret.back() > 0 && ret.back() < -asteroid)
                {
                    ret.pop_back();
                }

                if(ret.size() == 0 || ret.back() < 0)
                {
                    ret.push_back(asteroid);
                }
                else if(ret.size() > 0 && ret.back() <= -asteroid)
                {
                    bool push = (ret.back() != -asteroid);
                    ret.pop_back();
                    if(push)
                    {
                        ret.push_back(asteroid);
                    }
                }
            }
            else
            {
                ret.push_back(asteroid);
            }
        }      

        return ret;        
    }
};



class Solution1 
{
public:
    void printVec(vector<int>& v)
    {
        for(int& n: v)
        {
            cout << n << ' ';
        }
        cout << '\n';
    }

    int collide(int left, int right)
    {
        if(left > -right)
        {
            return left;
        }
        else if(left < -right)
        {
            return right;
        }
        return 0;
    }

    void nextState(vector<int>& asteroids, bool& collision)
    {
        vector<int> next;
        const int n = asteroids.size();
        collision = false;
        for(int i = 0; i < n; ++i)
        {
            int j = i+1;
            if(j == n)
            {
                next.push_back(asteroids[i]);
            }
            else if(asteroids[i] > 0 && asteroids[j] < 0)
            {
                collision = true;
                int result = collide(asteroids[i], asteroids[j]);
                if(result != 0)
                {
                    next.push_back(result);
                }
                ++i;
            }
            else
            {
                next.push_back(asteroids[i]);
            } 
        }
        //printVec(next);

        asteroids = next;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        bool collision = true;
        while(collision)
        {
            nextState(asteroids, collision);
        }
        return asteroids;        
    }
};