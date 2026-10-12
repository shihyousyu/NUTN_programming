import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        int[] values = new int[5];
        for(int i = 0; i < 5; i++) values[i] = input.nextInt();
        for(int value : values) {
            for(int j = 0; j < value; j++) System.out.print("*");
            System.out.println();
        }

        input.close();
    }
}
