import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        double commission = 0;
        double[] item = {239.99, 129.75, 99.95, 350.89};

        Scanner input = new Scanner(System.in);

        for(int i = 0; i < 4; i++){
            System.out.printf("item %d: ", i + 1);
            commission += input.nextInt() * item[i];
        }

        commission = commission * 0.09 + 200;
        System.out.printf("commission: $%.2f", commission);

        input.close();
    }
}
