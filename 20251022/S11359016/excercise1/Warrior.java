package oop1;

public class Warrior {
	private String name;
	private int life;
	private int magic;
	
	public Warrior() {
		this.name=" ";
		this.life=0;
		this.magic=0;
	}
	public Warrior(String name) {
		this.name=name;
		this.life=400;
		this.magic=100;
	}
	
	void setName(String name) {this.name=name;}
	void setLife(int life) {this.life=life;}
	void setMagic(int magic) {this.magic=magic;}
	
	String getName() {return name;}
	int getLife() {return life;}
	int getMagic() {return magic;}
	
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
}