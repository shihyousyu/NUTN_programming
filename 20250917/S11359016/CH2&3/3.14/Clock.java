public class Clock{
    private int hour;
    private int minute;
    private int second;

    public Clock(){}
    public Clock(int h, int m, int s){
        hour = h;
        minute = m;
        second = s;
    }

    public void setHour(int h){hour = h;}
    public void setMinute(int m){minute = m;}
    public void setSecond(int s){second = s;}

    public int getHour(){return (hour > 23 || hour < 0) ? 0 : hour;}
    public int getMinute(){return (minute > 59 || minute < 0) ? 0 : minute;}
    public int getSecond(){return (second > 59 || second < 0) ? 0 : second;}

    public void displayTime(){System.out.printf("%d:%d:%d", hour, minute, second);}
}
