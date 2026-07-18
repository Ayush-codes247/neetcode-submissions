class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());
        for(int i = 0; i < position.size(); i++){
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        sort(cars.begin(), cars.end());
        stack<double> times;
        times.push((target - cars[cars.size()-1].first)/(double)cars[cars.size()-1].second);
        for(int i = cars.size() - 2; i >= 0; i--){
            double t = (target - cars[i].first)/(double)cars[i].second;
            if(t > times.top()){
                times.push(t);
            }
        }
        return times.size();
    }
};
