static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;

        int si = 0, tlen = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (tlen + words[i].length() + (i - si) <= maxWidth) {
                tlen += words[i].length();
            } else {
                // Flush si ... i - 1
                int nsp = maxWidth - tlen;
                int slots = i - 1 - si;

                string line = words[si];                
                if (slots > 0) {
                    int spd = nsp / slots;
                    int spr = nsp % slots;
                
                    for (int j = si + 1; j < i; ++j) {
                        for (int s = 0; s < spd; ++s)
                            line.push_back(' ');
                        if (spr > 0) {
                            line.push_back(' ');
                            --spr;
                        }
                        line += words[j];
                    }
                } else {
                    for (int sp = 0; sp < nsp; ++sp)
                        line.push_back(' ');
                }
                lines.push_back(line);

                ///
                tlen = words[i].length();
                si = i;
            }
        }

        string line = words[si];
        int nsp = maxWidth - tlen;
        for (int i = si + 1; i < words.size(); ++i) {
            line.push_back(' ');
            line += words[i];
            --nsp;
        }
        for (int sp = 0; sp < nsp; ++sp)
            line.push_back(' ');
        lines.push_back(line);

        return lines;
        
    }
};
