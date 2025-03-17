public class DivideArr2206 {
    public boolean divideArray(int[] nums) {
        int arr[] = new int[501];
        for (int num : nums) {
            arr[num]++;
        }

        for (int j = 0; j <= 500; j++)
        {
            if(arr[j] % 2 != 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int nums[] = {1, 2, 3, 4};
        System.out.println(new DivideArr2206().divideArray(nums));
    }
}