import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int[] numbers = new int[5];
        for(int i = 0; i < numbers.length; i++){
            int n = input.nextInt();
            if(n < 1 || n > 30){
                System.out.println("Enter a number between 1 and 30.");
                i--;
            }else numbers[i] = n;
        }
        for(int n : numbers){
            for(int j = 0; j < n; j++) System.out.print("*");
            System.out.println();
        }

        input.close();
    }
}
