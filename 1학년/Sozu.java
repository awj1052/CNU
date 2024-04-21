package lab07;

import java.util.*;

public class Sozu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] sizes = sc.nextLine().split(" ");
        int upperSize = Integer.parseInt(sizes[0]);
        int lowerSize = Integer.parseInt(sizes[1]);
        String[] input = sc.nextLine().split("");
        sc.close();

        Queue<String> upper = new LinkedList<>();
        Stack<String> lower = new Stack<>();
        boolean flag = false; // 아래 false 위 true

        for(int i=0; i<input.length; i++) {
            if(input[i].equals("0")) {
                flag=!flag;
                if(!flag) {
                    while(lower.size()>0) {
                        System.out.print(lower.pop());
                    }
                }
                continue;
            }

            upper.add(input[i]);
            if (upper.size() > upperSize) {
                String polled = upper.poll();

                if(!flag) {
                    System.out.print(polled);
                    continue;
                }

                if (lower.size() < lowerSize) {
                    lower.add(polled);
                }else {
                    System.out.print(polled);
                }

            }
        }
    }
}