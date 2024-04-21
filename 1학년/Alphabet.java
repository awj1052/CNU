package week5;

import java.util.Scanner;

public class Alphabet {

	public static void main(String[] args) {
		Scanner i = new Scanner(System.in);
		String a = i.nextLine();
		if(a.equals("a") || a.equals("e") || a.equals("i") || a.equals("o") || a.equals("u")){
			System.out.println("vowel");
		}else{
			System.out.println("consonant");
		}
	}

}
