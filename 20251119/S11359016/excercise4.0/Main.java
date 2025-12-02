package oop4_0;
import java.security.SecureRandom;

public class Main {
	public static void main(String[] args) {
		SecureRandom r=new SecureRandom();
		
		ROLE[] roles=new ROLE[9];
		roles[0]=new Warrior("A");
		roles[1]=new Warrior("B");
		roles[2]=new Warrior("C");
		roles[3]=new Witch("X");
		roles[4]=new Witch("Y");
		roles[5]=new Witch("Z");
		
		while(true) {
			int i=r.nextInt(6);
			int j=r.nextInt(6);
			if(i==j) continue;
			
			ROLE a=roles[i];
			ROLE b=roles[j];
			
			if(a instanceof Warrior) 
				((Warrior)a).NewMoon(b);
			else if(a instanceof Witch) 
				((Witch)a).SmallFire(b);
			
			if(a.getLife()<=0 || b.getLife()<=0) {
				System.out.println(a);
				System.out.println(b);
				break;
			}
			System.out.println(a.getName()+" hit "+b.getName());
			System.out.println(b.getName()+" hit "+a.getName());
			System.out.println();
			
			if (a.getLife() < 100 || a.getMagic() < 70) {
			    int p = r.nextInt(100);
			    Drug d;
			    if (p < 10) d = new RedDrug("Large");
			    else if (p < 40) d = new RedDrug("Medium");
			    else if (p < 80) d = new RedDrug("Small");
			    else d = null;

			    if (d != null) a.Drink(d);
			    else System.out.println(a.getName() + " skipped drink.");
			}

			if (b.getLife() < 100 || b.getMagic() < 70) {
			    int p = r.nextInt(100);
			    Drug d;
			    if (p < 10) d = new BlueDrug("Large");
			    else if (p < 40) d = new BlueDrug("Medium");
			    else if (p < 80) d = new BlueDrug("Small");
			    else d = null;

			    if (d != null) b.Drink(d);
			    else System.out.println(b.getName() + " skipped drink.");
			}
			if (a instanceof LifeRecoverable) {
			    double val = ((LifeRecoverable) a).recoverLife();
			    System.out.println(a.getName() + " recovers +" + val + " LIFE");
			}
			if (a instanceof MagicRecoverable) {
			    double val = ((MagicRecoverable) a).recoverMagic();
			    System.out.println(a.getName() + " recovers +" + val + " MAGIC");
			}
			if (b instanceof LifeRecoverable) {
			    double val = ((LifeRecoverable) b).recoverLife();
			    System.out.println(b.getName() + " recovers +" + val + " LIFE");
			}
			if (b instanceof MagicRecoverable) {
			    double val = ((MagicRecoverable) b).recoverMagic();
			    System.out.println(b.getName() + " recovers +" + val + " MAGIC");
			}
		}
	}
}