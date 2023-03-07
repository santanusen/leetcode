class Solution {
    template<typename T>
    T random_pick(T range_from, T range_to) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<T>    distr(range_from, range_to);
        return distr(generator);
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        if (is_sorted(nums.begin() + low, nums.begin() + high + 1)) return;
        swap(nums[low], nums[random_pick(low, high)]);
        int p = low, l = low + 1, r = high;
        int pnum = nums[p];
 
        while (l <= r) {
            while (l <= r && nums[l] <= pnum) ++l;
            while (l <= r && nums[r] >= pnum) --r;
            if (l < r) swap(nums[l], nums[r]);
        }
        swap(nums[p], nums[r]);
        quicksort(nums, low, r - 1);
        quicksort(nums, r + 1, high);
    }

    void count_sort(vector<int>& nums) {
        unordered_map<int, int> freq;
        int vmin = INT_MAX, vmax = INT_MIN;
        for (auto n : nums) {
            ++freq[n];
            vmin = min(vmin, n);
            vmax = max(vmax, n);
        }
        for (int n = vmin, i = 0; n <= vmax; ++n) {
            auto itr = freq.find(n);
            if (itr != freq.end())
                while (itr->second--)
                    nums[i++] = n;
        }
    }

    vector<int>& merge_sort(vector<int>& nums, vector<int>& aux) {
        int n = nums.size();
        auto vin = &nums;
        auto vout = &aux;

        int k = 1;
        while (k < n) {
            int kdob = k << 1, i;
            for (i = 0; i + k < n; i += kdob) {
                int a = i, b = i + k, c = i, bmax = min(i + kdob, n);
                while (a < i + k && b < bmax)
                    (*vout)[c++] = ((*vin)[a] < (*vin)[b]) ? (*vin)[a++] : (*vin)[b++];
                while (a < i + k) (*vout)[c++] = (*vin)[a++];
                while (b < bmax) (*vout)[c++] = (*vin)[b++];
            }
            while (i < n) (*vout)[i++] = (*vin)[i];

            k = kdob;
            swap(vin, vout);
        }

        return *vin;
    }

    void max_heapify(vector<int>& nums, int idx, int N) {
        if (idx >= N) return;
        int c = 2 * idx + 1;
        if (c >= N) return;
        if (c + 1 < N && nums[c + 1] > nums[c])
            c = c + 1;
        if (nums[idx] < nums[c]) {
            swap(nums[idx], nums[c]);
            max_heapify(nums, c, N);
        }
    }
    void build_heap(vector<int>& nums) {
        for (int idx = nums.size() / 2 - 1; idx > -1; --idx)
            max_heapify(nums, idx, nums.size());
    }

    void heap_sort(vector<int>& nums) {
        build_heap(nums);
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[i], nums[0]);
            max_heapify(nums, 0, i);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        /*
        if (!is_sorted(nums.begin(), nums.end()))
            
        */
        /*
        if (!is_sorted(nums.begin(), nums.end()))
            count_sort(nums);
        */
        /*
        if (!is_sorted(nums.begin(), nums.end())) {
            vector<int> aux(nums.size());
            return merge_sort(nums, aux);
        }
        */

        quicksort(nums, 0, nums.size() - 1);
        /*
        heap_sort(nums);
        */


        return nums;
    }
};
