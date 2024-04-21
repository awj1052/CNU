package lab07;

import java.util.*;

class file implements Comparable<file>{
    String name;
    int cnt;
    file(String name){
        this.name = name;
        this.cnt = 1;
    }
    public void add() {
        this.cnt+=1;
    }
    public String toString() {
        return this.name + " " + this.cnt;
    }
    public String getName() {
        return this.name;
    }
    @Override
    public int compareTo(file arg0) {
        return this.name.compareTo(arg0.getName());
    }
}

public class FileExtension {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<file> f = new ArrayList<>();
        loop : for(int i=0; i<n; i++) {
            String[] tmp = sc.nextLine().split("\\.");
            for(int j=0; j<f.size(); j++) {
                if (f.get(j).getName().equals(tmp[1])) {
                    f.get(j).add();
                    continue loop;
                }
            }

            f.add(new file(tmp[1]));

        }

        Collections.sort(f);
        for(file a : f) {
            System.out.println(a);
        }

    }
}