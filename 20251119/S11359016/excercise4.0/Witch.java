package oop4_0;

public class Witch extends ROLE implements MagicRecoverable {
	public Witch() {super(" ", 0, 0);}
    public Witch(String name) {super(name, 280, 200);}

    public void SmallFire(ROLE r) {
        if (magic < 25) {
            System.out.println("Invalid attack! Not enough magic.");
            return;
        }
        magic-=25;

        if (r instanceof Warrior) r.life-=40;
        else if (r instanceof Witch) r.life-=60;

        if (r.life<=0)
            System.out.println(r.getName() + " is died!");
    }
    @Override
    public double recoverMagic() {
        this.magic+=MAGICRATE;
        return MAGICRATE;
    }

    @Override
    public String toString() {
        return "Witch - " + super.toString();
    }
}
