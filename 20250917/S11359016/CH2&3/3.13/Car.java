public class Car{
    private String model;
    private String year;
    private double price;

    public Car(){}
    public Car(String m, String y, double p){
        model = m;
        year = y;
        if (p >= 0) price = p;
    }

    public void setModel(String m){model = m;}
    public void setYear(String y){year = y;}
    public void setPrice(double p){price = p;}

    public String getModel(){return model;}
    public String getYear(){return year;}
    public double getPrice(){return price;}
}