static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    string predictPartyVictory1(string senate) {
        string D = "Dire", R = "Radiant";
        int n = senate.length();

        int r = 0, d = 0;
        queue<char> q;

        for (auto c : senate) {
            if (c == 'R') ++r;
            else ++d;
            q.push(c);
        }

        int rban = 0, dban = 0;
        while (d && r) {
            auto c = q.front(); q.pop();
            if (c == 'R') {
                if (rban > 0) {
                    --rban;
                    --r;
                } else {
                    ++dban;
                    q.push(c);
                }
            } else {
                if (dban > 0) {
                    --dban;
                    --d;
                } else {
                    ++rban;
                    q.push(c);
                }
            }
        }

        return d ? D : R;
    }


    string predictPartyVictory(string s) {
        string D = "Dire", R = "Radiant";
        queue<int> rq, dq;
        int n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] == 'R') rq.push(i);
            else dq.push(i);

        while (!rq.empty() && !dq.empty()) {
            auto r = rq.front(); rq.pop();
            auto d = dq.front(); dq.pop();
            if (r < d) rq.push(r + n);
            else dq.push(d + n);
        }

        return rq.empty() ? D : R;
    }

    string predictPartyVictory2(string senate) {
        string D = "Dire", R = "Radiant";
        int n = senate.length();
        if (n == 1) return (senate[0] == 'D') ? D : R;

        int r = 0;
        for (auto c : senate)
            if (c == 'R') ++r;
        int d = n - r;

        int i = 0;
        while (d > 0 && r > 0) {
            if (senate[i] != 'X') {
                for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                    if (senate[j] != 'X' && senate[j] != senate[i]) {
                        senate[j] = 'X';
                        if (senate[i] == 'R') --d;
                        else --r;
                        break;
                    }
                }
            }
            i = (i + 1) % n;
        }
        
        return (d > 0) ? D : R;
    }
};
