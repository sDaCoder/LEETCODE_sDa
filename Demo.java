import java.util.ArrayList;

public class Demo {
    public static void main(String[] args) {
        System.out.println("This is the printing of an arrayList: ");
        ArrayList<Boolean> row = new ArrayList<>(6);
        for (int i = 0; i < 6; i++) {
            row.add(false);
        }
        ArrayList<ArrayList<Boolean>> visited = new ArrayList<>(5);
        for (int i = 0; i < 5; i++) {
            visited.add(row);
            System.out.println(visited.get(i));
        }
    }
}
