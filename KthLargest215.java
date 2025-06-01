import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        Comparator<Integer> comMin = new Comparator<Integer>() {
            public int compare(Integer a, Integer b)
            {
                if (a > b) return 1; // Ascending order logic
                if (a < b) return -1;
                return 0;
            }
        };
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(comMin);       
        for (int num : nums) {
            minHeap.add(num);
            System.out.println("Adding " + num + " to the Queue");
            if (minHeap.size() > k) {
                int el = minHeap.poll();
                System.out.println("Removing " + el + " from the Queue");
            }
        }
        return minHeap.peek();
    }
}

public class KthLargest215 {
    public static void main(String[] args) {
        int arr[] = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        Solution S = new Solution();
        System.out.println(S.findKthLargest(arr, k));
    }
}