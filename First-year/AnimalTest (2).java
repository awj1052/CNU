package week11;

import java.util.Scanner;

public class AnimalTest {
	public static void main(String[] args) { // 개 사람 > 1미터, 고양이 원숭이 < 1미터
		
		Scanner sc = new Scanner(System.in);
		int numberOfFoot = sc.nextInt();
		int howTall = sc.nextInt();
		String name = sc.next();
		sc.close();
		
		Animal anyAnimal = null;
		
		if(numberOfFoot==2) {
			if(howTall>=100) {
				anyAnimal = new Human();
				anyAnimal.setName(name);
			}else{
				anyAnimal = new Monkey();

			}
			
		}else if(numberOfFoot==4){
			if(howTall>=100) {
				anyAnimal = new Dog();
				anyAnimal.setName(name);
			}else{
				anyAnimal = new Cat();
				anyAnimal.setName(name);
			}
		}
		if(anyAnimal!=null) {
			System.out.println(anyAnimal.name());
			System.out.println(anyAnimal.talk());
			System.out.println(anyAnimal.move());
		}else {
			System.out.println("It is Not Animal");
		}
	}
}

class Human implements Animal{
	String name;
	@Override
	public String talk() {
		return "Hello";
	}

	@Override
	public String name() {
		if(name!=null) {
			return name;
		}else {
			return getClass().toString();
		}
	}

	@Override
	public void setName(String newName) {
		this.name=newName;
		
	}
	@Override
	public String move() {
		return "On Your Left";
	}
	
}

class Dog implements Animal{
	String name;
	@Override
	public String talk() {
		return "Bow-Wow";
	}

	@Override
	public String name() {
		if(name!=null) {
			return name;
		}else {
			return getClass().toString();
		}
	}

	@Override
	public void setName(String newName) {
		this.name=newName;
		
	}

	@Override
	public String move() {
		return "Step One-Two-One-Two";
	}
}

class Cat implements Animal{
	String name;
	@Override
	public String talk() {
		return "Mew~";
	}

	@Override
	public String name() {
		if(name!=null) {
			return name;
		}else {
			return getClass().toString();
		}
	}

	@Override
	public void setName(String newName) {
		this.name=newName;
		
	}

	@Override
	public String move() {
		return "Step One-Two-One-Two";
	}
}

class Monkey implements Animal{
	String name;
	@Override
	public String talk() {
		return "Grrrrr";
	}

	@Override
	public String name() {
		if(name!=null) {
			return name;
		}else {
			return getClass().toString();
		}
	}

	@Override
	public void setName(String newName) {
		this.name=newName;
		
	}

	@Override
	public String move() {
		return "Step One-Two-One-Two";
	}	
}

interface Animal{
	
	String name();
	void setName(String newName);
	abstract String talk();

	String move();
}