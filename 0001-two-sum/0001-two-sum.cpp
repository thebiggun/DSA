class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;
        for(int i = 0; i<nums.size(); i++){
            int comp = target - nums[i];
            if(res.find(comp)!=res.end()) return {res[comp], i};
            res[nums[i]] = i;
        }
        return {};
    }
};