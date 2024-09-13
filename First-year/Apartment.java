package Final;

import java.util.Scanner;

public class Apartment {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] tmp = sc.nextLine().split(" ");
		int height = Integer.parseInt(tmp[0]);
		int width = Integer.parseInt(tmp[1]);
		String[][] people = new String[height][width];
		for(int i=0; i<height; i++) {
			String[] tmp2 = sc.nextLine().split(" ");
			for(int j=0; j<width; j++) {
				try {
					people[i][j]=tmp2[j];
				}catch (Exception e){
					break;
				}
			}
		}
		boolean print = false;
		String name = sc.nextLine();
		for(int i=0; i<height; i++) {
			for(int j=0; j<people[i].length; j++) {
				if(name.equals(people[i][j])) {
					print = true;
					System.out.print(((i+1)*100+(j+1)) + " ");
				}
			}
		}
		if(!print) {
			System.out.println("empty");
		}
	}

}
