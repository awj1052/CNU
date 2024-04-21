package week14;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Account {	
	public static boolean matchID(String id) {
		Pattern p1 = Pattern.compile("^[a-zA-Z]+[a-zA-Z0-9]+@[a-zA-Z]+\\.(?:com|co|kr|net)$");
		Matcher m1 = p1.matcher(id);
		if(! m1.matches()) {
			System.out.println("Illegal ID input!");
			return false;
		}
		else
			return true;
	}
	
	public static boolean matchPW(String pw) {
		Pattern p2 = Pattern.compile("[a-zA-Z1-8|!|@|#|$|%|^|&]{5,10}");
		Matcher m2 = p2.matcher(pw);
		if(! m2.matches()) {
			System.out.println("Illegal PW input!");
			return false;
		}
		else
			return true;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String id = sc.nextLine();
		String pw = sc.nextLine();
		sc.close();
		
		boolean resultID, resultPW;
		
		resultID = matchID(id);
		resultPW = matchPW(pw);
		
		if(resultID && resultPW)
			System.out.println("Account created!");
	}

}
