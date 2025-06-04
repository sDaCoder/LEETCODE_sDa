// https://leetcode.com/problems/k-closest-points-to-origin/description/

import java.util.Comparator;
import java.util.PriorityQueue;

// class Solution {
//     public int[][] kClosest(int[][] points, int k) {

//     }
// }

public class KClosestPoints973 {

    public static void main(String[] args) {
        int points[][] = {
                { 2, 2 }, { 2, 2 }, { 3, 3 }, { 2, -2 }, { 1, 1 }
        };
        int k = 4;

        Comparator<Integer[]> comMinDist = new Comparator<Integer[]>() {
            @Override
            public int compare(Integer[] a, Integer[] b) {
                int distA = a[0] * a[0] + a[1] * a[1];
                int distB = b[0] * b[0] + b[1] * b[1];
                if (distA > distB) return -1;
                if (distA < distB) return 1;
                return 0;
            }
        };
        PriorityQueue<Integer[]> PQ = new PriorityQueue<>(comMinDist); // max Heap
        for (int[] point : points) 
        {
            Integer[] boxedPoint = new Integer[] { point[0], point[1] };
            PQ.add(boxedPoint);

            if (PQ.size() > k) PQ.poll();
        }

        int res[][] = new int[k][2];
        int i = 0;
        while (!PQ.isEmpty()) {
            Integer[] point = PQ.poll();
            int px = point[0];
            int py = point[1];
            res[i] = new int[] { px, py };
            // System.out.println("[" + px + ", " + py + "]");
            System.out.println("[" + res[i][0] + ", " + res[i][1] + "]");
            i++;
        }

        // for (int[] point : res) {
        //     System.out.println("[" + point[0] + ", " + point[1] + "]");
        // }
    }
}