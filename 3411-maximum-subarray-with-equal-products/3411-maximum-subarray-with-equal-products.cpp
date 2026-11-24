class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxsize = 0;

        for (int i = 0; i < n; i++) {
            long long curr_prod = 1;
            long long curr_gcd = nums[i];
            long long curr_lcm = nums[i];

            for (int j = i; j < n; j++) {
                curr_prod *= nums[j];
                curr_gcd = gcd(curr_gcd, (long long)nums[j]);
                curr_lcm = (curr_lcm / gcd(curr_lcm, (long long)nums[j])) * nums[j];

                if (curr_prod == curr_gcd * curr_lcm) {
                    maxsize = max(maxsize, j - i + 1);
                }
                if (curr_prod > curr_gcd * curr_lcm) {
                    break; 
                }
            }
        }
        return maxsize;
    }
};