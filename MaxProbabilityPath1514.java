
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;


class DistNode {
    int node;
    double prob;
    public DistNode(double prob, int node) {
        this.prob = prob;
        this.node = node;
    }
}

public class MaxProbabilityPath1514 {

    public static void main(String[] args) {
        int edges[][] = {
            {0, 1}, {1, 2}, {0, 2}
        };
        double succProb[] = {0.5, 0.5, 0.2};
        int n = 3;
        int start_node = 0;
        int end_node = 2;
        System.out.println(maxProbability(n, edges, succProb, start_node, end_node));
    }

    public static double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        // Creating the Adjacency List
        List<List<DistNode>> adjL = new ArrayList<>();
        for (int i = 0; i < n; i++) adjL.add(new ArrayList<>());
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];

            adjL.get(u).add(new DistNode(prob, v));
            adjL.get(v).add(new DistNode(prob, u));
        }

        // Creating the Memoization Array
        double probMatrix[] = new double[n];
        probMatrix[start_node] = 1;

        Comparator<DistNode> com = (a, b) -> Double.compare(b.prob, a.prob);
        PriorityQueue<DistNode> Q = new PriorityQueue<>(com);
        Q.add(new DistNode(probMatrix[start_node], start_node));
        while (!Q.isEmpty()) {
            DistNode poppedNode = Q.poll();
            int currNode = poppedNode.node;
            double currProb = poppedNode.prob;

            for (DistNode adj : adjL.get(currNode)) {
                int adjNode = adj.node;
                double adjNodeProb = adj.prob;

                if(currProb * adjNodeProb > probMatrix[adjNode]) 
                {
                    probMatrix[adjNode] = currProb * adjNodeProb;
                    Q.add(new DistNode(probMatrix[adjNode], adjNode)); 
                }
            }
        }

        return probMatrix[end_node];
    }
}