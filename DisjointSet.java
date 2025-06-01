import java.util.*;
public class DisjointSet {
    private List<Integer> rank = new ArrayList<>();
    private List<Integer> parent = new ArrayList<>();
    private List<Integer> size = new ArrayList<>();

    private Map<String, String> parentMap = new HashMap<>();
    private Map<String, Integer> rankMap = new HashMap<>();
    private Map<String, Integer> sizeMap = new HashMap<>();
    
    DisjointSet(int n)
    {
        for (int i = 0; i <= n; i++) {
            rank.add(0);
            parent.add(i);
            size.add(1);
        }
    }

    // Overloaded: initialize for int[] nodes
    DisjointSet(int[][] points) {
        for (int[] point : points) addNode(point);
    }

    private void addNode(int[] node) {
        String key = key(node);
        parentMap.put(key, key);
        rankMap.put(key, 0);
        sizeMap.put(key, 1);
    }

    private String key(int[] node) {
        return node[0] + "," + node[1];
    }
    
    void getRank()
    {
        System.out.print("Rank Array (1-indexed): ");
        System.out.println(this.rank.subList(1, this.rank.size()));
    }
    
    void getParent()
    {
        System.out.print("Parent Array (1-indexed):");
        System.out.println(this.parent.subList(1, this.parent.size()));
    }
    
    int findParent(int node)
    {
        if(node != parent.get(node))
        {
            parent.set(node, findParent(parent.get(node)));
            // return parent.get(node);
        }
        return parent.get(node);
    }

    // Overloaded: findParent for int[] node
    public String findParent(int[] node) {
        String k = key(node);
        if (!parentMap.get(k).equals(k)) {
            parentMap.put(k, findParent(strToArr(parentMap.get(k))));
        }
        return parentMap.get(k);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v) return;

        if (rank.get(ulp_u) < rank.get(ulp_v)) 
        {
            parent.set(ulp_u, ulp_v);
        }
        else if (rank.get(ulp_u) > rank.get(ulp_v)) 
        {
            parent.set(ulp_v, ulp_u);
        } 
        else 
        {
            parent.set(ulp_v, ulp_u);
            int rankU = rank.get(ulp_u);
            rank.set(ulp_u, rankU + 1);
        }
    }

    // Overloaded: unionByRank for int[] nodes
    public void unionByRank(int[] u, int[] v) {
        String pu = findParent(u);
        String pv = findParent(v);
        if (pu.equals(pv)) return;

        int rankU = rankMap.get(pu);
        int rankV = rankMap.get(pv);

        if (rankU < rankV) {
            parentMap.put(pu, pv);
        } else if (rankU > rankV) {
            parentMap.put(pv, pu);
        } else {
            parentMap.put(pv, pu);
            rankMap.put(pu, rankU + 1);
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;
        int sizeU = size.get(ulp_u);
        int sizeV = size.get(ulp_v);
        if(sizeU < sizeV)
        {
            parent.set(ulp_u, ulp_v);
            size.set(ulp_v, sizeV + sizeU);
        }
        else
        {
            parent.set(ulp_v, ulp_u);
            size.set(ulp_u, sizeV + sizeU);
        }
    }

    // Overloaded: unionBySize for int[] nodes
    public void unionBySize(int[] u, int[] v) {
        String pu = findParent(u);
        String pv = findParent(v);
        if (pu.equals(pv)) return;

        int sizeU = sizeMap.get(pu);
        int sizeV = sizeMap.get(pv);

        if (sizeU < sizeV) {
            parentMap.put(pu, pv);
            sizeMap.put(pv, sizeU + sizeV);
        } else {
            parentMap.put(pv, pu);
            sizeMap.put(pu, sizeU + sizeV);
        }
    }

    // Utility to convert string key back to int[]
    private int[] strToArr(String s) {
        String[] parts = s.split(",");
        return new int[]{Integer.parseInt(parts[0]), Integer.parseInt(parts[1])};
    }
    
}