class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) {
            return false;
        }
        
        unordered_set<char> alphabet;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            alphabet.insert(ch);
        
        for (char ch : sentence) {
            alphabet.erase(ch);
            if (alphabet.empty())
                return true;
        }
        
        return false;
        
    }
};
