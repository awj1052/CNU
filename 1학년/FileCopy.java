package week13;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class FileCopy {

	public static void main(String[] args){
		//PrintWriter pw = null;
		try(BufferedReader br = new BufferedReader(new FileReader("src/day2/FileCopy.java"));
			PrintWriter pw = new PrintWriter("e:/test.txt");){
			String line;
			while((line=br.readLine())!=null){
				pw.println(line);
			}
		} catch(FileNotFoundException e) {
			e.printStackTrace();
		} catch(IOException e) {
			e.printStackTrace();
		}
		
	}

}
