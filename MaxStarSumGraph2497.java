
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;



public class MaxStarSumGraph2497 {

    public static void main(String[] args) {
        int edges[][] = {
            {0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}
        };
        int k = 2;
        int vals[] = {1,2,3,4,10,-10,-20};
        System.out.println(maxStarSum(vals, edges, k));
    }

    static public int maxStarSum(int[] vals, int[][] edges, int k) {
        int n = vals.length;
        List<List<ValueNode>> adjL = new ArrayList<>();
        for (int i = 0; i < n; i++) adjL.add(new ArrayList<>());
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adjL.get(u).add(new ValueNode(vals[v], v));
            adjL.get(v).add(new ValueNode(vals[u], u));
        }

        Comparator<ValueNode> com = (a, b) -> Integer.compare(a.value, b.value);
        int maxSum = Integer.MIN_VALUE, i = 0;
        PriorityQueue<ValueNode> PQ = new PriorityQueue<>(com);
        for (List<ValueNode> rows : adjL) {
            int starSum = vals[i];
            i++;
            for (ValueNode valueNode : rows) {
                int node = valueNode.node, value = valueNode.value;
                PQ.add(new ValueNode(value, node));

                if (PQ.size() > k) PQ.poll();
            }
            while (!PQ.isEmpty()) {
                ValueNode V = PQ.poll();
                starSum += V.value;
            }
            maxSum = Math.max(starSum, maxSum);
        }
        return maxSum;
    }
}

class ValueNode
{
    int value, node;

    public ValueNode(int value, int node) {
        this.value = value;
        this.node = node;
    }
}