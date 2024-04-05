#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <numeric>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class DSU
{
private:
    std::vector<std::vector<std::string>> accounts;
    std::vector<int> parents;
    std::vector<int> sizes;
    std::vector<std::string> names;
    std::unordered_map<std::string, int> mailToParent;

public:

    DSU(std::vector<std::vector<std::string>>&& accounts)
    {
        this->accounts = std::move(accounts);
        const int n = this->accounts.size();
        this->parents = std::vector<int> (n);
        this->names = std::vector<std::string> (n);
        this->sizes = std::vector<int>(n, 0);
        std::iota(this->parents.begin(), this->parents.end(), 0);
    }

    void combine()
    {
        const int n = this->accounts.size();
        for(int i = 0; i < n; ++i)
        {
            const auto& info = accounts[i];
            this->names[i] = info[0];
            int localSize = info.size()-1;
            bool needUnion = false;
            std::unordered_set<int> unionTargets;
            for(int j = 1; j < info.size(); ++j)
            {
                const auto& mail = info[j];
                if(this->mailToParent.count(mail) == 1)
                {
                    --localSize;
                    needUnion = true;
                    unionTargets.insert(findWithPathComression(this->mailToParent[mail]));                    
                }
                else
                {
                    this->mailToParent[mail] = i;
                }
            }
            this->sizes[i] += localSize;
            unionTargets.insert(i);
            while(unionTargets.size() > 1)
            {
                auto it = unionTargets.begin();
                int target1 = this->findWithPathComression(*(it));
                ++it;
                int target2 = this->findWithPathComression(*(it));
                unionTargets.erase(this->unionBySize(target1, target2));
            }
        }
    }

    int unionBySize(int i, int j)
    {
        if(this->sizes[i] >= this->sizes[j])
        {
            std::swap(i, j);
        }
        this->parents[i] = j;
        this->sizes[j] += this->sizes[i];
        return i;//be child
    };

    int findWithPathComression(int i)
    {
        if(i == this->parents[i])
        {
            return i;
        }
        this->parents[i] = this->findWithPathComression(this->parents[i]);
        return this->parents[i];
    };

    std::vector<std::vector<std::string>> output()
    {
        std::unordered_map<int, std::vector<std::string>> resultSet;

        for(auto& p: this->mailToParent)
        {
            auto& mail = p.first;
            int parent = this->findWithPathComression(this->parents[p.second]);

            if(resultSet.count(parent) == 0)
            {
                resultSet[parent] = {this->names[parent]};
            }
            resultSet[parent].push_back(mail);
        }
        
        std::vector<std::vector<std::string>> ret;
        for(auto& p: resultSet)
        {
            ret.push_back(p.second);
            std::sort(ret.back().begin()+1, ret.back().end());
        }
        return ret;
    }
    
};


class Solution
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) 
    {
        auto dsu = DSU(std::move(accounts));
        dsu.combine();
        return dsu.output();
    }
};