import java.util.Random;

public class Main{
    static Random rand = new Random();

    public static int TortoiseMove(){
        int i = rand.nextInt(10) + 1;
        if(i <= 5)
            return 3;
        else if(i == 6 || i == 7)
            return -6;
        else return 1;
    }

    public static int HareMove(){
        int i = rand.nextInt(10) + 1;
        if(i == 1 || i == 2)
            return 0;
        else if(i == 3 || i == 4)
            return 9;
        else if(i == 5)
            return -12;
        else if(i <= 8)
            return 1;
        else return -2;
    }

    public static void PrintTrack(int tortoise, int hare){
        StringBuilder track = new StringBuilder();

        for(int i = 0; i <= 70; i++){
            if(i == tortoise && i == hare){
                track.append("OUCH!!!");
                i += 6;
            }
            else if(i == tortoise)
                track.append("T");
            else if(i == hare)
                track.append("H");
            else track.append(" ");
        }
        System.out.println(track);
    }

    public static void main(String[] args){
        int tortoise = 1, hare = 1;

        System.out.println("BANG !!!!!");
        System.out.println("AND THEY'RE OFF");

        while(tortoise < 70 && hare < 70){
            tortoise += TortoiseMove();
            hare += HareMove();

            if(tortoise < 1) tortoise = 1;
            if(hare < 1) hare = 1;

            PrintTrack(tortoise, hare);
        }

        if(tortoise >= 70 && hare >= 70)
            System.out.println("It's a tie");
        else if(tortoise >= 70)
            System.out.println("TORTOISE WINS!!! YAY!!!");
        else System.out.println("Hare wins. Yuch.");
    }
}