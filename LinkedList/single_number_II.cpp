//Add bitwise counting solution for LeetCode 137 (Single Number II)
//Counts set bits at each of the 32 positions across all numbers;
//since triplicated values contribute 0 mod 3 per bit, the remaining
//bits (count % 3 != 0) reconstruct the single unique number.
//Time: O(32n), Space: O(1)

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        int bitSum = 0;
        for (int num : nums) {
            bitSum += (num >> i) & 1;
        }
        if (bitSum % 3 != 0) {
            result |= (1 << i);
        }
    }
    return result;
}