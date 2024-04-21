package week13;

import java.util.Scanner;

public class Icecream {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ice = sc.nextInt();
		int st = sc.nextInt();
		if(ice==0) {
			System.out.println("Empty.");
			return;
		}
		if(ice>=st) {
			try {
				System.out.println(ice/st + " " + ice%st);
			} catch(ArithmeticException e) {
				System.out.println("No one wants.");
			}
		}else {
			System.out.println("There are people more than ice cream.");
		}
	}

}
