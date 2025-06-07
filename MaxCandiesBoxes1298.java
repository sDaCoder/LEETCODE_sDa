import java.util.LinkedList;
import java.util.Queue;

public class MaxCandiesBoxes1298 {
    static public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> Q = new LinkedList<>();
        boolean[] visitedBoxes = new boolean[status.length];
        boolean[] hasKeys = new boolean[keys.length];
        boolean[] hasBoxes = new boolean[containedBoxes.length];

        for (int box : initialBoxes) {
            if(status[box] == 1)
            {
                Q.add(box);
                visitedBoxes[box] = true;
            }
        }
        
        int collectedCandies = 0;
        while(!Q.isEmpty())
        {
            int poppedBox = Q.poll();
            collectedCandies += candies[poppedBox];
            // System.out.println("Adding " + candies[poppedBox] + " candies " + "from box " + poppedBox);

            // Get the keys from the popped box
            for(int key: keys[poppedBox])
            {
                hasKeys[key] = true;
                if(!visitedBoxes[key] && hasKeys[key] == true)
                {
                    Q.add(key);
                    visitedBoxes[key] = true;
                }
            }
            
            // Adding the contained boxes which has the keys
            for (int box : containedBoxes[poppedBox]) {
                hasBoxes[box] = true;
                if((status[box] == 1 || hasKeys[box]) && !visitedBoxes[box])
                {
                    Q.add(box);
                    visitedBoxes[box] = true;
                }
            }
        }
        return collectedCandies;   
    }

    public static void main(String[] args) {
        int[] status = {1,1,1};
        int[] candies = {100, 1, 100};
        int[][] keys = {
            {}, {0, 2}, {}
        };
        int[][] containedBoxes = {
            {}, {}, {}
        };
        int[] initialBoxes = {1};
        System.out.println(maxCandies(status, candies, keys, containedBoxes, initialBoxes));
    }
}