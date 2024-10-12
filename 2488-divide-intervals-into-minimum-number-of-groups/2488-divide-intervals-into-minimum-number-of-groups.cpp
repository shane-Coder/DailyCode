class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int start = INT_MAX;
        int end = INT_MIN;
        for (vector<int> interval : intervals) {
            start = min(start, interval[0]);
            end = max(end, interval[1]);
        }

        vector<int> arr(end + 2, 0);
        for (vector<int> interval : intervals) {
            arr[interval[0]]++;
            arr[interval[1] + 1]--;
        }

        int curr = 0;
        int res = 0;
        for (int i = start; i <= end; i++) {
            curr += arr[i];
            res = max(res, curr);
        }
        return res;
    }
};