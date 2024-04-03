#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution//DFS 
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) 
    {
        std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<std::string>>> nameToGraph;

        for(auto& info : accounts)
        {
            auto& graph = nameToGraph[info[0]];

            for(int i = 1; i < info.size(); ++i)
            {
                auto& mail1 = info[i];
                if(graph.count(mail1) == 0)
                {
                    graph[mail1] = {};
                }
                for(int j = 1; j < info.size(); ++j)
                {
                    auto& mail2 = info[j];
                    if(mail1 != mail2)
                    {
                        graph[mail1].insert(mail2);
                        graph[mail2].insert(mail1);
                    }
                }
            }
        }
        int i = 0;
        for(auto& p: nameToGraph)
        {
            auto& name = p.first;
            auto& graph = p.second;
            std::vector<std::vector<std::string>> trees;
            std::unordered_set<std::string> visit;
            DFS(graph, trees, visit, name);
            for(auto& mails: trees)
            {
                std::sort(mails.begin()+1, mails.end());
                accounts[i++] = std::move(mails);
            }
        }
        while (accounts.size() > i)
        {
            accounts.pop_back();
        }
        return accounts;
    }

    void DFS(   std::unordered_map<std::string, std::unordered_set<std::string>>& graph, 
                std::vector<std::vector<std::string>>& trees,
                std::unordered_set<std::string>& visit,
                const std::string& name
            )
    {
        for(auto& p: graph)
        {
            auto& current = p.first;
            if(visit.count(current) == 0)
            {
                std::vector<std::string> tree{name};
                DFShelper(graph, visit, tree, current);
                trees.push_back(tree);
            }
        }

    }

    void DFShelper  (   std::unordered_map<std::string, std::unordered_set<std::string>>& graph, 
                        std::unordered_set<std::string>& visit,
                        std::vector<std::string>& tree,
                        const std::string& current
                    )
    {
        if(visit.count(current) == 1)
        {
            return;
        }
        visit.insert(current);
        tree.push_back(current);
        for(auto& next: graph[current])
        {
            DFShelper(graph, visit, tree, next);
        }
    }
};

class Solution1//~disjoint set 
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) 
    {
        std::unordered_map<std::string, std::vector<std::unordered_set<std::string>>> hashMap;

        for(auto&info : accounts)
        {
            std::string& name = info[0];
            hashMap[name].push_back(std::unordered_set<std::string>(info.begin()+1, info.end()));
        }

        auto hasCommon = [](std::unordered_set<std::string>& a, std::unordered_set<std::string>& b)
        {
            for(auto& s: a)
            {
                if(b.count(s))
                {
                    return true;
                }
            }
            return false;
        };

        for(auto& p: hashMap)
        {
            auto& mailGroupsVec = p.second;
            int size;
            do
            {
                std::vector<std::unordered_set<std::string>> res = {mailGroupsVec[0]};
                size = mailGroupsVec.size();
                for(int i = 1; i < mailGroupsVec.size(); ++i)
                {
                    auto mailSetI =  mailGroupsVec[i];
                    bool common = false;
                    for(int j = 0; j < res.size(); ++j)
                    {
                        auto& mailSetJ = res[j];
                        if(mailSetI.size() <= mailSetJ.size())
                        {
                            common = hasCommon(mailSetI, mailSetJ);
                        }
                        else
                        {
                            common = hasCommon(mailSetJ, mailSetI);
                        }

                        if(common)
                        {
                            mailSetJ.insert(mailSetI.begin(), mailSetI.end());
                            break;
                        }
                    }
                    if(!common)
                    {
                        res.push_back(mailSetI);
                    }
                }
                if(res.size() < mailGroupsVec.size())
                {
                    mailGroupsVec.swap(res);
                }
            }while(size != mailGroupsVec.size());
        }

        std::vector<std::vector<std::string>> res;
        for(auto& nameAndGroupsVec: hashMap)
        {
            for(auto& group: nameAndGroupsVec.second)
            {
                std::vector<std::string> account {nameAndGroupsVec.first};
                std::vector<std::string> mails(group.size());
                mails.assign(group.begin(), group.end());
                std::sort(mails.begin(), mails.end());
                account.reserve(1+mails.size());
                std::move(std::begin(mails), std::end(mails), std::back_inserter(account));
                res.push_back(account);
            }
        }

        return res;
    }
};