package week3;

import java.util.Scanner;

public class Casting {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		double a = i.nextDouble();
		int b = (int) a;
		System.out.print(b+"\n"+Integer.toBinaryString(b));
				
		
	}

}
