#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

typedef std::pair<int, int> pi;

class SnapshotArray 
{
private:
    std::vector<std::vector<pi>> snapshots;
    int snap_id;

public:
    SnapshotArray(int length) 
    {
        this->snap_id = 0;
        this->snapshots = std::vector<std::vector<pi>> (length);
        for(auto& vec: this->snapshots)
            vec.push_back(std::make_pair(this->snap_id, 0));
    }    

    void set(int index, int val) 
    {
        if(this->snapshots[index].back().first == this->snap_id)
            this->snapshots[index].back().second = val;
        else
            this->snapshots[index].push_back(std::make_pair(this->snap_id, val));
    }
    
    int snap() 
    {
        return this->snap_id++;  

    }
    
    int get(int index, int snap_id) 
    {
        auto upper = std::upper_bound(this->snapshots[index].begin(), this->snapshots[index].end(), std::make_pair(snap_id, INT_MAX));
        if(upper == this->snapshots[index].end())
            return this->snapshots[index].back().second;
        return (*(upper-1)).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main(int argc, char const *argv[])
{
    
    return 0;
}
