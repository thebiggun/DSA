class Solution {
public:
    string decodeMessage(string key, string message) {
        int flag = 0;
        string no_space = "";
        for(char c: key){
            if(c!=' '){
                no_space += c;
            }
        }
        unordered_map<char, char> m;
        for(char c:no_space){
            if(m.find(c)==m.end()){
                m[c] = 'a' + flag;
                flag++;
            }
        }
        no_space = "";
        for(char c:message){
            if(c == ' '){
                no_space += ' ';
            }
            else if(m.find(c)!=m.end()){
                no_space += m[c];
            }
        }
        return no_space;
    }
};