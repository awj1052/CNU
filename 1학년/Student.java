package week10;

public class Student extends Human {
	String major;
	Student(String name, int age, String major) {
		super(name, age);
		System.out.println("Student 생성자");
		this.major = major;
	}
	String getMajor(){
		return major;
	}
	public String toString(){
		return super.toString() + " Student [major = "+major+"]";
	}
	void setMajor(String major){
		this.major = major;
	}
	public static void main(String args[]){
		Student p1 = new Student("명진", 21, "컴퓨터");
		Student p2 = new Student("미현", 21, "경영");
		Student p3 = new Student("용준", 21, "경제");
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
	}
}
