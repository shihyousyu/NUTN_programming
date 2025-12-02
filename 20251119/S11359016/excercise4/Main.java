package oop4;
import java.security.SecureRandom;

public class Main {
    public static void main(String[] args) {
        SecureRandom r=new SecureRandom();

        ROLE[] roles=new ROLE[6];
        roles[0]=new Warrior("A");
        roles[1]=new Warrior("B");
        roles[2]=new Witch("R");
        roles[3]=new Witch("S");
        roles[4]=new Priest("X");
        roles[5]=new Priest("Y");

        while (true){
            int i=r.nextInt(6);
            int j=r.nextInt(6);
            if(i==j) continue;

            ROLE a=roles[i];
            ROLE b=roles[j];

            if (a instanceof Warrior) ((Warrior) a).NewMoon(b);
            else if (a instanceof Witch) ((Witch) a).SmallFire(b);
            else if (a instanceof Priest) ((Priest) a).Dark(b);

            System.out.println(a);
            System.out.println(b);
            System.out.println();

            if (a.getLife()<=0 || b.getLife()<=0){
                System.out.println("Battle ended.");
                break;
            }
        }
    }
}
