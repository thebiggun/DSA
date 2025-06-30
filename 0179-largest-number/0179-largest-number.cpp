class Solution {
public:
    static bool cmp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector <string> res;
        for(int n:nums){
            res.push_back(to_string(n));
        }
        sort(res.begin(), res.end(), cmp);
        string ans;
        for(string s:res){
            ans+=s;
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};