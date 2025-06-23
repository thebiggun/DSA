class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int center = 0; center<s.length(); center++){
            int i = center;
            int j = center;
            while(i>=0 && j<s.length() && s[i]==s[j]){
                count++;
                i--;
                j++;
            }
            i = center;
            j = center+1;
            while(i>=0 && j<s.length() && s[i]==s[j]){
                count++;
                i--;
                j++;
            }
        }
        return count;
    }
};