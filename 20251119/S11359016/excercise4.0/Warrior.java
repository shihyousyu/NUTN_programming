package oop4_0;

public class Warrior extends ROLE implements LifeRecoverable {
	public Warrior() {super(" ", 0, 0);}
    public Warrior(String name) {super(name, 400, 100);}

    public void NewMoon(ROLE r) {
        if (magic < 10) {
            System.out.println("Invalid attack! Not enough magic.");
            return;
        }
        magic-=10;

        if (r instanceof Warrior) r.life-=25;
        else if (r instanceof Witch) r.life-=40;
        else if(r instanceof Priest) r.life-=50;

        if (r.life<=0)
            System.out.println(r.getName() + " is died!");
    }
    
    @Override
    public double recoverLife() {
        this.life += LIFERATE;
        return LIFERATE;
    }
    @Override
    public String toString() {
        return "Warrior - " + super.toString();
    }
}

