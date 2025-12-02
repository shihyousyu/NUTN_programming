package oop3;

public class BlueDrug extends Drug {
    int addMagic;

    public BlueDrug(String size) {
        super(size);
        if(size.equals("Large")) addMagic = 100;
        else if(size.equals("Medium")) addMagic = 60;
        else addMagic = 30;
    }
}
