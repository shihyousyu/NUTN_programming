package oop1;

public class Witch {
	private String name;
	private int life;
	private int magic;
	
	public Witch() {
		this.name=" ";
		this.life=0;
		this.magic=0;
	}
	public Witch(String name) {
		this.name=name;
		this.life=280;
		this.magic=200;
	}
	
	void setName(String name) {this.name=name;}
	void setLife(int life) {this.life=life;}
	void setMagic(int magic) {this.magic=magic;}
	
	String getName() {return name;}
	int getLife() {return life;}
	int getMagic() {return magic;}
	
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
}
