class Solution {

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if (n <= 2) return true; // Trivial case

        // Convert edge list into adjacency list
        unordered_map<int, unordered_set<int>> dlist;
        for (auto& d : dislikes) {
            dlist[d[0]].insert(d[1]);
            dlist[d[1]].insert(d[0]);
        }

        // Run BFS from each node and try to color its neighbors.
        // color :  0 - Uncolored
        //          1 - Group 1
        //          2 - Group 2
        // If a node has color of a particular group, try to color
        // the neighbor with the opposite group color. 
        vector<bool> visited(n + 1, false);
        vector<uint8_t> color(n + 1, 0);

        for (int i = 1; i < n + 1; ++i) {
            if (visited[i]) continue;
            if (!dlist.count(i)) continue; // No haters.
   
            if (!color[i]) color[i] = 1; // If not part of a group yet, start with one.
            queue<int> bfsq;
            bfsq.push(i);
            // Run BFS and color neighbors.
            while(!bfsq.empty()) {
                int x = bfsq.front(); bfsq.pop();
                if (visited[x]) continue;
                visited[x] = true;
                
                auto itr = dlist.find(x);
                if (itr == dlist.end()) continue;

                uint8_t tcol = 3 - color[x]; // Target color for neighbors.
                for (auto d : itr->second) {
                    if (!color[d]) color[d] = tcol;
                    if (color[d] != tcol) // Cannot put neighbor to opposite group.
                        return false;
                    if (!visited[d]) bfsq.push(d);
                }            
            }
        }

        return true;
    }
};
