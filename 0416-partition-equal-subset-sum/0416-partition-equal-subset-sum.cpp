
class Solution {
public:
    bool findSum(vector<int>& nums, int index, int wantSum){
        if(wantSum==0) return true;
        if(index>=nums.size()) return false;
        
        bool inc = false;
        bool ex = false;
        if(nums[index]<=wantSum){
            inc = findSum(nums, index+1, wantSum-nums[index]);
        }
        ex = findSum(nums, index+1, wantSum);
        return inc||ex;
    }

    bool findSumMemo(vector<int>& nums, int index, int wantSum, vector<vector<int>>& dp){
        if(wantSum==0) return true;
        if(index>=nums.size()) return false;
        if(dp[index][wantSum]!=-1) return dp[index][wantSum];
        bool inc = false;
        bool ex = false;
        if(nums[index]<=wantSum){
            inc = findSumMemo(nums, index+1, wantSum-nums[index], dp);
        }
        ex = findSumMemo(nums, index+1, wantSum, dp);
        dp[index][wantSum] = inc||ex;
        return inc||ex;
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        for(int i:nums) totalSum+=i;
        if(totalSum%2==1) return false;
        int find_Sum = totalSum/2;
        
        vector<vector<int>>dp(nums.size(), vector<int>(find_Sum+1, -1));
        return findSumMemo(nums, 0, find_Sum, dp);
    }
};