import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class DiffPair{
    int difference, element;

    public DiffPair(int difference, int element) {
        this.difference = difference;
        this.element = element;
    }
}

public class KClosestElements658 {

    public static void main(String[] args) 
    {
        int arr[] = {1,2,3,4,5};
        int k = 4, x = 3;
        
        System.out.println(findClosestElements(arr, k, x));    
    }
    
    static public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ans = new ArrayList<>();
        Comparator<DiffPair> com = new Comparator<DiffPair>() {
            public int compare(DiffPair a, DiffPair b)
            {
                if(a.difference > b.difference) return -1;
                if(a.difference < b.difference) return 1;
                if(a.element > b.element) return -1;
                if(a.element < b.element) return 1;
                return 0;
            }
        };
        PriorityQueue<DiffPair> PQ = new PriorityQueue<>(com);
        for (int num : arr) {
            int diff = Math.abs(num - x);
            PQ.add(new DiffPair(diff, num));

            if (PQ.size() > k) PQ.poll();
        }

        while (!PQ.isEmpty()) {
            ans.add(PQ.poll().element);
        }
        Collections.sort(ans);
        return ans;
    }
}