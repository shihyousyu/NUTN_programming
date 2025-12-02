package oop3;

public class Witch extends ROLE{
	public Witch() {super(" ", 0, 0);}
	public Witch(String name) {super(name, 280, 200);}
	
	void SmallFire(ROLE r) {
		if(magic<25) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=25;
		r.life-=40;
		if(r.life<=0)
			System.out.println("The warrior "+r.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Witch- "+super.toString());}
}
