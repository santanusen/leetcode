class UnionFind {
    vector<int> representative;
    vector<int> componentSize;
    // Number of distinct components in the graph.
    int components;
    
public:
    // Initialize the list representative and componentSize
    // Each node is representative of itself with size 1.
    UnionFind(int n) {
        components = n;
        for (int i = 0; i <= n; i++) {
            representative.push_back(i);
            componentSize.push_back(1);
        }
    }
    
    // Get the root of a node.
    int findRepresentative(int x) {
        if (representative[x] == x) {
            return x;
        }
        
        // Path compression.
        return representative[x] = findRepresentative(representative[x]);
    }
    
    // Perform the union of two components that belongs to node x and node y.
    int performUnion(int x, int y) {       
        x = findRepresentative(x); y = findRepresentative(y);
        
        if (x == y) {
            return 0;
        }
        
        if (componentSize[x] > componentSize[y]) {
            componentSize[x] += componentSize[y];
            representative[y] = x;
        } else {
            componentSize[y] += componentSize[x];
            representative[x] = y;
        }
        
        components--;
        return 1;
    }
    
    // Returns true if all nodes get merged to one.
    bool isConnected() {
        return components == 1;
    }
};

class Solution2 {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Different objects for Alice and Bob.
        UnionFind Alice(n), Bob(n);

        int edgesRequired = 0;
        // Perform union for edges of type = 3, for both Alice and Bob.
        for (vector<int>& edge : edges) {
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        // Perform union for Alice if type = 1 and for Bob if type = 2.
        for (vector<int>& edge : edges) {
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        // Check if the Graphs for Alice and Bob have n - 1 edges or is a single component.
        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};

class Solution {
    class UnionFind {
        vector<int> group;
        vector<int> gsize;
        
    public:
        UnionFind (int n) : group(n), gsize(n, 1) {
            for (int i = 0; i < n; ++i) group[i] = i;
        }

        int find(int x) {
            if (group[x] != x)
                group[x] = find(group[x]);
            return group[x];
        }

        bool join(int x, int y) {
            int gx = find(x);
            int gy = find(y);
            if (gx == gy) return false;

            if (gsize[gx] > gsize[gy]) {
                gsize[gx] += gsize[gy];
                group[gy] = gx;
            } else {
                gsize[gy] += gsize[gx];
                group[gx] = gy;
            }

            return true;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        UnionFind ua(n), ub(n);
        int na = n, nb = n, er = 0;
        for (int i = edges.size() - 1; i > -1; --i) {
        //for (auto& e : edges) {
            auto& e = edges[i];
            if (e[0] == 3) {
                bool ja, jb;
                if ((ja = ua.join(e[1] - 1, e[2] - 1)))
                    --na;
                if ((jb = ub.join(e[1] - 1, e[2] - 1)))
                    --nb;
                if (ja || jb)
                    ++er;
            } else if (e[0] == 2) {
                if (ub.join(e[1] - 1, e[2] - 1)) {
                    --nb;
                    ++er;
                }
            } else {
                if (ua.join(e[1] - 1, e[2] - 1)) {
                    --na;
                    ++er;
                }
            }
        }

        return (na > 1 || nb > 1) ? -1 : edges.size() - er;
    }
};
