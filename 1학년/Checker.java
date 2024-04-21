package week4;

import java.util.Scanner;

public class Checker {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		String a = i.nextLine();
		int a0 = (int) a.charAt(0);
		System.out.println((a0 < 58)? "Digit" : (a0 < 91)? "UpperCase" : "LowerCase");
	}

}
