class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> nbrs;
        for (int i = 0; i < arr.size(); ++i)
            nbrs[arr[i]].push_back(i);

        vector<bool> visited(arr.size(), false);
        int l = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front(); q.pop();
                    if (cur == arr.size() - 1)
                        return l;

                if (cur > 0 && !visited[cur - 1]) {
                    visited[cur -1] = true;
                    q.push(cur - 1);
                }
                if (cur + 1 < arr.size() && !visited[cur + 1]) {
                    if (cur + 1 == arr.size() - 1) return l + 1;
                    visited[cur + 1] = true;
                    q.push(cur + 1);
                }

                for (auto nbr : nbrs[arr[cur]])
                    if (!visited[nbr]) {
                        if (nbr == arr.size() - 1) return l + 1;
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                
                nbrs[arr[cur]].clear(); // This is the trick
            }
            ++l;
        }

        return -1;
        
    }
};
