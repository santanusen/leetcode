/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        std::srand(std::time(0)); // seed the random number generator
    }

    int getRandom() {
        int count = 0;
        ListNode* curr = head;
        int result = 0;
        
        while (curr) {
            count++;
            if ((static_cast<double>(rand()) / (1.0 + RAND_MAX)) < (1.0 / count)) {
                result = curr->val;
            }
            curr = curr->next;
        }

        return result;
    }    
    
    int getRandom2() {
        int count = 0;
        int result = 0;
        ListNode* curr = head;
        
        while (curr) {
            count++;
            // generate a random number between 1 and the count
            // if the random number is 1, update the result with the current node's value
            if (std::rand() % count == 0) {
                result = curr->val;
            }
            curr = curr->next;
        }
        
        return result;
    }
};

class Solution2 {
    vector<int> mPrimes;
    ListNode* mHead;
    ListNode* mCur;

    unsigned int PRNG()
    {
        // our initial starting seed is 5323
        static unsigned int nSeed = 5323;

        // Take the current seed and generate a new value from it
        // Due to our use of large constants and overflow, it would be
        // very hard for someone to predict what the next number is
        // going to be from the previous one.
        nSeed = (8253729 * nSeed + 2396403); 

        // Take the seed and return a value between 0 and 32767
        return nSeed  % 32767;
    }

    ListNode* Shuffle(ListNode* head) {
        int prime = 16 + PRNG() % 127;
        vector<ListNode*> bhead(prime, NULL);
        vector<ListNode*> btail(prime, NULL);

        // Scatter
        for (ListNode* cur = head; cur; ) {
            ListNode* next = cur->next;
            int bid = PRNG() % prime;
            if (!bhead[bid]) {
                bhead[bid] = btail[bid] = cur;
                cur->next = NULL;
            } else {
                cur->next = bhead[bid];
                bhead[bid] = cur;
            }
            cur = next;
        }

        ListNode *ohead = NULL, *otail = NULL;
        // Gather
        while (!bhead.empty()) {
            int bid = PRNG() % bhead.size();
            if (bhead[bid]) {
                if (!ohead)
                    ohead = bhead[bid];
                else
                    otail->next = bhead[bid];
                otail = btail[bid];
            }
            bhead.erase(bhead.begin() + bid);
            btail.erase(btail.begin() + bid);
        }

        return ohead;
    }



public:
    Solution2(ListNode* head) :
        mPrimes {23, 29, 31, 37, 41, 43, 47, 53}
    {
        mHead = Shuffle(head);
        mCur = mHead;
    }
    
    int getRandom() {
        int val = mCur->val;
        mCur = mCur->next;
        if (!mCur) {
            mHead = Shuffle(mHead);
            mCur = mHead;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
