class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        const s_ordered = s.split("").sort().join("");
        const t_ordered = t.split("").sort().join("");

        return s_ordered.localeCompare(t_ordered) === 0;
    }
}
