lass Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        if (n > t.length())
            return false;
        if (n == 0)
            return true;

        int pos = 0;
        for (auto ch : t)
            if (s[pos] == ch)
                if (++pos == n)
                    return true;


        return false;
        
    }
};

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
