package lab04;

import java.util.*;

public class p1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> arr = new ArrayList<>();
        for (String t: sc.nextLine().split(" ")){
            arr.add(t);
        }
        int loop = Integer.parseInt(sc.nextLine());
        for (int i=0; i<loop; i++){
            String[] cmd = sc.nextLine().split(" ");
            if (cmd[0].equals("A")){
                arr.add(Integer.parseInt(cmd[1]), cmd[2]);
            }else if (cmd[0].equals("D")){
                arr.remove(Integer.parseInt(cmd[1]));
            }
        }
        for (String a : arr){
            System.out.print(a+" ");
        }
    }
}