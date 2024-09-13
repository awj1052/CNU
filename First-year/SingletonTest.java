package week10;

public class SingletonTest {
	public static void main(String[] args) {
		//Singleton s1 = new Singleton(); // 생성자가 private 이여서 접근 불가
		Singleton s2 = Singleton.getInstance();
		Singleton s3 = Singleton.getInstance();
		System.out.println("s2 value = " + s2.getValue());
		System.out.println("s2 value = " + s3.getValue());
		s2.setValue(10);
		System.out.println("s2 value = " + s2.getValue());
		System.out.println("s2 value = " + s3.getValue());
		
	}
}

class Singleton{
	private static Singleton s;
	private int value;
	private Singleton() {
		value = 5;
	}
	public static Singleton getInstance() {
		if(s==null)
			s=new Singleton();
		return s;
	}
	public void setValue(int a) {value=a;}
	public int getValue() {return value;}
}
