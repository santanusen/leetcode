class FoodRatings {
    typedef set<pair<int, string>> rset_t;
    typedef unordered_map<string, rset_t::iterator> rhmap_t;
    typedef unordered_map<string, pair<rset_t, rhmap_t>> table_t;

    typedef unordered_map<string, string> f2c_t;

    table_t table;
    f2c_t f2c;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            auto& f = foods[i];
            auto& c = cuisines[i];
            auto& r = ratings[i];

            auto& prr = table[c];
            auto& rs = prr.first;
            auto& rh = prr.second;

            auto res = rs.insert({-r, f});
            rh[f] = res.first;

            f2c[f] = c;
        }
    }
    
    void changeRating(string food, int newRating) {
        auto c = f2c[food];
        auto& [rs, rh] = table[c];

        auto itr = rh[food];
        rs.erase(itr);
        
        auto res = rs.insert({-newRating, food});
        rh[food] = res.first;
    }
    
    string highestRated(string cuisine) {
        return table[cuisine].first.begin()->second;    
    }
};

auto _ = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
