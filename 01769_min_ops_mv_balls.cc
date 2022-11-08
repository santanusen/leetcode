class Solution {
public:
    vector<int> minOperations(string boxes) {
        int psum[boxes.size()];
        int nballs[boxes.size()];
        
        int ps = 0, n = 0;
        for (int i = 0; i < boxes.size(); ++i) {
            if (boxes[i] - '0')
                ps += i;
            psum[i] = ps;
            
            n += (boxes[i] - '0');
            nballs[i] = n;
        }
        
        vector<int> res(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); ++i) {
            if (i > 0)
                res[i] = i * nballs[i - 1] - psum[i - 1];
            if (i < boxes.size() - 1)
                res[i] += (psum[boxes.size() - 1] - psum[i] - i * (nballs[boxes.size() - 1] - nballs[i]));
        }
        
        return res;
    }
    
    vector<int> minOperations2(string boxes) {
        vector<int> res(boxes.length());
        
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};
