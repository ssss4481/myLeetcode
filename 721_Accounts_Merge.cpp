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

void printer(std::unordered_map<int, std::vector<std::string>>& parentToAccountInfo)
{
    for(auto& P : parentToAccountInfo)
    {
        for(auto& str: P.second)
        {
            std::cout << str << ' ';
        }
        std::cout << '\n';
    }
}
template<typename T>
void printVec(std::vector<T>& vec)
{
    for(T& t:vec)
    {
        std::cout << t << ' ';
    }
    std::cout << '\n';
}

void printSet(std::unordered_set<std::string>& S)
{

    for(auto& str: S)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';
}
#define DONE -1

class DSU
{
private:
    std::vector<int> parents;
    std::vector<std::unordered_set<std::string>> mails;
    std::vector<std::string> names;
    const int size;

public:
    DSU(std::vector<std::vector<std::string>>&& accounts) : size{static_cast<int>(accounts.size())}
    {
        this->parents = std::vector<int>(size);
        std::iota(std::begin(this->parents), std::end(this->parents), 0);
        this->mails = std::vector<std::unordered_set<std::string>> (size);
        this->names = std::vector<std::string> (size);
        for(int i = 0; i < size; ++i)
        {
            this->mails[i] = std::unordered_set<std::string>(accounts[i].begin()+1, accounts[i].end());
            this->names[i] = std::move(accounts[i].front());
        }
    }

    std::vector<std::vector<std::string>> merge()
    {
        bool change;
        do
        {
            change = false;
            for(int i = 0; i < this->size-1; ++i)
            {
                if(this->parents[i] == DONE)
                {
                    continue;
                }
                for(int j = i+1; j < this->size; ++j)
                {
                    if(i == j || this->parents[j] == DONE)
                    {
                        continue;
                    }
                    if(this->hasCommonAndNotLinkedOrDone(i, j))
                    {
                        this->unionBySize(this->findWithPathCompression(i), this->findWithPathCompression(j));
                        change = true;
                    }
                }
            }

            for(int i = 0; i < this->size; ++i)
            {  
                if(this->findWithPathCompression(i) != i && this->parents[i] != DONE)
                {
                    auto& parentMails =  this->mails[this->parents[i]];
                    parentMails.insert(this->mails[i].begin(), this->mails[i].end());
                    this->parents[i] = DONE;
                }
            }
        }while(change);

        std::vector<std::vector<std::string>> ret;

        for(int i = 0; i < size; ++i)
        {
            if(this->parents[i] == i)
            {
                std::vector<std::string> account(1+this->mails[i].size());
                account[0] = this->names[i];
                int j = 1;
                for(auto& mail:this->mails[i])
                {
                    account[j++] = mail;
                }
                std::sort(account.begin()+1, account.end());
                ret.push_back(std::move(account));
            }
        }
        return ret;
    }

    bool hasCommonAndNotLinkedOrDone(int i, int j)
    {
        if(this->parents[i] == j || this->parents[j] == i || this->parents[i] == this->parents[j])
        {
            return false;
        }

        if(this->mails[i].size() > this->mails[j].size())
        {
            std::swap(i, j);
        }

        for(auto& mail: this->mails[i])
        {
            if(this->mails[j].count(mail) == 1)
            {
                return true;
            }
        }
        return false;
    }

    void unionBySize(int i, int j)
    {
        if(this->mails[i].size() == this->mails[j].size() && i > j)
        {
            std::swap(i, j);
        }
        else if(this->mails[i].size() > this->mails[j].size())
        {
            std::swap(i, j);
        }
        this->parents[i] = j; 
    }

    int findWithPathCompression(int i)
    {
        if(this->parents[i] == DONE)
        {
            return DONE;
        }
        if(this->parents[i] == i)
        {
            return i;
        }

        this->parents[i] = this->findWithPathCompression(this->parents[i]);
        return this->parents[i];
    }

};

class Solution 
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) 
    {
        auto dsu = DSU(std::move(accounts));
        return dsu.merge();
    }
};