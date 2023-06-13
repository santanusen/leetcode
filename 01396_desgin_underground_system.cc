static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class UndergroundSystem {
    unordered_map<int, pair<string, int>> chkin;
    unordered_map<string, pair<int, int>> travt;
public:
    
    void checkIn(int id, string stationName, int t) {
        chkin[id] = {stationName, t};      
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [cstn, ctm] = chkin[id];
        chkin.erase(id);
        auto& [ttm, n] = travt[cstn + ":" + stationName];
        ttm += (t - ctm);
        ++n;
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto [ttm, n] = travt[startStation + ":" + endStation];
        return (double)ttm / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
