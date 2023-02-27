class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int n = profits.size();
        if (n == 1) return (capital[0] > w) ? w : w + profits[0];

        vector<pair<int, int>> proj(n);

        for (int i = 0; i < n; ++i)
            proj[i] = {capital[i], profits[i]};

        sort(proj.begin(), proj.end());

        priority_queue<int> q;
        int unlocked = 0;
        while (k--) {
            while(unlocked < n && proj[unlocked].first <= w)
                q.push(proj[unlocked++].second);

            if (q.empty()) break;
            w += q.top(); q.pop();
        }
        return w;
    }

    int findMaximizedCapital2(int k, int w, vector<int>& profits, vector<int>& capital) {
        list<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i)
            projects.push_back({profits[i],capital[i]});

        projects.sort(greater<pair<int, int>>());
        while (k--) {
            bool got_project = false;
            for (auto itr = projects.begin(); itr != projects.end(); ++itr) {
                if (w >= itr->second) {
                    w += itr->first;
                    got_project = true;
                    projects.erase(itr);
                    break;
                }
            }

            if (!got_project)
                break;
        }

        return w;
        
    }
};
