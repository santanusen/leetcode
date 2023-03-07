class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        for (int i = 1, cnt = 1; i <= chars.size(); ++i) {
            if (i < chars.size() && chars[i - 1] == chars[i])
                ++cnt;
            else {
                chars[j++] = chars[i - 1];
                if (cnt > 1) {
                    string scnt = to_string(cnt);
                    for (auto cch: scnt)
                        chars[j++] = cch;
                }
                cnt = 1;
            }
        }
        //chars.erase(chars.begin() + j, chars.end());
        //return chars.size();
        return j;
    }
};
