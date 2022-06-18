package Java;

import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) {
            return Arrays.asList();
        }
        Arrays.sort(nums);
        Set<String> st = new HashSet<String>();
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for (int i = 0; i < nums.length - 2; ++i) {
            int target = -nums[i];
            int left = i+1, right = nums.length - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    List<Integer> tmpl = Arrays.asList(-target, nums[left], nums[right]);
                    String tmps = tmpl.toString();
                    if (!st.contains(tmps)) {
                        st.add(tmps);
                        ans.add(tmpl);
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
}
