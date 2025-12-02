package oop4;

public class Warrior extends ROLE{
	public Warrior() {super(" ", 0, 0);}
	public Warrior(String name) {super(name, 400, 100);}
	
	void NewMoon(ROLE r) {
		if(magic<10) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=10;
		if(r instanceof Warrior) r.life-=25;
	    else if(r instanceof Witch) r.life-=40;
	    else if(r instanceof Priest) r.life-=30;
	
	    if(r.life<=0) 
	    	System.out.println(r.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Warrior- "+super.toString());}
}