package middle;

import java.util.Scanner;
public class SelectSnack {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] m_A = sc.nextLine().split(" ");
		String[] m_B = sc.nextLine().split(" ");
		int max = 0;
		for(String a : m_A) {
			if(Integer.parseInt(a)>max) {
				max = Integer.parseInt(a);
			}
		}
		for(String a : m_B) {
			if(Integer.parseInt(a)>max) {
				max = Integer.parseInt(a);
			}
		}
		boolean[] ms = new boolean[max+1];
		for(String a : m_A) {
			for(String b : m_B) {
				if(a.equals(b)) {
					ms[Integer.parseInt(a)]=true;
					break;
				}
			}
		}
		boolean print = false;
		for(int i=0; i<max+1;i++) {
			if(ms[i]) {
				System.out.print(i+ " ");
				print = true;
			}
		}
		if(!print) {
			System.out.println("empty");
		}
		
	}
}