class Solution {
public:
    int convertToMin(string& time){
        int hr = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));
        return hr*60+min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;
        for(string s: timePoints){
            times.push_back(convertToMin(s));
        }
        sort(times.begin(), times.end());
        int minTime = INT_MAX;
        for(int i = 0; i<times.size()-1; i++){
            minTime = minTime>(times[i+1]-times[i])?(times[i+1]-times[i]):minTime;
        }
        minTime = minTime>(1440-times.back()+times[0])?1440-times.back()+times[0]:minTime;
        return minTime;
    }
};