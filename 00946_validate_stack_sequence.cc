class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0, k = 0;
        for (auto num : pushed) {
            pushed[k] = num;
            while (k > -1 && j < popped.size() && pushed[k] == popped[j]) {
                --k;
                ++j;
            }
            ++k;
        }

        return j == popped.size();
        
    }

    bool validateStackSequences2(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (auto num : pushed) {
            s.push(num);
            while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }

        //return (s.empty() && j == popped.size());
        return j == popped.size();
        
    }
};
