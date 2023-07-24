class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) ans.push_back(asteroids[i]);
            else if (ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
            else if (ans.back() <= -asteroids[i]) {
                if (ans.back() < -asteroids[i]) --i; 
                ans.pop_back(); 
            }
        }
        return ans;
    }

    vector<int> asteroidCollision1(vector<int>& asteroids) {
        vector<int> ans;

        for (auto a : asteroids) {
            if (a > 0)
                ans.push_back(a);
            else {
                if (ans.empty() || ans.back() < 0)
                    ans.push_back(a);
                else {
                    while (!ans.empty() && ans.back() > 0 && ans.back() < -a)
                        ans.pop_back();

                    if (!ans.empty()) {
                        if (ans.back() == -a)
                            ans.pop_back();
                        else if (ans.back() < 0)
                            ans.push_back(a);
                    } else
                        ans.push_back(a);
                }
            }
        }

        return ans;
    }

    vector<int> asteroidCollision2(vector<int>& asteroids) {
        vector<int> ans;
        deque<int> pstack;

        for (auto a : asteroids) {
            if (a > 0)
                pstack.push_back(a);
            else {
                while (!pstack.empty() && pstack.back() < -a)
                    pstack.pop_back();

                if (pstack.empty())
                    ans.push_back(a);
                else if (pstack.back() == -a)
                    pstack.pop_back();
            }
        }

        while (!pstack.empty()) {
            ans.push_back(pstack.front());
            pstack.pop_front();
        }

        return ans;
    }
};

auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return false;}();
