
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

class FrequencyPair{
    int frequency, element;

    public FrequencyPair(int frequency, int element) {
        this.frequency = frequency;
        this.element = element;
    }
}

public class KFrequentElements347 {

    public static void main(String[] args) {
        int nums[] = {-1,-1};
        int k = 1;

        for (int element : topKFrequent(nums, k)) {
            System.out.print(element + " ");
        }
    }
    
    static public int[] topKFrequent(int[] nums, int k) {
        Comparator<FrequencyPair> com = new Comparator<FrequencyPair>() {
            public int compare(FrequencyPair a, FrequencyPair b)
            {
                if(a.frequency > b.frequency) return 1;
                if(a.frequency < b.frequency) return -1;
                return 0;
            }
        }; // Comparator for Min HEAP to find the max frequency
        PriorityQueue<FrequencyPair> PQ = new PriorityQueue<>(com);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int num : nums) {
            // int value = mp.get(num);
            int value = 0;
            if(mp.get(num) != null) value = mp.get(num);
            mp.put(num, value + 1);
        }

        for (int key : mp.keySet()) {
            PQ.add(new FrequencyPair(mp.get(key), key));
            if (PQ.size() > k) PQ.poll();
        }

        int res[] = new int[k];
        int i = 0;
        while (!PQ.isEmpty()) {
            FrequencyPair F = PQ.poll();
            res[i] = F.element;
            i++;
        }
        return res;
    }
}