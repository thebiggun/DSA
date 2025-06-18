class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(int i = 0; i<s.length(); i++){
            if(res.length()==0) res += s[i];
            else if(res.back()==s[i]){
                res.pop_back();
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};