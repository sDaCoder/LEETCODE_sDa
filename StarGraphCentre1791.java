import java.util.HashMap;
import java.util.Map;

public class StarGraphCentre1791 {

    public static void main(String[] args) {
        int edges[][] = {
            {1, 2}, {2, 3}, {3, 2}
        };
        System.out.println(findCenter(edges));
    }

    static public int findCenter(int[][] edges) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            
            mp.put(u, mp.getOrDefault(u, 0) + 1);
            mp.put(v, mp.getOrDefault(v, 0) + 1);
        }       

        for (int node : mp.keySet()) {
            if(mp.get(node) == edges.length) return node;
        }
        return -1;
    }
}