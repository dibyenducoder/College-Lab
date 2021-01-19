package com.admin.flight;

public class FlightDetails {
		
	private int fno, capacity, seat_left, price ; 
	private String company, src, dest, dept_date, dept_time, special_limit, special_offer;
	
	
	public FlightDetails() {
		super();
	}


	public FlightDetails(String company, int fno, String src,
			String dest, String dept_date, String dept_time, int capacity, int seat_left, int price, String special_offer,String special_limit) {
		super();
		this.company = company;
		this.fno = fno;
		this.capacity = capacity;
		this.seat_left = seat_left;
		this.price = price;
		this.special_offer = special_offer;
		this.src = src;
		this.dest = dest;
		this.dept_date = dept_date;
		this.dept_time = dept_time;
		this.special_limit = special_limit;
	}

	
	public String getCompany() {
		return company;
	}


	public void setCompany(String company) {
		this.company = company;
	}


	public int getFno() {
		return fno;
	}


	public void setFno(int fno) {
		this.fno = fno;
	}


	public int getCapacity() {
		return capacity;
	}


	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}


	public int getSeat_left() {
		return seat_left;
	}


	public void setSeat_left(int seat_left) {
		this.seat_left = seat_left;
	}


	public int getPrice() {
		return price;
	}


	public void setPrice(int price) {
		this.price = price;
	}


	

	public String getSpecial_offer() {
		return special_offer;
	}


	public void setSpecial_offer(String special_offer) {
		this.special_offer = special_offer;
	}


	public String getSrc() {
		return src;
	}


	public void setSrc(String src) {
		this.src = src;
	}


	public String getDest() {
		return dest;
	}


	public void setDest(String dest) {
		this.dest = dest;
	}


	public String getDept_date() {
		return dept_date;
	}


	public void setDept_date(String dept_date) {
		this.dept_date = dept_date;
	}


	public String getDept_time() {
		return dept_time;
	}


	public void setDept_time(String dept_time) {
		this.dept_time = dept_time;
	}


	public String getSpecial_limit() {
		return special_limit;
	}


	public void setSpecial_limit(String special_limit) {
		this.special_limit = special_limit;
	}
	
	
}
