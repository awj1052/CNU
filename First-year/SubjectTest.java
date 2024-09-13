package week11;

import java.util.Arrays;

public class SubjectTest {
	public static void main(String[] args) {
		Subject A = new Science(1, "물리학I", "Physics"); // Up-Casting
		System.out.println(A.getSubject()); // "Physics"
		// A.Field(); // Compile Error
		Science P = (Science) A; // Down-Casting
		System.out.println(P.getSubject()); // "Physics"
		// Language B = new Subject(1, "읽기"); // Compile Error
		// Language B = (Language) new Subject(1, "읽기"); // Execution Error
		Language E = new Language(1, "말하기", "English");
		Leaner P1 = new Leaner("학생1");
		Leaner P2 = new Leaner("학생2");
		P1.Join(P);
		P1.Join(E);
		P2.Join(P);
		System.out.println(P1.getName() +"의 과목 : "+Arrays.toString(P1.getSubject()));
		System.out.println(P2.getName() +"의 과목 : "+Arrays.toString(P2.getSubject()));
		System.out.println(P.getSubject() +"의 학생 : "+Arrays.toString(P.getLeaner()));
		System.out.println(E.getSubject() +"의 학생 : "+Arrays.toString(E.getLeaner()));
		System.out.println("--------------------");
		P1.Quit(P);
		P2.Quit(P);
		System.out.println(P1.getName() +"의 과목 : "+Arrays.toString(P1.getSubject()));
		System.out.println(P2.getName() +"의 과목 : "+Arrays.toString(P2.getSubject()));
		System.out.println(P.getSubject() +"의 학생 : "+Arrays.toString(P.getLeaner()));
		System.out.println(E.getSubject() +"의 학생 : "+Arrays.toString(E.getLeaner()));
	}
	
	
}

class Leaner{
	private String name;
	private Subject[] arr;
	Leaner(String name){
		this.name = name;
		arr = new Subject[0];
	}
	String getName() {
		return name;
	}
	void Quit(Subject s) {
		boolean quit = false;
		for(int i=0; i<s.leaner.length; i++) {
			if (s.leaner[i]==this) {
				quit = true;
				break;
			}			
		}
		if(!quit) return;
		quit = false;
		Leaner[] tmp = new Leaner[s.leaner.length-1];
		for(int i=0; i<s.leaner.length; i++) {
			if (s.leaner[i]==this) {
				quit = true;
				continue;
			}
			if(quit) {
				tmp[i-1] = s.leaner[i];
			}else {
				tmp[i] = s.leaner[i];
			}
		}
		s.leaner = tmp;	
		quit = false;
		Subject[] tmp1 = new Subject[arr.length-1];
		for(int i=0; i<arr.length; i++) {
			if(arr[i] == s) {
				quit = true;
				continue;
			}
			if(quit) {
				tmp1[i-1] = arr[i];
			}else {
				tmp1[i] = arr[i];
			}
		}
		arr = tmp1;
	}
	void Join(Subject s) {
		Leaner[] tmp = new Leaner[s.leaner.length+1];
		for(int i=0; i<s.leaner.length; i++) {
			tmp[i] = s.leaner[i];
		}
		tmp[s.leaner.length] = this;
		s.leaner = tmp;
		Subject[] tmp1 = new Subject[arr.length+1];
		
		for(int i=0; i<arr.length; i++) {
			tmp1[i] = arr[i];
		}
		tmp1[arr.length] = s;
		arr = tmp1;
	}
	String[] getSubject() {
		String[] tmp = new String[arr.length];
		for(int i=0; i<arr.length;i++) {
			tmp[i]=arr[i].getSubject();
		}
		return tmp;
	}
	
}

class Subject{
	private int grade;
	private String book;
	Leaner[] leaner;
	Subject(int grade, String book){
		if(grade>0 && grade<5) {
			this.grade = grade;
		}else {
			this.grade = 1;
		}
		this.book = book;
		leaner = new Leaner[0];
	}
	String getSubject() {
		return "Subject";
	}	
	String[] getLeaner() {
		String[] tmp = new String[leaner.length];
		for(int i=0; i<leaner.length;i++) {
			tmp[i]=leaner[i].getName();
		}
		return tmp;		
	}
}

class Science extends Subject{
	private String field;
	Science(int grade, String book, String field) {
		super(grade, book);
		if (field.equals("Basic") || field.equals("Physics") || field.equals("Chemistry")) {
			this.field = field;
		}else {
			this.field = "Basic";
		}
	}
	String getSubject() {
		return field;
	}
}

class Language extends Subject{
	private String field;
	Language(int grade, String book, String field) {
		super(grade, book);
		if (field.equals("English") || field.equals("Korean") || field.equals("Japanese")) {
			this.field = field;	
		}else {
			this.field = "English";
		}
	}
	String getSubject() {
		return field;
	}
	
}
