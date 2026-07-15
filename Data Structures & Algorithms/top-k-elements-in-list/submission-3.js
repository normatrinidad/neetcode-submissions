class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const frequencies = new Map();
        
        for (let n of nums) {
            if (frequencies.has(n)) {
                const current = frequencies.get(n);
                frequencies.set(n, current + 1);
            } else {
                frequencies.set(n, 1);
            }
        } 
        const frequenciesArray = new Array(nums.length + 1).fill(null);

        for (let [key, value] of frequencies) {
            if (frequenciesArray[value] != null) {
                frequenciesArray[value].push(key);
            } else {
                frequenciesArray[value] = [key];
            }
        }

        let i = nums.length;
        let result = [];
        
        while (k > 0 && i >= 0) {
            if (frequenciesArray[i]?.length) {
                const popped = frequenciesArray[i].pop();
                result.push(popped);
                k--;
            } else {
                i--;
            }
        }

        return result;
    }
}
