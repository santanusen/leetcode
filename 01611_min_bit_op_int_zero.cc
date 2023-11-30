class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int k = 0, cur = 1;
        while((cur << 1) <= n) {
            cur <<= 1;
            ++k;
        }
        return (1 << (k + 1)) - 1 -  minimumOneBitOperations(n ^ cur);
    }

    int minimumOneBitOperations_bfs(int n) {
        if (n == 0) return 0;

        unordered_set<uint32_t> seen {static_cast<uint32_t>(n)};
        queue<uint32_t> q;
        q.push({static_cast<uint32_t>(n)});
        
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();
                // op1
                uint32_t n1 = ((cur & 0x1) ? (cur & ~0x1) : (cur | 0x1));
                if (n1 == 0) return ans + 1;
                if (seen.find(n1) == seen.end()) {
                    seen.insert(n1);
                    q.push(n1);
                }

                // op2
                int i = 0;
                while ((cur & (0x1 << i)) == 0)
                    ++i;
                
                if (i > 30) continue;
                uint32_t mask = 0x1 << (i + 1);
                uint32_t n2 = ((cur & mask) ? (cur & ~mask) : (cur | mask));
                if (n2 == 0) return ans + 1;
                if (seen.find(n2) == seen.end()) {
                    seen.insert(n2);
                    q.push(n2);
                }                
            }
            ++ans;
        }

        return -1;
    }
};
