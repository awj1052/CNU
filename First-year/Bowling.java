package Final;

import java.util.Scanner;

public class Bowling {
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			String[] s = sc.nextLine().split(" ");
			int score=0;
			for(int i=0; i<s.length; i++){
				System.out.print((i+1) + "\t");
			}
			System.out.println();
			for(int i=0; i<s.length; i++){
				System.out.print(s[i] + "\t");
			}
			System.out.println();
			
			for(String a : s) {
				if(a.equals("X")) {
					score+=30;
				}else if(a.contains("/")) {
					score+=Integer.parseInt(a.replace("/", ""))+10;
				}else if(a.contains("-")) {
					score+=Integer.parseInt(a.replace("-", ""));
				}else { 
					int tmp=Integer.parseInt(a);
					while(tmp>0) {
						score+=tmp%10;
						tmp/=10;
					}
				}
				System.out.print(score + "\t");
			}
			
		}

}
