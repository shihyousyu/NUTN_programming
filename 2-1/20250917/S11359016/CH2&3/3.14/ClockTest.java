import java.util.Scanner;

public class ClockTest{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int h, m, s;

        System.out.print("Enter hh mm ss: ");
        h = input.nextInt();
        m = input.nextInt();
        s = input.nextInt();

        Clock clock = new Clock(h, m, s);
        clock.setHour(clock.getHour());
        clock.setMinute(clock.getMinute());
        clock.setSecond(clock.getSecond());

        System.out.print("Time: ");
        clock.displayTime();

        input.close();
    }
}