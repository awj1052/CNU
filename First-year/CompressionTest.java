package Final;

import java.util.Scanner;

interface Compression {

    String compress(String origin);
}

public class CompressionTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputData = scanner.nextLine();


        Compression[] compressions = new Compression[2];

        compressions[0] = new NormalCompression();
        compressions[1] = new SpecialCompression();

        for (Compression compression : compressions) {
            System.out.println(compression.compress(inputData));
        }
    }
}

class NormalCompression implements Compression{

	@Override
	public String compress(String origin) {
		String[] arr = origin.split("");
		int count = 0;
		String print ="";
		String a;
		a = arr[0];
		for(int i=0; i<arr.length; i++) {
			if(arr[i].equals(a)) {
				count++;
			}else {
				print+=format2((int)a.charAt(0))+""+format2(count);
				count=1;
			}
			a=arr[i];
		}
		print+=format2((int)a.charAt(0))+""+format2(count);
		return print;
	}
	
	public String format2(int a) {
		if(a==0) {
			return "0";
		}
		String print = "";
		while(a>0) {
			print+=a%2;
			a/=2;
		}
		String printt[] = print.split("");
		print="";
		for(int i=0; i<printt.length; i++) {
			print+=printt[printt.length -1 - i];
		}
		return print;
	}
	
}

class  SpecialCompression implements Compression{

	@Override
	public String compress(String origin) {
		String[] arr = origin.split("");
		int count = 0;
		String print ="";
		String a;
		a = arr[0];
		String[] arr2 = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l","m",
				"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
		for(int i=0; i<arr.length; i++) {
			if(arr[i].equals(a)) {
				count++;
			}else {
				for(int j=0; j<26; j++) {
					if(arr2[j].equals(String.valueOf(a.charAt(0)))) {
						print+=format2(j)+""+format2(count);
						count=1;
						break;
					}
				}
			}
			a=arr[i];
		}
		for(int j=0; j<26; j++) {
		    if(arr2[j].equals(String.valueOf(a.charAt(0)))) {
		        print+=format2(j)+""+format2(count);
		        break;
		    }
		}
		return print;
	}
	
	public String format2(int a) {
		if(a==0) {
			return "0";
		}
		String print = "";
		while(a>0) {
			print+=a%2;
			a/=2;
		}
		String printt[] = print.split("");
		print="";
		for(int i=0; i<printt.length; i++) {
			print+=printt[printt.length -1 - i];
		}
		return print;
	}
	
}
