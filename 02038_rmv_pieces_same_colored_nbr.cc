class Solution {
public:
    bool winnerOfGame(string colors) {
        int adv = 0;

        char pc = 'C';
        int n = colors.size(), streak = 0;
        for (int i = 0; i <= n; ++i) {
            auto c = (i < n ? colors[i] : 'Z');
            if (c != pc) {
                if (streak > 2) {
                    if (pc == 'A')
                        adv += (streak - 2);
                    else
                        adv -= (streak - 2);
                }
                streak = 1;
            } else {
                ++streak;
            }

            pc = c;
        }

        return adv > 0;
        
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
