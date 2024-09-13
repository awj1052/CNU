package week2;

import java.util.*;

public class PrintFormatting {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String st = scanner.nextLine();
		System.out.printf("%s\n", st);
		System.out.printf("%2s\n", st);
		System.out.printf("%3s\n", st);
		System.out.printf("%4s\n", st);
		System.out.printf("%5s", st);

	}

}
