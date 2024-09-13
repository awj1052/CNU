package week7;

import java.util.Scanner;

public class Stable {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int count = Integer.parseInt(sc.nextLine());
		int arrayI[] = new int[count];
		String arrayS[] = new String[count];
		for(int i=0; i<count;i++){
			String st = sc.nextLine();
			String split[] = st.split(" ");
			arrayI[i] = Integer.parseInt(split[0]);
			arrayS[i] = split[1];	
		}
		for(int i=0;i<count-1;i++){
			boolean changed = false;
			for(int j=0; j<count-1-i;j++){
				if(arrayI[j] > arrayI[j+1]){
					int tmp = arrayI[j];
					arrayI[j] = arrayI[j+1];
					arrayI[j+1] = tmp;
					String tmp2 = arrayS[j];
					arrayS[j] = arrayS[j+1];
					arrayS[j+1] = tmp2;
					changed = true;
				}
			}
			if (!changed) break;
		}
		for(int i=0;i<count;i++){
			System.out.println(arrayI[i] + " " +arrayS[i]);
		}
		
		
	}

}
