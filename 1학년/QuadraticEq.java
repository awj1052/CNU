package week4;

import java.util.Scanner;

public class QuadraticEq {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int b = i.nextInt();
		int c = i.nextInt();
		System.out.println((b*b-4*a*c<0)? "False" : "True\n" + Math.round((-b+Math.sqrt(b*b-4*a*c))*50)/100.0 + "\n" + Math.round((-b-Math.sqrt(b*b-4*a*c))*50)/100.0);
	}

}
