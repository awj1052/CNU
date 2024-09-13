package week13;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.stream.Stream;

public class IntStreamTest {
	public static void main(String[] args) {
		try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));){
			Stream.generate(()->{
				try {
					return Integer.parseInt(br.readLine());
				} catch (Exception e) {}
				return 0; // int 형으로 변환이 불가능하면 0으로 됨
			}).limit(Integer.parseInt(br.readLine())).sorted().forEach(i->{
				try {
					bw.write(i+"\n");
				} catch (Exception e) {}
			});
		} catch (Exception e) {
			e.printStackTrace();
		}
		//Stream.generate(()->5).limit(6).forEach(i->System.out.println(i+1));
		//Stream.iterate(30, i->i+2).limit(5).forEach(i->{System.out.println(i); System.out.println(i+".");});
		//Stream.iterate(30, i->i+2).limit(5).forEach(System.out::println);
	}
}
