package oop2;

public class Warrior extends ROLE{
	public Warrior() {super(" ", 0, 0);}
	public Warrior(String name) {super(name, 400, 100);}
	
	void NewMoon(Warrior w) {
		if(magic<10) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=10;
		this.life-=25;
		if(this.life<=0)
			System.out.println("The warrior "+w.getName()+" is died!");
	}
	
	void NewMoon(Witch t) {
		if(magic<10) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=10;
		this.life-=40;
		if(this.life<=0)
			System.out.println("The witch "+t.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Warrior- "+super.toString());}
}