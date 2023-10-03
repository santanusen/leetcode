class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> pq;

        for (int r = 0; r < m; ++r) {
            /*
            int l = 0, h = n - 1, sol = 0;
            while (l <= h) {
                sol = (l + h) /  2;
                if (mat[r][sol]) {
                    if (sol == n - 1 || mat[r][sol + 1] == 0)
                        break;
                    l = sol + 1;
                } else
                    h = sol - 1;
            }
            sol += mat[r][sol];
            */
            int sol = lower_bound(mat[r].begin(), mat[r].end(), 0, greater<int>()) - mat[r].begin();
            
            pair<int, int> sr {sol, r};
            if (pq.size() < k)
                pq.push(sr);
            else {
                if (pq.top() > sr) {
                    pq.pop();
                    pq.push(sr);
                }
            }
        }

        vector<int> ans(k);
        while(!pq.empty()) {
            ans[--k] = pq.top().second;
            pq.pop();
        }

        return ans;
        
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
