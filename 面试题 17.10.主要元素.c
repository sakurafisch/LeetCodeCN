// 摩尔投票算法
int majorityElement(int* nums, int numsSize){
    int major = nums[0], count = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == major) {
            ++count;
        }
        else {
            if (count > 0)
                --count;
            else {
                major = nums[i];
                count = 1;
            } 
        }
    }
    if (count > 0) {
        count = 0;
        for (int i = 0; i < numsSize; ++i)
            if (nums[i] == major)
                ++count;
    }
    if (count > numsSize / 2) return major;
    else return -1;
}
