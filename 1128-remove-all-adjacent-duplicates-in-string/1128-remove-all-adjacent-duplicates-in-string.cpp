class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        int i = 0;
        while(i<s.length()){
            if(res.empty()||res.back()!=s[i]){
                res+=s[i];
            }
            else{
                res.pop_back();
            }
            i++;
        }
        return res;
    }
};