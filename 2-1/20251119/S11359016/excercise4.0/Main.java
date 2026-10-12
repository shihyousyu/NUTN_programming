package oop4_0;
import java.security.SecureRandom;

public class Main {
	public static void main(String[] args) {
		SecureRandom r=new SecureRandom();

		ROLE[] roles=new ROLE[6];
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
			System.out.println();

            recoverWithDrugs(a, r);
            recoverWithDrugs(b, r);

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
    static void recoverWithDrugs(ROLE role, SecureRandom random){
        if(role.getLife() < 100){
            String size = randomSize(random);
            if(size != null) role.Drink(new RedDrug(size));
        }
        if(role.getMagic() < 70){
            String size = randomSize(random);
            if(size != null) role.Drink(new BlueDrug(size));
        }
    }
    static String randomSize(SecureRandom random){
        int value = random.nextInt(100);
        if(value < 10) return "Large";
        if(value < 40) return "Medium";
        if(value < 80) return "Small";
        return null;
    }

}
