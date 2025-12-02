package oop4_0;

public abstract class Drug {
	protected String size;
	public Drug() {this.size=" ";}
	public Drug(String size) {this.size=size;}
	void setSize(String size) {this.size=size;}
	String getSize() {return size;}
}