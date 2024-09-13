package week14;

import java.util.Scanner;
import java.util.Arrays;

public class ScoreCalc {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] tmp = sc.nextLine().split(" ");
		sc.close();
		int[] arr = new int[tmp.length];
		int[] arr2 = new int[tmp.length];
		for(int i=0; i<tmp.length; i++) {
			arr[i] = Integer.parseInt(tmp[i]);
		}
		Arrays.sort(arr);
		int sum = 0;
		for(int i=0; i<tmp.length; i++) {
			arr2[i]=arr[tmp.length-i-1];
			sum+=arr2[i];
		}
		System.out.println("sort : " + Arrays.toString(arr2));
		System.out.println("sum : " +sum);
		System.out.println("avg : " + Math.round(100.0*sum/tmp.length)/100.0);
		System.out.println("rank 1 score : " + arr2[0]);
		System.out.println("rank " + tmp.length + " score : " + arr2[tmp.length-1]);
		
	}

}
