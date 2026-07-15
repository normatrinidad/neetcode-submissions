class Solution {

    getFingerprint(str) {
        const zero = 'a'.charCodeAt(0);
        const l = 'z'.charCodeAt(0) - zero;
        const arr = new Array(l).fill(0);

        for (let c of str) {
            arr[c.charCodeAt(0) - zero] = arr[c.charCodeAt(0) - zero] + 1;
        }

        return arr.join("-");
    }
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const map = new Map();

        for (let str of strs) {
            const fingerprint = this.getFingerprint(str);

            if (map.has(fingerprint)) {
                const current = map.get(fingerprint);
                current.push(str)
                map.set(fingerprint, current)
            } else {
                map.set(fingerprint, [str])    
            }
        }

        const result = [];

        for (const [key, value] of map.entries()) {
            result.push(value);
        }

        return result;

    }


    
}
