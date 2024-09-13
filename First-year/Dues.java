package week4;

import java.util.Scanner;

public class Dues {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int a = i.nextInt();
		int b = i.nextInt();
		int c = i.nextInt();
		int d = i.nextInt();
		int min1 = a < b ? a : b;
		int min2 = c < d ? c : d;
		int minf = min1 < min2 ? min1 : min2;
		System.out.print(minf);
				
		
	}

}
