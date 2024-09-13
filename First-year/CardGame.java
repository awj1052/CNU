package week14;

import java.util.Scanner;

public class CardGame {

 public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    
    String tmp1 = sc.nextLine();
    String tmp2 = sc.nextLine();
    
    Card c1 = new Card();
    c1.setNumber(Integer.parseInt(tmp1.split(" ")[0]));
    c1.setKind(tmp1.split(" ")[1]);

    Card c2 = new Card();
    c2.setNumber(Integer.parseInt(tmp2.split(" ")[0]));
    c2.setKind(tmp2.split(" ")[1]);
    
    boolean result = c1.isWin(c2);
    
    System.out.println("c1 : " + c1.toString());
    System.out.println("c2 : " + c2.toString());
    
    
    if (result) {
       System.out.println("c1 Win!");
    }else{
       System.out.println("c2 win!");
    }
 }
}
//fix end

//write here
class Card{
	String type;
	int number;
	
	String getKind() {
		return type;
	}
	void setKind(String kind) {
		if(!kind.equals("Spade")&&!kind.equals("Diamond")&&!kind.equals("Heart")&&!kind.equals("Clover")) {
			System.out.println("Wrong input.");
			System.exit(0);
		}
		type = kind;
	}
	int getNumber() {
		return number;
	}
	void setNumber(int number) {
		if(number>13||number<1) {
			System.out.println("Wrong input.");
			System.exit(0);
		}
		this.number = number;
	}
	boolean isWin(Card c1) {
		int a = 0, b = 0;
		if(type.equals("Spade")) {
			a = 4;
		}else if(type.equals("Diamond")) {
			a = 3;
		}else if(type.equals("Heart")) {
			a = 2;
		}else if(type.equals("Clover")) {
			a = 1;
		}
		if(c1.type.equals("Spade")) {
			b = 4;
		}else if(c1.type.equals("Diamond")) {
			b = 3;
		}else if(c1.type.equals("Heart")) {
			b = 2;
		}else if(c1.type.equals("Clover")) {
			b = 1;
		}
		if(a>b) {
			return true;
		}else if (a<b) {
			return false;
		}
		if(number>c1.number) {
			return true;
		}else if (number<c1.number) {
			return false;
		}
		System.out.println("Wrong input.");
		System.exit(0);
		return false;
	}
	public String toString() {
		return "Card type is " + type + " and number is " + number;
	}
}