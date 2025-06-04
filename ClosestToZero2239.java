public class ClosestToZero2239 {

    public static int findClosestNumber(int[] nums) {
        int closest = Integer.MAX_VALUE;
        int res = -1;
        for (int num : nums) {
            if (Math.abs(num) < closest) {
                closest = Math.abs(num);
                res = num;
            }
            else if(Math.abs(num) == closest)
            {
                res = Math.max(res, num);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int nums[] = {2,-1,1};
        System.out.println(findClosestNumber(nums));
    }
}