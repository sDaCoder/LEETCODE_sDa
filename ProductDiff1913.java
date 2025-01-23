class Solution {
    public int maxProductDifference(int[] nums) {
        int large = Integer.MIN_VALUE, large2 = Integer.MIN_VALUE;
        int small = Integer.MAX_VALUE, small2 = Integer.MAX_VALUE;

        for (int i : nums) {
            if(i >= large)
            {
                large2 = large;
                large = i;
            }
            else if(i >= large2)
            {
                large2 = i;
            }

            if (i <= small) 
            {
                small2 = small;
                small = i;
            }
            else if (i <= small2) 
            {
                small2 = i;
            }
        }
        return ((large2 * large)- (small2 * small));
    }
}

public class ProductDiff1913 {
    public static void main(String[] args) {
        int nums[] = {5,6,2,7,4};
        Solution S = new Solution();
        System.out.println(S.maxProductDifference(nums));
    }
}