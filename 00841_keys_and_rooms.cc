class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited, q;
        //queue<int> q;
        q.insert(0);
        while (!q.empty()) {
            auto r = *q.begin();
            q.erase(r);
            if (!visited.count(r)) {
                visited.insert(r);
                if (visited.size() == rooms.size())
                    return true;
                for (auto k : rooms[r]) q.insert(k);
            }
        }

        return visited.size() == rooms.size();
        
    }
};
