package week7;

import java.util.Scanner;

public class Sieve {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st[] = sc.nextLine().split(" ");
		int num[] = new int[st.length];
		for(int i=0;i<st.length;i++){
			num[i] = Integer.parseInt(st[i]);
		}
		count : for(int i=1;i<51;i++){
			for(int j=0;j<st.length;j++){
				if(i%num[j]==0){
					continue count;
				}
			}
			System.out.print(i+" ");
		}
	}

}
