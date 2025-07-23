class Solution {
public:
    void func(vector<int>& candidates, vector<vector<int>>& res, vector<int>& flag, int target, int index) {
        if (target == 0) {
            res.push_back(flag);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            flag.push_back(candidates[i]);
            func(candidates, res, flag, target - candidates[i], i + 1);
            flag.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> flag;
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        func(candidates, res, flag, target, 0);
        return res;
    }
};
