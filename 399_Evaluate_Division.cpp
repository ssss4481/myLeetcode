#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution 
{
private:
    unordered_map<string, unordered_map<string, double>> map;
    unordered_map<string, bool> visit;
    double ansOfDFS;

public:
    void ansOfDFSInit()
    {
        this->ansOfDFS = -1.0;
    }

    void visitInit()
    {
        for(auto& obj: this->visit)
        {
            obj.second = false;
        }        
    }

    void DFS(string current, const string& target, double currentValue)
    {
        if(this->visit[current])
            return;
        if(current == target)
        {
            this->ansOfDFS = currentValue;
            return;
        }

        this->visit[current] = true;

        for(auto& successor: map[current])
        {
            DFS(successor.first, target, currentValue*successor.second);
            if(this->ansOfDFS != -1.0)
                return;
        }
    }

    void insertWrapper(string& a, string& b, double value)
    {
            if(this->map.count(a) == 0)
            {
                unordered_map<string, double> innerMap = {{b, value}};
                this->map.insert({a, std::move(innerMap)});
            }
            else
            {
                this->map[a].insert({b, value});
            }       
    }


    void mapGenerator(vector<vector<string>>& equations, vector<double>& values)
    {
        for(int i = 0; i < values.size(); ++i)
        {
            this->insertWrapper(equations[i][0], equations[i][1], values[i]);
            this->insertWrapper(equations[i][1], equations[i][0], 1/values[i]);
            this->visit.insert({equations[i][0], false});
            this->visit.insert({equations[i][1], false});
        }        
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        vector<double> ret;
        this->mapGenerator(equations, values);

        for(auto& query: queries)
        {
            this->ansOfDFSInit();
            if(this->visit.count(query[0]) == 1 && this->visit.count(query[1]) == 1)
            {
                this->visitInit();
                this->DFS(query[0], query[1], 1.0);
            }
            ret.push_back(this->ansOfDFS);
        }
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
