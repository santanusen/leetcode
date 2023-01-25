class Solution {
    int findParent(int i, vector<int>& parent) {
        if (parent[i] != i)
            parent[i] = findParent(parent[i], parent);
        return parent[i];
    }

    void dsUnion(int i, int j, vector<int>& parent) {
        int pi = findParent(i, parent);
        int pj = findParent(j, parent);
        if (pi != pj)
            parent[max(pi, pj)] = min(pi, pj);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) parent[i] = i;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i])
                dsUnion(s1[i] - 'a', s2[i] - 'a', parent);

        string res;
        for (auto ch : baseStr)
            res += ('a' + findParent(ch - 'a', parent));

        return res;
    }
};

