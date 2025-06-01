import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;

class Solution {
    Comparator<Integer> comMin = new Comparator<Integer>() {
        public int compare(Integer a, Integer b)
        {
            if (a > b) return 1; // Ascending order logic
            if (a < b) return -1;
            return 0;
        }
    };

    public int thirdMax(int[] nums) {
        
        HashSet<Integer> HS = new HashSet<>();
        for (Integer num : nums) {
            HS.add(num);
        }
        if(HS.size() == 1) return HS.iterator().next();
        if(HS.size() == 2) {
            Iterator<Integer> it = HS.iterator();
            Integer a = it.next();
            Integer b = it.next();
            return Math.max(a, b);
        }
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(comMin);   
        int k = 3;    
        for (int num : HS) {
            minHeap.add(num);
            if (minHeap.size() > k) {
                int el = minHeap.poll();
            }
        }
        return minHeap.peek();
    }
}

public class ThirdMax {

    public static void main(String[] args) {
        int nums[] = {1, 1, 2};
        Solution S = new Solution();
        System.out.println(S.thirdMax(nums));
        
        HashSet<Integer> HS = new HashSet<>();
        for (Integer num : nums) {
            HS.add(num);
        }
        if(HS.size() == 2) {
            Iterator<Integer> it = HS.iterator();
            Integer a = it.next();
            Integer b = it.next();
            System.out.println(a);
            System.out.println(b);
        }
    }
}