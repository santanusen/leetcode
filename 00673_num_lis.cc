class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int, int>>> LIS;
        LIS.push_back(vector<pair<int, int>>(1, pair<int,int>(nums[0], 1))); 

        for(int i = 1; i < nums.size(); i++) {
            auto j = LIS.rbegin();
            int greaterCount = 0;
            while (j != LIS.rend()) {
                for (auto k = (*j).rbegin(); k < (*j).rend(); ++k)
                    if(nums[i] > (*k).first)
                        greaterCount += (*k).second;
                    else //if its not bigger than the given element, exit the count check
                        break; 
                if (greaterCount != 0) // if greater count is 0, go back 1 list length, else break
                    break; 
                ++j;
            }

            if(j == LIS.rbegin()) { // if its bigger than an element at the longest length, make length 1 longer
                LIS.push_back(move(vector<pair<int,int>>(1, pair<int,int>(nums[i], greaterCount))));
            } else  {
                if (j == LIS.rend())
                    greaterCount = 1;
                if (nums[i] == (*(j - 1)).back().first)
                    (*(j - 1)).back().second += greaterCount;
                else
                    (*(j - 1)).push_back(move(pair<int,int>(nums[i], greaterCount)));
            }
        }

        return  accumulate(LIS.back().begin(), LIS.back().end(), 0,
                            [](int a, pair<int,int> b) {
                                return a + b.second;
                            });
    }

    int findNumberOfLIS2(std::vector<int>& nums) {
        int n = nums.size();
        int length[n], count[n];

        int lismax = 1, lcnt = 0;

        for (int i = 0; i < n; i++) {

            length[i] = count[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    int ll = length[j] + 1;
                    if (ll > length[i]) {
                        length[i] = ll;
                        count[i] = count[j];
                    } else if (ll == length[i]) {
                        count[i] += count[j];
                    }
                }
            }

            if (length[i] > lismax) {
                lismax = length[i];
                lcnt = count[i];
            } else if (length[i] == lismax) {
                lcnt += count[i];
            }
        }

        return lcnt;
    }

};

auto _=[](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
