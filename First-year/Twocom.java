package week14;

import java.math.BigInteger;
import java.util.Scanner;

public class Twocom {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger input = sc.nextBigInteger();
		
		sc.close();
		
		for(int i=0; i<input.bitLength(); i++) {
			input = input.flipBit(i);
		}
		input = input.flipBit(0);
		if(!input.testBit(0)) { // input.testBit(0) 1 true 0 false
			for(int i=1; i<input.bitLength();i++) {
				input = input.flipBit(i);
				if(input.testBit(i)) {
					break;
				}
			}
		}
		System.out.println(input);

	}

}
