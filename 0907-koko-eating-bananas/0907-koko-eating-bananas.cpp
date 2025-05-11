class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long count = 0;

            for (int pile : piles) {
                count += (pile + mid - 1) / mid; // avoids branching (ceil)
            }

            if (count <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
