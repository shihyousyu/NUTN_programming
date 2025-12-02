package oop4;

public class Priest extends ROLE{
	public Priest() {super(" ", 0, 0);}
    public Priest(String name) {super(name, 340, 160);}

    void Dark(ROLE r) {
		if(magic<20) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=20;
		if(r instanceof Warrior) r.life-=30;
        else if(r instanceof Witch) r.life-=50;
        else if(r instanceof Priest) r.life-=40;

        if(r.life<=0) 
        	System.out.println(r.getName()+" is died!");
	}
	
	@Override
	public String toString() {return ("Priest- "+super.toString());}
}
