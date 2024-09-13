package week6;

import java.util.Scanner;

public class Fibonacci {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int n = 1;
		int m = 1;
		int sum = 1;
		while(m<a){
			sum+=m;
			m+=n;
			n=m-n;
		}
		System.out.println(sum);
	}

}
