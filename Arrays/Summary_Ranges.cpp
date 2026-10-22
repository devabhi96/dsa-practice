// LeetCode 228: Summary Ranges
// Approach: Linear Traversal
// Logic: Track the starting index of each range. When consecutive numbers break,
// add the previous range to the result and start a new range.
// Handle single-element ranges separately and add the final range after the loop.
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary space (excluding the output).

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == i - 1)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));

                start = i;
            }
        }

        if (start == nums.size() - 1 && !nums.empty())
            ans.push_back(to_string(nums[start]));
        else if (!nums.empty())
            ans.push_back(to_string(nums[start]) + "->" + to_string(nums.back()));

        return ans;
    }
};