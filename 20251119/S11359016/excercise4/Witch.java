package oop4;

public class Witch extends ROLE{
	public Witch() {super(" ", 0, 0);}
	public Witch(String name) {super(name, 280, 200);}
	
	void SmallFire(ROLE r) {
		if(magic<25) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=25;
		if(r instanceof Warrior) r.life-=40;
	    else if(r instanceof Witch) r.life-=60;
	    else if(r instanceof Priest) r.life-=50;
	
	    if(r.life<=0) 
	    	System.out.println(r.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Witch- "+super.toString());}
}