class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0); // Indegree - Outdegree
        for (auto& t : trust)
            --degree[t[0]], ++degree[t[1]]; // t[0] trusts t[1]. t[0] -> t[1]
        for (int i = 1; i < n + 1; ++i)
            if (degree[i] == n - 1)
                return i;
        return -1;
    }

    int findJudge2(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n, 0), trusted_by(n, 0);
        for (auto& t: trust) {
            ++trusts[t[0] - 1];
            ++trusted_by[t[1] - 1];
        }

        int judge = -1;
        for (int i = 0; i < n; ++i)
            if (trusts[i] == 0 && trusted_by[i] == n - 1)
                if (judge != -1)
                    return -1;
                else
                    judge = i + 1;

        return judge;    
    }
}
