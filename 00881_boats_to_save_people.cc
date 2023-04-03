class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        //if (people[r] > limit) return INT_MAX;
        //int ans = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) ++l;
            --r;
            //++ans;
        }
        //return ans;
        return people.size() - 1 - r;
    }
};
