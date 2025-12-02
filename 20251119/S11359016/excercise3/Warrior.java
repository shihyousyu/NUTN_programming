package oop3;

public class Warrior extends ROLE{
	public Warrior() {super(" ", 0, 0);}
	public Warrior(String name) {super(name, 400, 100);}
	
	void NewMoon(ROLE r) {
		if(magic<10) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=10;
		r.life-=25;
		if(r.life<=0)
			System.out.println("The warrior "+r.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Warrior- "+super.toString());}
}