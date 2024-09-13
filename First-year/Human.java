package week10;

public class Human{
	private String name;
	private int age;
	Human(String name, int age){
		System.out.println("Human 생성자");
		this.name = name;
		this.age = age;
	}
	public String toString(){
		return "Human [name = "+name+", age = "+age+"]";
	}
	void setName(String name){
		this.name = name;
	}
	void setAge(int age){
		this.age = age;
	}
	String getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	public static void main(String[] args) {
		Human p1 = new Human("춘향", 18);
		Human p2 = new Human("몽룡", 21);
		Human p3 = new Human("사또", 50);
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
	}	
}
