class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (int i = 1, prv = pref[0]; i < pref.size(); pref[i] ^= prv, ++i)
            swap(pref[i], prv);
        return pref;
    }

    vector<int> findArray2(vector<int>& pref) {
        for (int i = pref.size() - 1; i > 0; --i) 
            pref[i] ^= pref[i - 1];
        return pref;
    }
};
