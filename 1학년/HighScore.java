package lab07;

import java.util.*;

public class HighScore {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<String> p = new ArrayList<>();
        ArrayList<Integer> s = new ArrayList<>();
        ArrayList<Integer> t = new ArrayList<>();
        String[] tmp;
        tmp = sc.nextLine().split(" ");
        loop : while(true) {
            if(tmp[1].equals("?")) {
                int idx = p.indexOf(tmp[0]);
                System.out.println(tmp[0] + " got " + s.get(idx) + " points at " + t.get(idx) + " tries.");
                break;
            }
            else {
                int sc1 = Integer.parseInt(tmp[1]);
                int idx = p.indexOf(tmp[0]);
                if(idx != -1) {
                    t.set(idx, t.get(idx)+1);
                    if(sc1 > s.get(idx)) {
                        s.set(idx, sc1);
                    }
                }else{
                    p.add(tmp[0]);
                    s.add(sc1);
                    t.add(1);
                }
                tmp = sc.nextLine().split(" ");
            }
        }
        sc.close();
    }
}