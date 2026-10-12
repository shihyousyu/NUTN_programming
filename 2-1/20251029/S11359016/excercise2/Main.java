package oop2;
import java.security.SecureRandom;

public class Main {
	public static void main(String[] args) {
		SecureRandom r=new SecureRandom();
		Warrior[] w=new Warrior[3];
		Witch[] t=new Witch[3];

		w[0]=new Warrior("A");
		w[1]=new Warrior("B");
		w[2]=new Warrior("C");

		t[0]=new Witch("X");
		t[1]=new Witch("Y");
		t[2]=new Witch("Z");

		while(true) {
			Warrior a=w[r.nextInt(3)];
			Witch b=t[r.nextInt(3)];
			a.NewMoon(b);
			if(b.getLife() <= 0) break;
			Warrior target = w[r.nextInt(3)];
			Witch attacker = t[r.nextInt(3)];
			attacker.SmallFire(target);
			if(target.getLife() <= 0) break;

			if(a.getLife()<=0 || b.getLife()<=0) {
				System.out.println(a);
				System.out.println(b);
				break;
			}
			System.out.println(a.getName()+" hit "+b.getName());
			System.out.println(attacker.getName()+" hit "+target.getName());
			System.out.println();
		}
	}
}
