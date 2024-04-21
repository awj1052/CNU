package week3;

import java.util.Scanner;

public class Cone {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int b = i.nextInt();
		System.out.println(Math.round(a*a*b*Math.PI/3*1000)/1000.0);
	}

}
