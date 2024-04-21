package week5;

import java.util.Scanner;

public class Calculator {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		int n = i.nextInt();
		String a = i.next();
		int m = i.nextInt();
		switch(a){
			case "+":
				System.out.println(n+m); break;
			case "-":
				System.out.println(n-m); break;
			case "/":
				if (m==0){
					System.out.println("error");
				}else{
					double result = Math.round(100.0*n/m)/100.0;
					System.out.println(result);
				} break;
			case "*":
				System.out.println(n*m); break; 
		}
	}

}
