class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto i: timePoints)
        {
            int h=0;
            int t= 0;
            h += i[0] - '0';
            h *= 10;
            h += i[1] - '0';
            t += i[3] - '0';
            t*= 10;
            t += i[4] - '0';
            v.push_back(h *60 + t);
        }
        sort(v.begin(), v.end());
        int mini = 24*60 + v[0] - v.back();
        for(int i=0; i<v.size() - 1; i++)
        {
            mini = min(mini, (v[i + 1] - v[i]));
        }
        return mini;
    }
};