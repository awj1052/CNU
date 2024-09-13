package week6;

import java.util.Scanner;

public class R_Cipher {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = sc.nextLine();
		int i;
		for(i=0;i<5;i++){
			System.out.print((int)st.charAt(4-i));
		}
	}

}
