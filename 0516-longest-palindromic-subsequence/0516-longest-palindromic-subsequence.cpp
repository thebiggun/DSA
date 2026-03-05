class Solution {
public:
int solOptimal1(string& text1, string& text2){
        vector<int> next(text2.size()+1, 0);
        vector<int> curr(text2.size()+1, 0);
        for(int i = text1.size()-1; i>=0; i--){
            for(int j = text2.size()-1; j>=0; j--){
                int ans = INT_MIN;
                if(text1[i]==text2[j]){
                    ans =  1 + next[j+1];
                }
                else{
                    ans = 0 + max(next[j], curr[j+1]);
                }
                curr[j] =  ans;
            }
            next = curr;
        }
        return curr[0];
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        return solOptimal1(a,s);
    }
};