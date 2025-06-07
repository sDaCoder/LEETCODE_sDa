
public class CitySmallestNeighbours1334 {

    public static void main(String[] args) {
        int n = 4;
        int edges[][] = {
            {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}
        };
        int distanceThreshold = 4;
        for (int[] rows : findTheCity(n, edges, distanceThreshold)) {
            for (int el : rows) {
                System.out.print(el + " ");
            }
            System.out.println();
        }
    }

    public static int[][] findTheCity(int n, int[][] edges, int distanceThreshold) {
        int distMatrix[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distMatrix[i][j] = Integer.MAX_VALUE;
                if (i == j) {
                    distMatrix[i][j] = 0;
                }
            }
        }
        for (int[] edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];
            distMatrix[src][dest] = wt;
            distMatrix[dest][src] = wt;
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distMatrix[i][via] != Integer.MAX_VALUE && distMatrix[via][j] != Integer.MAX_VALUE) {
                        distMatrix[i][j] = Math.min(distMatrix[i][j], distMatrix[i][via] + distMatrix[via][j]);
                    }
                }
            }
        }
        return distMatrix;
    }
}
