package oop4_0;

public class ROLE {
	protected String name;
	protected int life;
	protected int magic;
	
	public ROLE() {
		this.name=" ";
		this.life=0;
		this.magic=0;
	}
	public ROLE(String name, int life, int magic) {
		this.name=name;
		this.life=life;
		this.magic=magic;
	}
	void setName(String name) {this.name=name;}
	void setLife(int life) {this.life=life;}
	void setMagic(int magic) {this.magic=magic;}
	
	String getName() {return name;}
	int getLife() {return life;}
	int getMagic() {return magic;}
	
	@Override
	public String toString() {
		return ("Name:"+name+" Life:"+life+" Magic:"+magic);
	}
	void Drink(Drug D) {
	    if (D instanceof RedDrug) {
	        RedDrug R = (RedDrug) D;
	        this.life += R.addLife;
	        System.out.println(name + " drinks RED " + R.size + " +" + R.addLife + " life.");
	    }
	    else if (D instanceof BlueDrug) {
	        BlueDrug B = (BlueDrug) D;
	        this.magic += B.addMagic;
	        System.out.println(name + " drinks BLUE " + B.size + " +" + B.addMagic + " magic.");
	    }
	}
}