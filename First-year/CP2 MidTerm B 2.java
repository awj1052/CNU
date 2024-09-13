package lab07;

import java.util.*;

public class Conference {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] tmp = sc.nextLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int k = Integer.parseInt(tmp[1]);

        LinkedList<String> p = new LinkedList<>();
        for(int i=0; i<N; i++){
            p.add(sc.nextLine());
        }
        int c = k-1;
        while(p.size()>0){
            if (c >= p.size()){
                c%=p.size();
            }
            System.out.print(p.remove(c) + " ");
            c+=k-1;
        }

    }

}
