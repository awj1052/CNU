package lab04;

import java.util.*;

public class p2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        String tmp="";
        if(sc.hasNext()){
            tmp = sc.nextLine();
        }else{
            System.out.println("VALID");
            return;
        }
        sc.close();
        if (tmp.equals("")){
            System.out.println("VALID");
            return;
        }
        int cnt = 0;
        for (String t : tmp.split("")){
            if (t.equals("(")){
                stack.add(1);
            }else{
                if (stack.size() == 0){
                    System.out.println("INVALID");
                    return;
                }
                if (!stack.pop().equals(1)){
                    System.out.println("INVALID");
                    return;
                }
            }
        }
        if (stack.size() == 0){
            System.out.println("VALID");
        }else{
            System.out.println("INVALID");
        }
    }
}