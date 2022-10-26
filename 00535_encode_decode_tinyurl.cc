class Solution {
    
    unordered_map<size_t, string> table;
        
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto h = hash<string>{}(longUrl);
        table[h] = longUrl;
        return to_string(h);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t h = stoul(shortUrl);
        return table[h];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
