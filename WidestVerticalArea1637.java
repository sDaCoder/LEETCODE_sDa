// class Solution {
// public:
//     int maxWidthOfVerticalArea(vector<vector<int>>& points) {

//     }
// };

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;

public class WidestVerticalArea1637 {
    Comparator<Integer> comMin = new Comparator<Integer>() {
        public int compare(Integer a, Integer b) {
            if (a > b) return 1; // Ascending order logic
            if (a < b) return -1;
            return 0;
        }
    };
    
    public static void main(String[] args) {
        int points[][] = {
                { 3, 1 }, { 9, 0 }, { 1, 0 }, { 1, 4 }, { 5, 3 }, { 8, 8 }
        };
        // ! TLE Solution
        // PriorityQueue<Integer> PQ = new PriorityQueue<>(); // min heap by default
        // for (int[] point : points) {
        //     if(PQ.contains(point[0])) continue;
        //     PQ.add(point[0]);
        // }
        // int maxDiff = Integer.MIN_VALUE;
        // while (!PQ.isEmpty()) {
        //     int popped = PQ.poll();
        //     int top;
        //     if(PQ.peek() != null) {
        //         top = PQ.peek();
        //     } 
        //     else{
        //         top = popped;
        //     } 
        //     int diff = Math.abs(top - popped);
        //     maxDiff = Math.max(maxDiff, diff);
        // }
        // System.out.println(maxDiff);


        ArrayList<Integer> xCoord = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            xCoord.add(points[i][0]);
        }
        xCoord.sort(comMin);
        int maxDiff = Integer.MIN_VALUE;
        for (int i = 1; i < xCoord.size(); i++) {
            int diff = Math.abs(xCoord.get(i) - xCoord.get(i - 1));
            maxDiff = Math.max(maxDiff, diff);
        }
        System.out.println(maxDiff);
    }
}