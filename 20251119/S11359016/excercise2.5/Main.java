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
			System.out.println(b.getName()+" hit "+a.getName());
			System.out.println();
		}
	}
}