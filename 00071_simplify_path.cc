class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        vector<pair<int, int>> dirs;
        int start = 0;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (i <= start) ;
                else if (path.compare(start, i - start, ".") == 0) ;
                else if (path.compare(start, i - start, "..") == 0) { if (!dirs.empty()) dirs.pop_back();}
                else dirs.push_back({start, i - 1});
                start = i + 1;
            }
        }

        if (dirs.empty())
            return "/";

        char res[path.size()];
        int i = 0;
        for (auto [b, e] : dirs) {
            res[i++] = '/';
            while (b <= e) res[i++] = path[b++];
        }
        res[i] = '\0';
        return res;
    }
};
