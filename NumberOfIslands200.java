import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;

class Pair
{
    int x, y;
    Pair(int x, int y)
    {
        this.x = x; this.y = y;
    }
}

public class NumberOfIslands200 {

    ArrayList<ArrayList<Boolean>> visited = new ArrayList<>();
    int directions[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void createArrayList(int rows, int cols)
    {
        for (int i = 0; i < rows; i++) {
            ArrayList<Boolean> row = new ArrayList<>();
            for (int j = 0; j < cols; j++) {
                row.add(false);
            }
            this.visited.add(row);
        }
    }

    public void DFSStack(Pair node, char[][] grid)
    {
        visited.get(node.x).set(node.y, true);
        Deque<Pair> stack = new ArrayDeque<Pair>();
        stack.push(node);
        int rows = grid.length;
        int cols = grid[0].length;

        while (stack.isEmpty() == false) {
            int m = stack.peek().x;
            int n = stack.peek().y;
            stack.pop();

            for (int[] dir : directions) {
                int di = dir[0];
                int dj = dir[1];
                if(
                    m + di >= 0 && m + di < rows && n + dj >= 0 && n + dj < cols &&
                    grid[m + di][n + dj] == '1' && visited.get(m + di).get(n + dj) == false
                ) {
                    Pair P = new Pair(m + di, n + dj);
                    visited.get(m + di).set(n + dj, true);
                    stack.push(P);
                }
            }
        }
    }

    public int numIslands(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        createArrayList(rows, cols);
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && visited.get(i).get(j) == false) {
                    count++;
                    Pair node = new Pair(i, j);
                    DFSStack(node, grid);
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        char[][] grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };
        System.out.println(new NumberOfIslands200().numIslands(grid));
    }
}