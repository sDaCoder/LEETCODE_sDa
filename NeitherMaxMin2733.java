import java.util.Arrays;

class Solution {
    public int findNonMinOrMax(int[] nums) {
        if(nums.length < 3) return -1;
        Arrays.sort(nums);
        Integer mid = (nums.length - 1) / 2;
        return nums[mid];
    }
}

public class NeitherMaxMin2733 {

    public static void main(String[] args) {
        int nums[] = {2,1,3};
        Solution S = new Solution();
        System.out.println(S.findNonMinOrMax(nums));
    }    
}