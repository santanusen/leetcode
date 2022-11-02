class Solution {
public:
    
    int dist(string s1, string s2) {
        int d = 0;
        
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i])
                if (++d > 1)
                    break;
        
        return d;
    }
    
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        int level = 0;
        
        q.push(start);
        while (!q.empty()) {
            int ls = q.size();
            for (int i = 0; i < ls; ++i) {
                auto cur = q.front(); q.pop();
                int d = dist(cur, end);
                if (d < 1)
                    return level + d;
                
                for (auto itr = bank.begin(); itr != bank.end();) {
                    if (dist(cur, *itr) < 2) {
                        q.push(*itr);
                        itr = bank.erase(itr);
                    } else
                        ++itr;
                }
            }
            ++level;
        }
        
        return -1;
        
    }
};

