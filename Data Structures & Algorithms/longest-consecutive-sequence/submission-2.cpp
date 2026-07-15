class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() == 0) {
            return 0;
        }

        int max = 1;
        int pivot = 1;

        int local_max = 1;
        while (pivot < nums.size()) {
            int difference = nums[pivot] - nums[pivot - 1];
            if (difference == 1) {
                local_max++;
            } else if (difference != 0) {
                if (local_max > max) {
                    max = local_max;
                }
                local_max = 1;
            }
            pivot++;
        }

              
        return local_max > max ? local_max : max;
    }
};
