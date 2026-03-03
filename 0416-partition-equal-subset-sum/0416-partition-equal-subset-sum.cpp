
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

    bool findSumTabular(vector<int>& nums, int want_Sum){
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(want_Sum+1, 0));

        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int index = n-1; index>=0; index--){
            for(int wantSum = 1; wantSum<=want_Sum; wantSum++){
                bool inc = false;
                bool ex = false;
                if(nums[index]<=wantSum){
                    inc = dp[index+1][wantSum-nums[index]];
                }
                ex = dp[index+1][wantSum];
                dp[index][wantSum] = inc||ex;
            }
        }
        return dp[0][want_Sum];
    }

    bool findSumOptimal1(vector<int>& nums, int want_Sum){
        int n = nums.size();

        vector<bool>next(want_Sum+1, false);
        vector<bool>curr(want_Sum+1, false);

        next[0] = true;
        curr[0] = true;

        for(int index = n-1; index>=0; index--){
            for(int wantSum = 1; wantSum<=want_Sum; wantSum++){
                bool inc = false;
                bool ex = false;
                if(nums[index]<=wantSum){
                    inc = next[wantSum-nums[index]];
                }
                ex = next[wantSum];
                curr[wantSum] = inc||ex;
            }
            next = curr;
        }
        return curr[want_Sum];
    }

    bool findSumOptimal2(vector<int>& nums, int want_Sum){
        int n = nums.size();

        vector<bool>curr(want_Sum+1, false);

        curr[0] = true;

        for(int index = n-1; index>=0; index--){
            for(int wantSum = want_Sum; wantSum >= 1; wantSum--){
                bool inc = false;
                bool ex = false;
                if(nums[index]<=wantSum){
                    inc = curr[wantSum-nums[index]];
                }
                ex = curr[wantSum];
                curr[wantSum] = inc||ex;
            }
        }
        return curr[want_Sum];
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;
        for(int i:nums) totalSum+=i;
        if(totalSum%2==1) return false;
        int find_Sum = totalSum/2;
        
        return findSumOptimal2(nums, find_Sum);
    }
};