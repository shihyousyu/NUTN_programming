package oop3;

public class RedDrug extends Drug{
	int addLife;

    public RedDrug(String size) {
        super(size);
        if(size.equals("Large")) addLife = 120;
        else if(size.equals("Medium")) addLife = 80;
        else addLife = 50;
    }
}
