package oop4;

public class ROLE {
    protected String name;
    protected int life;
    protected int magic;

    public ROLE() {this("", 0, 0);}
    public ROLE(String name, int life, int magic) {
        this.name=name;
        this.life=life;
        this.magic=magic;
    }

    public String getName() {return name;}
    public int getLife() {return life;}
    public int getMagic() {return magic;}

    public void setLife(int life) {this.life=life;}
    public void setMagic(int magic) {this.magic=magic;}

    @Override
    public String toString() {
        return "Name: "+name+"  Life: "+life+"  Magic: "+magic;
    }
}