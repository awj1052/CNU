package week7;

import java.util.Scanner;

public class Spin {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st[] = sc.nextLine().split(" ");
		int num = st[0].length();
		for(int i=1;i<st.length;i++){
			if(num<st[i].length()){
				num=st[i].length();
			}
		}
		String star[][] = new String[st.length][num];
		for(int i=0;i<st.length;i++){
			for(int j=0;j<num;j++){
				star[i][j] = (j<st[i].length())? "*" : " ";
			} // 배열을 입력값에 따라 * 또는 공백으로 채움
		}
		String result[][] = new String[num][st.length];
		for(int i=0;i<st.length;i++){
			for(int j=0;j<num;j++){
				result[j][st.length-i-1] = star[i][j];
			} // result 에 행과 열을 바꾸고 열을 뒤에서부터 채움 (시계방향 90도)
		}
		for(int i=0;i<result.length;i++){
			for(int j=0;j<result[i].length;j++){
				System.out.print(result[i][j]);
			}
			System.out.println();
		}
	}

}

