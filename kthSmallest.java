import java.util.Comparator;
import java.util.PriorityQueue;

public class kthSmallest {

    public int findKthSmallest(int[] nums, int k) {

        Comparator<Integer> com = new Comparator<Integer>() {
            public int compare(Integer a, Integer b)
            {
                if(a > b) return -1;
                else if(a < b) return 1; // Ascending order logic
                else return 0;
            }
        };

        PriorityQueue<Integer> heap = new PriorityQueue<>(com);
        for (Integer num : nums) {
            heap.add(num);
            System.out.println("Adding " + num + " to the Queue");
            if (heap.size() > k) {
                int el = heap.poll();
                System.out.println("Removing " + el + " from the Queue");
            }
        }
        return heap.peek();
    }

    public static void main(String[] args) {
        int arr[] = {7, 10, 4, 3, 20, 15};
        int k = 3;
        kthSmallest S = new kthSmallest();
        System.out.println(S.findKthSmallest(arr, k));
    }
}