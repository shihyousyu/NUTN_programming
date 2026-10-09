import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        int A = 0, B = 0, C = 0, D = 0;

        for(int i = 0; i < 5; i++){
            System.out.print("student " + (i + 1) + " (name grade): ");
            String name = input.next();
            char grade = input.next().charAt(0);

            switch (grade){
                case 'A':
                    A++;
                    break;
                case 'B':
                    B++;
                    break;
                case 'C':
                    C++;
                    break;
                case 'D':
                    D++;
                    break;
                default:
                    System.out.println("Invalid grade entered for " + name);
            }
        }

        System.out.println("\nGrade summary:");
        System.out.println("A: " + A);
        System.out.println("B: " + B);
        System.out.println("C: " + C);
        System.out.println("D: " + D);

        input.close();
    }
}
