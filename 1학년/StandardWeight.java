package week5;

import java.util.Scanner;

public class StandardWeight {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		double a = i.nextDouble();
		double b = i.nextDouble();
		if (Math.round(b/a/a*1000000)/100.0 >= 23){
			System.out.println("over");
		}else if (Math.round(b/a/a*1000000)/100.0 >= 18.5){
			System.out.println("standard");
		}else{
			System.out.println("under");
		}
		
	}

}
