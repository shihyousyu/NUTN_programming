import java.util.Scanner;

public class CarApplication{
    static Scanner input = new Scanner(System.in);

    static Car inputCar(){
        String model, year;
        double price;

        System.out.print("Model: ");
        model = input.nextLine();
        System.out.print("Year: ");
        year = input.nextLine();
        System.out.print("Price: ");
        price = input.nextFloat();

        Car car = new Car(model, year, price);
        return car;
    }

    static void showCar(Car car){
        System.out.printf("\nModel: %s\n", car.getModel());
        System.out.printf("Year: %s\n", car.getYear());
        System.out.printf("Price: $%.2f\n", car.getPrice());
    }

    public static void main(String[] args){
        Car car1 = inputCar();
        input.nextLine();
        Car car2 = inputCar();

        showCar(car1);
        showCar(car2);

        car1.setPrice(car1.getPrice() * 0.95);
        car2.setPrice(car2.getPrice() * 0.93);

        System.out.printf("Car1 after discount: $%.2f\n", car1.getPrice());
        System.out.printf("Car2 after discount: $%.2f\n", car2.getPrice());

        input.close();
    }
}