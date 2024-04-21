package week13;

import java.util.Scanner;

public class VendingMachine {
   
   public static void main(String[] args) {
      String[] beverage = {"POCARI", "PEPSI", "COCA", "FANTA", "SIKHYE", "MAESIL",
            "SPRITE", "BONGBONG", "YOOJA", "GALBAE"};
      int[] price = {1000, 1000, 1500, 1300, 1100, 900, 1200, 1200, 900, 900};
      Scanner sc = new Scanner(System.in);
      int money = sc.nextInt();
      int num = sc.nextInt();
      try {
         if(money>=price[num-1]) {
            System.out.println(beverage[num-1]);
            System.out.println(money-price[num-1]);
         }else {
            System.out.println("Can't buy.");
         }
      }catch(ArrayIndexOutOfBoundsException e) {
         System.out.println("Invalid number.");
      }
      

   }

}
