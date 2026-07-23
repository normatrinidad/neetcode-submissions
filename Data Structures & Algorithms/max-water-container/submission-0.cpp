class Solution {
public:
    int maxArea(vector<int>& heights) {
        int begin = 0;
        int end = heights.size() - 1;
        int max = 0;

        while(begin < end) {
            int distance = end - begin;
            int min_height = min(heights[begin], heights[end]);
            int area = min_height * distance;
            if (area > max) {
                max = area;
            }

            if (heights[begin] < heights[end]) {
                begin++;
            } else {
                end--;
            }
        }

        return max;
    }
};
