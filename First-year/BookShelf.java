package middle;

import java.util.Scanner;
public class BookShelf {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] inputt = sc.nextLine().split(" ");
		int[] arr = new int[inputt.length];
		int max = 0;
		for(int i=0; i<inputt.length;i++) {
			arr[i]=Integer.parseInt(inputt[i]);
			if(arr[i]>max) {
				max = arr[i];
			}
		}
		for(int i=max; i>0;i--) {
			for(int j : arr) {
				if(j>=i) {
					System.out.print("*");
				}else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	
		
		
	}
}