
constexpr int mod = 1'000'000'007;
int fact[1001], ifact[1001];

long pow(long u, int p) {
    long res = 1;
    while (p) {
        if (p & 1) res = res * u % mod;
        p >>= 1;
        u = u * u % mod;
    }
    return res;
}

int speedup = []{
    ios::sync_with_stdio(0); cin.tie(0);
    long f = fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1000; ++i) fact[i] = f = f * i % mod;
    ifact[1000] = f = pow(f, mod - 2);
    for (int i = 1000; i; --i) ifact[i-1] = f = f * i % mod;
    return 0;
}();


int mi[10][1000], mp[10][1000];

int compute(int l, int r) {
    int sz = r - l;
    if (sz <= 2) return 1;
    int lsz = 31 - __builtin_clz(sz), r2 = r - (1 << lsz);
    int p = mi[lsz][l] <= mi[lsz][r2] ? mp[lsz][l] : mp[lsz][r2];

    long res = long(fact[sz-1]) * ifact[p-l] % mod * ifact[r-p-1] % mod;
    return res * compute(l, p) % mod * compute(p+1, r) % mod;
}

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = size(nums), pos[n+1];
        for (int i = 0; i < n; ++i) pos[nums[i]]  = i;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; ++i) mi[0][i] = pos[nums[i]], mp[0][i] = i;
        for (int d = 0, s = 2; s <= n; ++d, s *= 2) {
            for (int i = 0; i + s <= n; ++i) {
                int j = i + s/2;
                if (mi[d][i] <= mi[d][j]) j = i;
                mi[d+1][i] = mi[d][j];
                mp[d+1][i] = mp[d][j];
            }
        }
        return compute(0, n) - 1;
    }
};


class Solution2 {
    vector<vector<long long>> table;
    long long M = 1E9 + 7;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m < 3) return 1;

        vector<int> lnums, rnums;
        for (int i = 1; i < m; ++i)
            if (nums[i] < nums[0])
                lnums.push_back(nums[i]);
            else
                rnums.push_back(nums[i]);
        //nums.clear();
        int lnsz = lnums.size();
        long long nl = dfs(lnums) % M;
        long long nr = dfs(rnums) % M;

        return (((nl * nr) % M) * table[m - 1][lnsz]) % M;
    }
public:
    int numOfWays(vector<int>& nums) {
        M = 1E9 + 7;
        int m = nums.size();
        table.resize(m + 1);
        for (int i = 0; i < m + 1; ++i) {
            table[i] = vector<long long> (i + 1, 1);
            for (int j = 1; j < i; ++j)
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % M;
        }

        return (dfs(nums) - 1) % M;
    }
};
