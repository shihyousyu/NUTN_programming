import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < 5; i++){
            int n = input.nextInt();
            if(n >= 1 && n <= 30){
                for(int j = 0; j < n; j++){
                    System.out.printf("*");
                }
                System.out.println();
            }
        }

        input.close();
    }
}
