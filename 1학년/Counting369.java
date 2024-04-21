package Final;

import java.util.Scanner;

public class Counting369 {
	static String print;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		print = "";
		sc.close();
		num3((num-1)/3);
		String[] arr = print.split("");
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[arr.length-1-i]);
		}
		if(num%3==0) {
			System.out.print("9");
		}else {
			System.out.print(num%3 * 3);
		}
	}
		
	public static void num3(int a) {
		if(a==0) {
			return;
		}
		if(a%3==0) {
			print+="9";
		}else {
			print+=a%3*3;
		}
		num3((a-1)/3);
	}
}
