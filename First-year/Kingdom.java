package week14;

// 귀족 Noble
// 금화 10, 병사 25 현상
// 친밀 30 이상

//시장 Mayor
//금화 25 병사 10
// 친밀 70

// 주교 Bishop
// 친밀도에 따라 헌상

import java.util.Scanner;

public class Kingdom {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int sumG = 0, sumA = 0, countV = 0, countA = 0;
		int gold = 0, army = 0, closeness = 0;
		
		String input;
		String[] temp;
		
		Vassal v = null;
		
		while(true) {
			temp = sc.nextLine().split(" ");
			if(temp[0].equals("X")) {
				break;
			}
			if(temp[0].equals("N")) {
				v = new Noble(Integer.parseInt(temp[1]), Integer.parseInt(temp[2]), Integer.parseInt(temp[3]));	
			} else
				if(temp[0].equals("M")) {
				v = new Mayor(Integer.parseInt(temp[1]), Integer.parseInt(temp[2]), Integer.parseInt(temp[3]));	
			} else
				if(temp[0].equals("B")) {
				v = new Bishop(Integer.parseInt(temp[1]), Integer.parseInt(temp[2]), Integer.parseInt(temp[3]));	
			} 
			sumG+=v.getGold();
			sumA+=v.getArmy();
			countV++;
			if(v.checkApproval()) {
				countA++;
			}
		}
		
		sc.close();
		
		System.out.println("Gold: " + sumG);
		System.out.println("Army: " + sumA);
		System.out.println("Approval: " + Math.round((double) countA / countV * 100) + "%");
	}

}
abstract class Vassal {
	int gold;
	int army;
	int closeness;
	
	public Vassal(int g, int a, int c) {
		this.gold= g;
		this.army = a;
		this.closeness = c;
	}
	
	abstract int getGold();
	abstract int getArmy();
	abstract boolean checkApproval();
}

class Noble extends Vassal {
	// Fill codes here.
	Noble(int g, int a, int c){
		super(g, a, c);
	}

	@Override
	int getGold() {
		return gold/10;	
	}

	@Override
	int getArmy() {
		return army/4;	
	}

	@Override
	boolean checkApproval() {
		return (closeness>=30) ? true : false;
	}
}

class Mayor extends Vassal {

	public Mayor(int g, int a, int c) {
		super(g, a, c);
		// TODO Auto-generated constructor stub
	}
	// Fill codes here.

	@Override
	int getGold() {
		return gold/4;	
	}

	@Override
	int getArmy() {
		return army/10;	
	}

	@Override
	boolean checkApproval() {
		return (closeness>=70) ? true : false;
	}
}

class Bishop extends Vassal {

	public Bishop(int g, int a, int c) {
		super(g, a, c);
		// TODO Auto-generated constructor stub
	}
	// Fill codes here.

	@Override
	int getGold() {
		return (int)(1.0/100*gold*closeness);	
	}

	@Override
	int getArmy() {
		return (int)(1.0/100*army*closeness);	
	}

	@Override
	boolean checkApproval() {
		return true;
	}
}