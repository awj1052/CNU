package week11;

import java.util.Scanner;

public class CodeTypeCheck3 {
	public static void main(String[] args) {
	      Scanner sc = new Scanner(System.in);
	      String code = sc.next();
	      while(!code.contains("#")) {code += sc.next();}
	      while(code.contains("$")) {code = code.substring(code.indexOf('$')+1);}
	      String [] array = code.split("");
	      int[] count = new int[62];
	      String [] arr = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j"
		            ,"k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J"
	            ,"K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	      for(int i = 0; i<array.length; i++) {
	    	 if(array[i].equals("#")) {
	    		 break;
	    	 }
	         loop : for(int k = 0; k<62; k++) {
	            if(array[i].equals(arr[k])) {
	            	count[k]++;
	            	break loop;
	            }
	         }
	      }
	      int idx = 0;
	      int max = count[0];
	      for(int i=0; i<62; i++) {
	         if(max < count[i]) {
	        	 max = count[i];
	        	 idx = i;
	         }
	      }
	      if(Character.isDigit(arr[idx].charAt(0))==true) {
	    	  System.out.print("D");
	      }else if (Character.isUpperCase(arr[idx].charAt(0))==true) {
	    	  System.out.print("U");
	      }else {
	    	  System.out.print("L");
	      }
	      System.out.print(arr[idx]);
	      System.out.print(count[idx]);
	      
	}
}
