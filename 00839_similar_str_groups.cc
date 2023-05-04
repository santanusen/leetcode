class Solution {
    bool isSimilar(const string& s1, const string& s2) {
        int mis = 0;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i])
                if (++mis > 2)
                    return false;
        return true;
    }

    int find(int x, int* parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    bool uni(int x, int y, int* parent, int* rank) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py)
            return false;
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[py] < rank[px])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int parent[strs.size()], rank[strs.size()];
        for (int i = 0; i < strs.size(); ++i) {
            parent[i] = i;
            rank[i] = 0;
        }

        int ngrps = strs.size();
        for (int i = 1; i < strs.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (isSimilar(strs[i], strs[j]))
                    if (uni(i, j, parent, rank))
                        --ngrps;

        return ngrps;
    }
};
