package week13;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.stream.IntStream;

public class BufferedWriterTest {
	public static void main(String[] args){
		int[] ints = new int[10];
		for(int i=0; i<10; i++) {
			ints[i]=i;
		}
		IntStream a = IntStream.of(ints);
		try(BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));) {
			bw.write(a.average().getAsDouble() + "");
		} catch(Exception e) {
			e.printStackTrace();
		}
		System.out.println("b"); // try 블럭을 나가면서 bw.close(); 되므로 출력 안됨.
		IntStream.range(0,10).forEach(i->System.out.println(i));
	}
}
