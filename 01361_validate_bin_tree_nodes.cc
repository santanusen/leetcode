class DJS {
    int *group;
public:

    DJS(int n) : group(new int[n]) {
        for (int i = 0; i < n; ++i)
            group[i] = i;
    }

    int Find(int x) {
        if (group[x] != x)
            group[x] = Find(group[x]);
        return group[x];
    }

    bool Union(int x, int y) {
        int gx = Find(x);
        int gy = Find(y);

        if (gx == gy)
            return false;

        group[gy] = gx;
        return true;
    }

};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DJS d(n);

        int cc = n, ch;
        for (int i = 0; i < n; ++i) {
            ch = leftChild[i];
            if (ch != -1) {
                if (d.Find(ch) != ch)
                    return false;

                if (d.Union(i, ch))
                    --cc;
                else
                    return false;
            }

            ch = rightChild[i];
            if (ch != -1) {
                if (d.Find(ch) != ch)
                    return false;

                if (d.Union(i, ch))
                    --cc;
                else
                    return false;
            }
        }

        return (cc == 1);
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
