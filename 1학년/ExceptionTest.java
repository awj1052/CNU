package week13;

public class ExceptionTest {
	public static void main(String[] arg) {
		try {
			System.out.println(0/0);
		} catch(NullPointerException e) {
			System.out.println("Exception");
		} catch(ArithmeticException e) { // 9,10번째 줄이 없으면
			System.out.println("called"); // 6번째줄때문에 런타임 에러남
			e.printStackTrace();
		}finally {
			System.out.println("ㅎㅇ");
		}
		System.out.println("Hi");
	} // called, ㅎㅇ, Hi
}
