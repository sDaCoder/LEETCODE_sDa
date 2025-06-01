import java.util.LinkedList;
import java.util.Queue;

public class Tuple{
    int w, x, y;
    
    Tuple(int w, int x, int y)
    {
        this.w = w; this.x = x; this.y = y;
    }
}

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if (m == 1 && n == 1) return -1;
        if(grid[0][0] == 1) return -1;

        int[][] dist = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = Integer.MAX_VALUE;
                // System.out.print(dist[i][j] + " ");
            }
            // System.out.println();
        }
        dist[0][0] = 0;
        int dxy[][] = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        Queue<Tuple> Q = new LinkedList<>();
        Q.add(new Tuple(0, 0, 0));
        while (!Q.isEmpty()) {
            Tuple T = Q.remove();
            int distance = T.w;
            int x = T.x;
            int y = T.y;

            for (int[] d : dxy) {
                int dx = d[0];
                int dy = d[1];

                if(x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] == 0 && distance + 1 < dist[x + dx][y + dy])
                {
                    dist[x + dx][y + dy] = distance + 1;
                    if(x + dx == m - 1 && y + dy == n - 1) return distance + 2;
                    Q.add(new Tuple(distance + 1, x + dx, y + dy));
                }
            }
        }
        return -1;
    }
}

public class BinaryMaze1091 {
    public static void main(String[] args) {
        // int m = 6;
        // int n = 5;
        // System.out.println(dist);
        
        int grid[][] = {
            {1, 0, 0},
            {1, 1, 0},
            {1, 1, 0}
        };

        // int grid[][] = {
        //     {0, 1},
        //     {1, 0}
        // };
        Solution s = new Solution();
        int dist = s.shortestPathBinaryMatrix(grid);
        System.out.println(dist);
    }
}