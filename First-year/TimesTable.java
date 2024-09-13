package middle;

import java.util.Scanner;
public class TimesTable {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String tt = sc.nextLine();
		int input = 0;
		int loop = 0;
		if(tt.charAt(0)=='2'||tt.charAt(0)=='3'||tt.charAt(0)=='4'||tt.charAt(0)=='5'||tt.charAt(0)=='6'||tt.charAt(0)=='7'||tt.charAt(0)=='8'||tt.charAt(0)=='9') {
			input = Integer.parseInt(tt);
		}
		if(input==2||input==3||input==4) {
			loop = 1;
		}
		if(input==5||input==6||input==7) {
			loop = 2;
		}
		if(input==8||input==9) {
			loop = 3;
		}
		if(loop!=0) {
			for(int i=0; i<loop;i++) {
				for(int j=0; j<9; j++) {
					for(int k=0; k<3; k++) {
						if(3*i+2+k<=input) {
							System.out.print(3*i+2+k + " * " + (j+1) + " = " + (3*i+2+k)*(j+1) + "\t");
						}
					}
					System.out.println();
				}
				System.out.println();
				
			}
		}

	}

}