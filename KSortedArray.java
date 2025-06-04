
import java.util.PriorityQueue;

public class KSortedArray {
    public static void main(String[] args) {
        int arr[] = {6, 5, 3, 2, 8, 10, 9};
        int k = 3;
        nearlySorted(arr, k);   
        for (int el : arr) {
            System.out.print(el + " ");
        }
    }

    static public void nearlySorted(int[] arr, int k) {
        // code here
        int res[] = new int[arr.length];
        int i = 0;
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        for (int num : arr) {
            PQ.add(num);
            if(PQ.size() > k)
            {
                res[i] = PQ.poll();
                i++;
            }
        }

        while (!PQ.isEmpty()) {
            res[i] = PQ.poll();
            i++;
        }

        System.arraycopy(res, 0, arr, 0, res.length); // One liner to copy all the elements from one array to the other
        
        // for (int j = 0; j < res.length; j++) {
        //     arr[j] = res[j];
        // }
    }
}
