package week2;

import java.util.*;

public class Swap {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String x = scanner.nextLine();
		String y = scanner.nextLine();
		String z = scanner.nextLine();
		String tmp = x;
		x = y;
		y = z;
		z = tmp;
		System.out.println(x);
		System.out.println(y);
		System.out.println(z);
	}

}
