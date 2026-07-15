class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> result(nums.size());

        for (auto i = 0; i < nums.size(); i++) {
            int prev = i == 0 ? 1 : prefix[i-1];
            prefix[i] = prev * nums[i];
        }

        int prod = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int pref = i == 0 ? 1 : prefix[i - 1];
            result[i] =  pref * prod;
            prod*=nums[i];
        }

        return result;
    }
};
