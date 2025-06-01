import java.util.Arrays;

class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int minIndex = -1;
        int minDist = Integer.MAX_VALUE;

        int i = 0;
        for (int[] point : points) 
        {
            int currX = point[0], currY = point[1];
            if (((Math.abs(currX - x) + Math.abs(currY - y)) < minDist) && (currX == x || currY == y)) 
            {
                minDist = (Math.abs(currX - x) + Math.abs(currY - y));
                minIndex = i;
            }
            i++;
        }
        return minIndex;
    }
}

public class NearestPoint1779 {

    public static void main(String[] args) {
        int points[][] = {
            {1,2},{3,1},{2,4},{2,3},{4,4}
        };
        int x = 3, y = 4;
        Solution S = new Solution();
        System.out.println(S.nearestValidPoint(x, y, points));
    }
}