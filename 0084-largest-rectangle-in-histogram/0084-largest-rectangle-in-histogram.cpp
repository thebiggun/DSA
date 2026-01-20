class Solution {
public:
    void nextSmaller(vector<int>& heights, vector<int>& next){
        stack <int> st;
        st.push(-1);
        int n = heights.size();
        for(int i = n-1; i>=0; i--){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
        reverse(next.begin(), next.end());
    }

    void prevSmaller(vector<int>& heights, vector<int>& prev){
        stack <int> st;
        st.push(-1);
        int n = heights.size();
        for(int i = 0; i<n; i++){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next;
        vector<int> prev;
        nextSmaller(heights, next);
        prevSmaller(heights, prev);
        for(int i = 0; i<next.size(); i++){
            if(next[i]==-1){
                next[i] = heights.size();
            }
        }
        int ans = 0;
        for(int i = 0; i<heights.size(); i++){
            int w = next[i]-prev[i]-1;
            if(ans<w*heights[i]){
                ans = w*heights[i];
            }
        }
        return ans;
    }
};