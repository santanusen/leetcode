#pragma GCC optimize("0fast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class SnapshotArray {
    unordered_map<int /*index*/,
                  map<int /*snap-id*/, int /*value*/>> snaps;
    int snapId;
public:
    SnapshotArray(int length) : snapId(0) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto itr = snaps.find(index);
        if (itr == snaps.end())
            return 0;
        auto uitr = itr->second.upper_bound(snap_id);
        if (uitr == itr->second.end())
            return itr->second.rbegin()->second;
        else if (uitr == itr->second.begin())
            return 0;
        return (--uitr)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
