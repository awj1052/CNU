package day1;

import java.util.Scanner;

public class Main {

	static int min;
	static int array[][];
	static boolean visit[];
	static int len;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		len = Integer.parseInt(sc.nextLine());
		visit = new boolean[len-1];
		array = new int[len][len];
		for(int i=0; i<len; i++){
			for(int j=0; j<len; j++){
				array[i][j] = sc.nextInt();
			}
		}
		min = len*100;
		calc(len,0,0);
		System.out.println(min);
	}
	
	static void calc(int line, int cost, int start){
		if(cost>=min){
			return;
		}
		if(line==1){
			if(array[start][0] != 0){
				cost+=array[start][0];
				if(min>cost){
					min = cost;
				}
			}
			return;
		}
		for(int i=0; i<len-1;i++){
			if(!visit[i] && array[start][i+1] != 0){
				visit[i] = true;
				calc(line-1, cost+array[start][i+1], i+1);
				visit[i] = false;
			}
		}
	}

}
