package week11;

import java.util.Scanner;

public class CodeTypeCheck {
	static int[] count;
	static int[] shape;
	static int idx;
	public static void main(String[] args) { // # 메세지의 끝 // $ 앞 문자코드 무시 새로작성
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		while(!a.contains("#")) {
			a+=sc.nextLine(); // str.substring(str.indexOf("$")+1,str.length());
		}
		count = new int[a.length()];
		shape = new int[a.length()];
		idx = 0;
		for(int i=0; i<a.length();i++) {
			if(a.charAt(i)=='#') {
				break;
			}
			check((int)a.charAt(i));
		}
		for(int i=0;i<a.length()-1;i++){
			boolean changed = false;
			for(int j=0; j<a.length()-1-i;j++){
				if(count[j] < count[j+1]){
					int tmp = count[j];
					count[j] = count[j+1];
					count[j+1] = tmp;
					tmp = shape[j];
					shape[j] = shape[j+1];
					shape[j+1] = tmp;
					changed = true;
				}
			}
			if (!changed) break;	
		}
		int same=0;
		for(int i=1; i<a.length();i++) {
			if(count[0]==count[i]) {
				same++;
			}else {
				break;
			}
		}
		int min = (shape[0]>='A' && shape[0]<='Z') ? shape[0]+100:shape[0];
		int idx2 = 0;
		for(int i=1;i<same+1;i++){
			if(shape[i]>='A' && shape[i]<='Z') {
				if(min>shape[i]+100) {
					min=shape[i]+100;
					idx2 = i;
				}	
			}else {
				if(min>shape[i]) {
					min=shape[i];
					idx2 = i;
				}
			}
		}
		System.out.print((shape[idx2] < 58)? "D" : (shape[idx2] < 91)? "U" : "L");
		System.out.print((char)shape[idx2]);
		System.out.print(count[0]);
	}
	public static void check(int a) { // $ 36  # 35
		if(a==36) {
			for(int i=0; i<shape.length;i++) {
				shape[i]=0;
				count[i]=0;
				idx=0;
			}
			return;
		}
		for(int i=0; i<idx;i++) {
			if(shape[i]==a) {
				count[i]++;
				return;
			}
		}
		shape[idx]=a;
		count[idx]++;
		idx++;
	}
}
