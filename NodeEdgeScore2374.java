
import java.util.HashMap;

public class NodeEdgeScore2374 {

    public static void main(String[] args) {
        int edges[] = {25,27,27,21,39,30,38,17,36,23,23,2,34,39,11,36,15,29,35,36,39,3,30,29,33,0,33,21,41,21,36,36,35,35,19,36,42,19,28,11,44,11,30,6,11};
        // int edges[] = {2, 0, 0, 2};
        System.out.println(edgeScore(edges));
        // HashMap<Integer, Long> edge_score = new HashMap<>();
        // for (int i = 0; i < edges.length; i++) {
        //     long score = edge_score.getOrDefault(edges[i], 0L);
        //     edge_score.put(edges[i], score + i);
        // }
        // for (int key : edge_score.keySet()) {
        //     System.out.println(key + " " + edge_score.get(key));
        // }
    }
    
    static public int edgeScore(int[] edges) {
        HashMap<Integer, Long> edge_score = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            long score = edge_score.getOrDefault(edges[i], 0L);
            edge_score.put(edges[i], score + i);
        }
        Long maxEdgeScore = Long.MIN_VALUE;
        int resNode = 0;
        for (int key : edge_score.keySet()) {
            // System.out.println(key + " " + edge_score.get(key));
            if (edge_score.get(key) > maxEdgeScore) {
                maxEdgeScore = edge_score.get(key);
                resNode = key;
            }
            else if(edge_score.get(key).equals(maxEdgeScore))
            {
                resNode = Math.min(resNode, key);
            }
        }
        return resNode;

    }
}