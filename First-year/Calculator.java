package week3;

import java.util.Scanner;

public class Calculator {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int b = i.nextInt();
		System.out.println(a+b);
		System.out.println(a-b);
		System.out.println(a*b);
		System.out.print(a/b + " " + a%b);		
		
	}

}
