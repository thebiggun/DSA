class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge = "";
        int i = 0, j = 0;
        int k = 0;
        while(i!=word1.size() && j!=word2.size()){
            if(k%2==0){
                merge+=word1[i++];
            }
            else{
                merge+=word2[j++];
            }
            k++;
        }
        while(i<word1.size()){
            merge+=word1[i++];
        }
        while(j<word2.size()){
            merge+=word2[j++];
        }
        return merge;
    }
};