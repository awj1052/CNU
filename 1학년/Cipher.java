package week4;

import java.util.Scanner;

public class Cipher {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		String st = i.nextLine();
		char s0 = st.charAt(0);
		char s1 = st.charAt(1);
		char s2 = st.charAt(2);
		char s3 = st.charAt(3);
		char s4 = st.charAt(4);
		System.out.println((int)s0+""+(int)s1+""+(int)s2+""+(int)s3+""+(int)s4);
	}

}
