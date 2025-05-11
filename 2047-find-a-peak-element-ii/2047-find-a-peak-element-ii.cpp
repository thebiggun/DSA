class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int j){
        // finding jth midth column's columun wise max element
        int maxi = INT_MIN;
        int index = -1;
        for(int i = 0; i<n;++i){
            if(mat[i][j] > maxi){
                maxi = mat[i][j];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0, e = m - 1; // cols wise
        while(s <= e){
            int mid = (s + e) / 2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            // now my approach deduced to 1D sort of thinking
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : INT_MIN;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex, mid};
            else if(mat[maxRowIndex][mid] < left)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return {};
    }
};