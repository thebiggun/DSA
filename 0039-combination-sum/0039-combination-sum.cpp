class Solution {
public:
    void func(vector<int>& candidates, vector<vector<int>>& res, vector<int>flag, int target, int index){
        if(target<0 || index>=candidates.size()){
            return;
        }
        if(target == 0){
            res.push_back(flag);
            return;
        }
        func(candidates, res, flag, target, index+1);
        flag.push_back(candidates[index]);
        func(candidates, res, flag, target-candidates[index], index);
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        func(candidates, res, {}, target, 0);
        return res;
    }
};