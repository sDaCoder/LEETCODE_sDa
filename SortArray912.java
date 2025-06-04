
import java.util.PriorityQueue;

public class SortArray912 {

    public static void main(String[] args) {
        int nums[] = {5,1,1,2,0,0};
        // System.out.println(sortArray(nums));
        for (int i : sortArray(nums)) System.out.println(i);
    }

    static public int[] sortArray(int[] nums) {
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            PQ.add(nums[i]);
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = PQ.poll();
        }
        return nums;
    }
}