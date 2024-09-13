package week6;

import java.util.Scanner;

public class Star_Pyramid {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int n;
		int m;
		for(n=0;n<a;n++){
			for(m=0;m<a-1-n;m++){
				System.out.print(" ");
			}
			for(m=0;m<2*n+1;m++){
				System.out.print("*");
			}
			for(m=0;m<a-1-n;m++){
				System.out.print(" ");
			}
			System.out.print("\n");
		}
	}

}
