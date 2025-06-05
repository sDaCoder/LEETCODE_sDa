
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;


class FrequencyPair{
    int frequency;
    char element;

    public FrequencyPair(int frequency, char element) {
        this.frequency = frequency;
        this.element = element;
    }
}


public class CharFrequencySort451 {

    public static void main(String[] args) {
        String s = "Aabb";
        // System.out.println(s.toCharArray());
        System.out.println(frequencySort(s));
    }

    static public String frequencySort(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char ch : s.toCharArray()) 
        {
            int value = 0;
            if(mp.get(ch) != null) value = mp.get(ch);
            mp.put(ch, value + 1);
        }

        Comparator<FrequencyPair> com = new Comparator<FrequencyPair>() {
            public int compare(FrequencyPair a, FrequencyPair b)
            {
                if(a.frequency > b.frequency) return -1;
                if(a.frequency < b.frequency) return 1;
                if((int)(a.element) < (int)(b.element)) return -1;
                if((int)(a.element) > (int)(b.element)) return 1;
                return 0;
            }
        };
        PriorityQueue<FrequencyPair> pq = new PriorityQueue<>(com);
        for (char ch: mp.keySet()) 
        {
            pq.add(new FrequencyPair(mp.get(ch), ch));
        }
        String res = "";
        while (!pq.isEmpty()) {
            FrequencyPair F = pq.poll();
            char ch = F.element;
            int freq = F.frequency;
            for (int i = 0; i < freq; i++) {
                res += ch;
            }
        }
        return res;
    }
}