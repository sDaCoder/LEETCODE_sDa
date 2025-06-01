import java.util.Comparator;
import java.util.PriorityQueue;

public class Tuple{
    int w, x, y;
    
    Tuple(int w, int x, int y)
    {
        this.w = w; this.x = x; this.y = y;
    }
}
class Solution {
    public int minimumEffortPath(int[][] heights) {
        Comparator<Tuple> com = new Comparator<Tuple>() {
            public int compare(Tuple x, Tuple y)
            {
                if(x.w > y.w) return 1;
                else if(x.w < y.w) return -1;
                else return 0;
            }
        };
        PriorityQueue<Tuple> PQ = new PriorityQueue<>(com);
        int m = heights.length;
        int n = heights[0].length;
        int effort[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                effort[i][j] = Integer.MAX_VALUE;
            }
        } 
        effort[0][0] = 0;

        PQ.add(new Tuple(0, 0, 0));
        int dxy[][] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!PQ.isEmpty()) {
            Tuple T = PQ.remove();
            int diff = T.w;
            int row = T.x;
            int col = T.y;
            
            if(row == m - 1 && col == n - 1) return diff;
            for (int[] dir : dxy) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newEffort = Math.max(diff, Math.abs(heights[newRow][newCol] - heights[row][col]));
                    if(newEffort < effort[newRow][newCol])
                    {
                        effort[newRow][newCol] = newEffort;
                        PQ.add(new Tuple(newEffort, newRow, newCol));
                    }
                }
            }

        }
        return 0;
    }
}

public class PathMinEffort1631 {


    public static void main(String[] args) {
        int heights[][] = {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}
        };
        System.out.println(new Solution().minimumEffortPath(heights));
    }
}