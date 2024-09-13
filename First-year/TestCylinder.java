package week10;

class Circle{
	double radius;
	Circle(){
		this(1.0);
	}
	Circle(double radius){
		this.radius = radius;
	}
	double getRadius(){
		return radius;
	}
	double getArea(){
		return radius*radius*3.14;
	}
}

class Cylinder extends Circle{
	double height;
	Cylinder(){
		this(1.0, 1.0);
	}
	Cylinder(double radius){
		this(radius, 1.0);
	}
	Cylinder(double radius, double height){
		super(radius);
		this.height = height;
	}
	double getHeight(){
		return height;
	}
	double getVolume(){
		return height*super.getArea();
	}
}

public class TestCylinder{
	public static void main(String[] args){
		Cylinder obj1 = new Cylinder();
		Cylinder obj2 = new Cylinder(5.0, 3.0);
		System.out.println("obj1의 밑면의 반지름 : "+obj1.getRadius()+", 밑면의 넓이 : "+obj1.getArea()+", 높이 : "+obj1.getHeight()+", 부피 : "+obj1.getVolume());
		System.out.println("obj2의 밑면의 반지름 : "+obj2.getRadius()+", 밑면의 넓이 : "+obj2.getArea()+", 높이 : "+obj2.getHeight()+", 부피 : "+obj2.getVolume());
	}
}