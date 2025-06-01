import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Edge implements Comparable<Edge>
{
    int mhDist;
    int[] p1;
    int[] p2;

    Edge(int mhDist, int[] p1, int[] p2)
    {
        this.mhDist = mhDist;
        this.p1 = p1;
        this.p2 = p2;
    }

    public String toString()
    {
        String s = this.mhDist + " (" + this.p1[0] + ',' + this.p1[1] + ") (" + this.p2[0] + ',' + this.p2[1] + ")";
        return s;
    }

    public int compareTo(Edge that)
    {
        if(this.mhDist > that.mhDist) return 1;
        else if(this.mhDist < that.mhDist) return -1;
        else return 0;
    }
}

class Solution {
    private int findManhattanDistance(int[] p1, int[] p2)
    {
        return (Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]));
    }
    private List<Edge> findEdges(int[][] points) {
        List<Edge> edges = new ArrayList<>();

        for (int i = 0; i < points.length; i++) {
            for(int j = i + 1; j < points.length; j++)
            {
                int mhDist = findManhattanDistance(points[i], points[j]);
                edges.add(new Edge(mhDist, points[i], points[j]));
            }
        }
        Collections.sort(edges);
        return edges;
    }    

    public int minCostConnectPoints(int[][] points) {
        List<Edge> edges = findEdges(points);
        int mstCost = 0;
        DisjointSet ds = new DisjointSet(points);
        for (Edge edge : edges) {
            int mhDist = edge.mhDist;
            int[] p1 = edge.p1;
            int p2[] = edge.p2;

            if (ds.findParent(p1) != ds.findParent(p2)) {
                mstCost += mhDist;
                ds.unionByRank(p1, p2);
            }
        }
        return mstCost;
    }
}

public class ConnectPoints1584 {
    public static void main(String[] args) {
        // int[][] points = {
        //     {0,0},
        //     {2,2},
        //     {3,10},
        //     {5,2},
        //     {7,0}
        // };

        int[][] points = {
            {3, 12},
            {-2, 5},
            {-4, 1}
        };
        Solution S = new Solution();
        System.out.println(S.minCostConnectPoints(points));
        // List<Edge> edges = S.findEdges(points);
        // for (Edge edge : edges) {
        //     System.out.println(edge.toString());
        // }
    }
}