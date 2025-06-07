
import java.util.HashMap;

public class InterchangeableRectangles2001 {

    public static void main(String[] args) {
        int[][] rectangles = {
            {4, 8}, {3, 6}, {10, 20}, {15, 30}
        };
        System.out.println(interchangeableRectangles(rectangles));
    }

    static public long interchangeableRectangles(int[][] rectangles) {
        HashMap<Double, Integer> map = new HashMap<>();
        long count = 0;
        for (int[] rectangle : rectangles) {
            double ratio = (double) rectangle[0] / rectangle[1];
            count += map.getOrDefault(ratio, 0);
            map.put(ratio, map.getOrDefault(ratio, 0) + 1);
        }
        return count;   
    }
}