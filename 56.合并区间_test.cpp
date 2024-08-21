/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // 双指针
        int point1 = 0, point2 = 0;
        // 存储结果
        vector<vector<int>> res;
        // 先按照每个区间的首个元素排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

        // 维护两个指针, 收集合并的区间
        point1 = intervals[0][0];
        point2 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // 如果下一个区间的首个元素小于第二个指针, 则合并区间
            if (intervals[i][0] <= point2) {
                point2 = max(point2, intervals[i][1]);
            } else {
                // 否则收集当前两个指针所代表的区间。然后更新两个指针到下一个区间。
                res.push_back({point1, point2});
                point1 = intervals[i][0];
                point2 = intervals[i][1];
            }
        };
        res.push_back({point1, point2});
        return res;
    }
}; // @lc code=end

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = s.merge(intervals);
    for (auto i : res) {
        cout << i[0] << " " << i[1] << endl;
    }
}
