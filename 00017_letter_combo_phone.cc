class Solution {
    string getLetters(char d) {
        switch (d) {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: break;
        }
        return "";
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        res.push_back("");
        for (auto d : digits) {
            auto ltrs = getLetters(d);
            vector<string> q;
            for (int i = 0; i < res.size(); ++i)
                for (auto l : ltrs)
                    q.push_back(res[i] + l);
            res.swap(q);
        }
        
        return res;
    }
};
