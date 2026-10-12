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
		w.setLife(w.getLife() - 40);
		if(w.getLife()<=0)
			System.out.println("The warrior "+w.getName()+" is died!");
	}

	void SmallFire(Witch t) {
		if(magic<25) {
			System.out.println("Invalid attack!");
			return;
		}
		magic-=25;
		t.setLife(t.getLife() - 60);
		if(t.getLife()<=0)
			System.out.println("The witch "+t.getName()+" is died!");
	}

	@Override
	public String toString() {return ("Witch- "+super.toString());}
}
