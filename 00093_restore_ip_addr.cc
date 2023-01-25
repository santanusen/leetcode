class Solution {
    bool valid_quat (const string& s, int pos, int len) {
        if (len < 1 || len > 3 || pos + len > s.length() || len > 1 && s[pos] == '0') return false;
        if (len == 3 && stoi(s.substr(pos, len)) > 255) return false;
        return true;
    }

    void dfs(const string& s, vector<int> dots, vector<string>& res) {
        if (dots.size() == 3) {
            int pos = dots[2] + 1;
            if (valid_quat(s, pos, s.length() - pos)) {
                res.push_back(s.substr(0, dots[0] + 1) + '.' +
                              s.substr(dots[0] + 1, dots[1] - dots[0]) + '.' +
                              s.substr(dots[1] + 1, dots[2] - dots[1]) + '.' +
                              s.substr(pos, s.length() - pos));
            }
            return;
        }

        int pos = (dots.empty() ? 0 : dots.back() + 1);
        for (int len = 1; len < 4; ++len) {
            if (valid_quat(s, pos, len)) {
                dots.push_back(pos + len - 1);
                dfs(s, dots, res);
                dots.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 3 && s.length() < 17) {
            vector<int> dots;
            dfs(s, dots, res);
        }
        return res;
    }
};
