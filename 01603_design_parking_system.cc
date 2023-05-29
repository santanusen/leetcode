static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class ParkingSystem {
    int np[3];
public:
    ParkingSystem(int big, int medium, int small) : np {big, medium, small} {  
    }
    
    bool addCar(int carType) {
        return np[carType - 1] ? np[carType - 1]-- : 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
