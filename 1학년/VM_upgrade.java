package week14;

import java.util.Scanner;

//fix start
public class VM_upgrade {	
	public static void main(String[] args) {
		DrinkVO[] drinkList = new DrinkVO[5];
		drinkList[0] = new DrinkVO("COCA", 1500);
		drinkList[1] = new DrinkVO("PEPSI", 1000);
		drinkList[2] = new DrinkVO("SPRITE", 1200);
		drinkList[3] = new DrinkVO("FANTA", "Orange", 700);
		drinkList[4] = new DrinkVO("FANTA", "Grape", 700);

		Drinks drinks = new Drinks();

		Scanner sc = new Scanner(System.in);
		String tmp = "";
		while (true){
			System.out.println("1.manager 2.user 3.exit");
			String inputUser = sc.nextLine();
			if (inputUser.equals("1")) {
				System.out.println("1.drink list 2.change drink");
				tmp = sc.nextLine();
				if (tmp.equals("1")) {
					drinks.printDrinks(drinkList);
				} else if (tmp.equals("2")) {
					System.out.println("Input number of drink and information you want to change.");
					tmp = sc.nextLine();
					drinkList = drinks.changeDrink(drinkList, tmp);
				} else {
					System.out.println("Wrong Input.");
				}
			} else if (inputUser.equals("2")) {
				drinks.printDrinks(drinkList);
				System.out.println("Select drink number and money");
				tmp = sc.nextLine();
				drinks.buyDrink(drinkList, tmp);
			} else if (inputUser.equals("3")) {
				break;
			} else {
				System.out.println("Wrong Input.");
			}
		}
	}
}
//fix end
//write here
class Drinks {
	void printDrinks(DrinkVO[] drinkList) {
		for(int i=0; i<drinkList.length; i++) {
			System.out.println((i+1) + " " + drinkList[i]);
		}
	}
	DrinkVO[] changeDrink(DrinkVO[] drinkList, String input) {
		String[] tmp = input.split(" ");
		int num = Integer.parseInt(tmp[0])-1;
		drinkList[num].setName(tmp[1]);
		if(tmp.length==3) {
			drinkList[num].setFlavor("-");
			drinkList[num].setPrice(Integer.parseInt(tmp[2]));
		}else if (tmp.length==4) {
			drinkList[num].setFlavor(tmp[2]);
			drinkList[num].setPrice(Integer.parseInt(tmp[3]));
		}
		System.out.println(tmp[0] + " " + drinkList[num]);
		return drinkList;
	}
	void buyDrink(DrinkVO[] drinkList, String input) {
		String[] tmp = input.split(" ");
		int num = Integer.parseInt(tmp[0])-1;
		int money = Integer.parseInt(tmp[1]);
		if(drinkList[num].getPrice()<=money) {
			System.out.println(drinkList[num].getName() + ", change : " + (money-drinkList[num].getPrice()));
		}else {
			System.out.println("Wrong Input.");
		}
	}
}

class DrinkVO {

	//fix start
	String name;
	String flavor;
	int price;
	DrinkVO(String name, int price){
		this.name = name;
		this.price = price;
		flavor = "-";
	}
	DrinkVO(String name, String flavor, int price){
		this(name, price);
		this.flavor = flavor;
	}
	void setName(String name) {
		this.name = name;
	}
	void setFlavor(String flavor) {
		this.flavor = flavor;
	}
	void setPrice(int price) {
		this.price = price;
	}
	String getName() {
		return name;
	}
	String getFlavor() {
		return flavor;
	}
	int getPrice() {
		return price;
	}
	
	@Override
	public String toString() {
		return name + " / " + flavor + " / " + price + " won";
	}
	// fix end
}
