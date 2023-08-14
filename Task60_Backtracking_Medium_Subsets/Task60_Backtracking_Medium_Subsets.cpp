#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;

    void subset_edit(std::vector<int> tmp, std::vector<int>& nums, int n, int m) {
        result.push_back(tmp);
        if (tmp.size() == nums.size()) {
            return;
        }
        for (int i = m;i < nums.size();i++) {
            if (i == m)
                tmp.push_back(nums[i]);
            else
                tmp[tmp.size() - 1] = nums[i];
            subset_edit(tmp, nums, n + 1, i + 1);
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        subset_edit({}, nums, 1, 0);
        return result;
    }
};