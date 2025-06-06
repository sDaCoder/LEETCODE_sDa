
import java.util.Arrays;
import java.util.HashMap;

public class FrequentEven2404 {

    public static void main(String[] args) {
        int nums[] = {4369,3347,7166,1792,9101,6887,4418,7038,5287,1630,9023,1368,8972,8092,1120,7050,8661,1297,3013,4504,9578,9399,6196,2383,8801,2120};
        Arrays.sort(nums);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int num : nums) {
            if (num % 2 == 0) {
                mp.put(num, mp.getOrDefault(num, 0) + 1);
            }
        }

        int max = Integer.MIN_VALUE;
        int res = -1;
        for (int key : mp.keySet()) {
            if (mp.get(key) > max) {
                max = mp.get(key);
                res = key;
            }
            else if (mp.get(key) == max) {
                res = Math.min(res, key);
            }
        }
        System.out.println(res);
        // Math.floorDiv(max, res)
    }
}