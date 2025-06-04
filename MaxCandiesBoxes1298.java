import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> Q = new LinkedList<>();
        boolean[] visited = new boolean[status.length];
        Q.add(initialBoxes[0]);
        visited[initialBoxes[0]] = true;
        int collectedCandies = 0;

        while(!Q.isEmpty())
        {
            int poppedBox = Q.poll();
            collectedCandies += candies[poppedBox];

            for (int i = 0; i < keys[poppedBox].length; i++) {
                if (!visited[keys[poppedBox][i]]) {
                    visited[keys[poppedBox][i]] = true;
                    Q.add(keys[poppedBox][i]);
                }
            }
        }

        return collectedCandies;   
    }
}

public class MaxCandiesBoxes1298 {

    public static void main(String[] args) {
        int[] status = {1, 0, 1, 0};
        int[] candies = {7, 4, 5, 100};
        int[][] keys = {
            {}, {}, {1}, {}
        };
        int[][] containedBoxes = {
            {1, 2}, {3}, {}, {}
        };
        int[] initialBoxes = {0};
        Solution S = new Solution();
        System.out.println(S.maxCandies(status, candies, keys, containedBoxes, initialBoxes));
    }
}