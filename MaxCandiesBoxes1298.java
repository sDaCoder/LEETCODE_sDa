import java.util.LinkedList;
import java.util.Queue;

public class MaxCandiesBoxes1298 {
    static public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> Q = new LinkedList<>();
        boolean[] visitedBoxes = new boolean[status.length];
        for (int box : initialBoxes) {
            Q.add(box);
            visitedBoxes[box] = true;
        }
        int collectedCandies = 0;
    
        while(!Q.isEmpty())
        {
            int poppedBox = Q.poll();
            if(status[poppedBox] == 0) continue;
            collectedCandies += candies[poppedBox];
            System.out.println("Adding " + candies[poppedBox] + " candies " + "from box " + poppedBox);

            for(int box: containedBoxes[poppedBox])
            {
                if(!visitedBoxes[box] && (status[box] == 1))
                {
                    System.out.println("Adding box " + box + " to queue");
                    Q.add(box);
                    visitedBoxes[box] = true;
                }
            }
            
            for(int box: keys[poppedBox])
            {
                status[box] = 1;
                if(!visitedBoxes[box])
                {
                    System.out.println("Adding box " + box + " to queue");
                    Q.add(box);
                    visitedBoxes[box] = true;
                }
            }
        }
    
        return collectedCandies;   
    }

    public static void main(String[] args) {
        int[] status = {1, 0, 1, 0};
        int[] candies = {7, 5, 4, 100};
        int[][] keys = {
            {}, {}, {1}, {}
        };
        int[][] containedBoxes = {
            {1, 2}, {3}, {}, {}
        };
        int[] initialBoxes = {0};
        System.out.println(maxCandies(status, candies, keys, containedBoxes, initialBoxes));
    }
}