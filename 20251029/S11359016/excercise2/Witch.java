package oop2;

public class Witch extends ROLE{
	public Witch() {super(" ", 0, 0);}
	public Witch(String name) {super(name, 280, 200);}
	
	void SmallFire(Warrior w) {
		if(magic<25) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=25;
		this.life-=40;
		if(this.life<=0)
			System.out.println("The warrior "+w.getName()+" is died!");
	}
	
	void NewMoon(Witch t) {
		if(magic<25) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=25;
		this.life-=60;
		if(this.life<=0)
			System.out.println("The witch "+t.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Witch- "+super.toString());}
}
