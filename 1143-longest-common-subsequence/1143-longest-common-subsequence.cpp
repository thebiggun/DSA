class Solution {
public:
    int solRecursive(string text1, string text2, int i, int j){
        if(i == text1.size() || j == text2.size()) return 0;
        int ans = INT_MIN;
        if(text1[i]==text2[j]){
            return 1 + solRecursive(text1, text2, i+1, j+1);
        }
        ans = 0 + max(solRecursive(text1, text2, i+1, j), solRecursive(text1, text2, i, j+1));
        return ans;
    }
    
    int solMemo(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.size() || j == text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MIN;
        if(text1[i]==text2[j]){
            return 1 + solMemo(text1, text2, i+1, j+1, dp);
        }
        ans = 0 + max(solMemo(text1, text2, i+1, j, dp), solMemo(text1, text2, i, j+1, dp));
        dp[i][j] = ans;
        return ans;
    }

    int solTabular(string& text1, string& text2){
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = text1.size()-1; i>=0; i--){
            for(int j = text2.size()-1; j>=0; j--){
                int ans = INT_MIN;
                if(text1[i]==text2[j]){
                    ans =  1 + dp[i+1][j+1];
                }
                else{
                    ans = 0 + max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] =  ans;
            }
        }
        return dp[0][0];
    }


    int longestCommonSubsequence(string text1, string text2) {
        return solTabular(text1, text2);
    }
};