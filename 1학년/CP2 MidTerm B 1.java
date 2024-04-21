package lab07;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class VendingMachine {

    public static void main(String[] args) {

        //1. write here
        List<DrinkVO> drinkList = new ArrayList();

        drinkList.add(new DrinkVO("COCA", 1500));
        drinkList.add(new DrinkVO("PEPSI", 1000));
        drinkList.add(new DrinkVO("SPRITE", 1200));
        drinkList.add(new DrinkVO("FANTA", 700));

        Drinks drinks = new Drinks();

        Scanner sc = new Scanner(System.in);
        String tmp = "";
        while (true) {
            System.out.println("1.manager 2.user 3.exit");
            String inputUser = sc.nextLine();
            if (inputUser.equals("1")) {
                System.out.println("1.drink list 2.add drink 3.remove drink");
                tmp = sc.nextLine();
                if (tmp.equals("1")) {
                    drinks.printDrink(drinkList);
                } else if (tmp.equals("2")) {
                    System.out.println("Please enter the information of the beverage you want to add.");
                    tmp = sc.nextLine();
                    drinkList = drinks.addDrink(drinkList, tmp);
                } else if (tmp.equals("3")) {
                    drinks.printDrink(drinkList);
                    System.out.println("Please enter the numer of the beverage you want to remove.");
                    tmp = sc.nextLine();
                    drinkList = drinks.removeDrink(drinkList, Integer.parseInt(tmp));
                } else {
                    System.out.println("Wrong Input.");
                }
            } else if (inputUser.equals("2")) {
                drinks.printDrink(drinkList);
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

class Drinks {

    public void printDrink(List<DrinkVO> drinkList) {
        //2. write here
        for(int i=1; i<=drinkList.size(); i++){
            System.out.println(i + "" + drinkList.get(i-1));
        }

    }

    public List<DrinkVO> addDrink(List<DrinkVO> drinkList, String input) {
        //3. write here
        String[] tmp = input.split(" ");
        drinkList.add(new DrinkVO(tmp[0], Integer.parseInt(tmp[1])));
        return drinkList;
    }

    public List<DrinkVO> removeDrink(List<DrinkVO> drinkList, int index) {
        //4. write here
        drinkList.remove(index-1);
        return drinkList;

    }

    public void buyDrink(List<DrinkVO> drinkList, String input) {
        //5. write here
        String[] tmp = input.split(" ");
        int tmp0 = Integer.parseInt(tmp[0])-1;
        int tmp1 = Integer.parseInt(tmp[1]);
        if (drinkList.get(tmp0).getPrice() <= tmp1){
            System.out.println(drinkList.get(tmp0).getName() + ", change : " + (tmp1-drinkList.get(tmp0).getPrice()));
        }else {
            System.out.println("Wrong Input.");
        }

    }

}

class DrinkVO {

    @Override
    public String toString() {
        return " " + name + " / " + price + "won";
    }

    private String name = "-";
    private int price = 0;

    public String getName() {
        return name;
    }

    public void setName(String name) {
    }

    public void setFlavor(String flavor) {
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
    }

    public DrinkVO(String name, int price) {
        this.name = name;
        this.price = price;
    }
}