// 41. First Missing Positive

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Constraints:

// 1 <= nums.length <= 10^5
// -2^31 <= nums[i] <= 2^31 - 1

#define FALSE 0
#define TRUE !(FALSE)

int firstMissingPositive(int* nums, int numsSize) {
    // In-place hash method - assign array values to their indexes by swapping them with the index at their value - 1
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    // If the value at an index is not equal to its index + 1, then that index + 1 is the smallest positive integer not included in the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If none of these are true, it must be one higher as every space is filled with its appropriate index value
    return numsSize + 1;
}