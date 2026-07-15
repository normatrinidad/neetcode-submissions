class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const map = {};

        for (let i = 0; i < nums.length; i++) {
            const subs = target - nums[i];
            if (map[subs] === undefined) {
                map[nums[i]] = i;
            } else {
                return [map[subs], i];
            }
        }
    }
}
