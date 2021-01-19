package com.user.register;

public class Customer {
	private String uname, email, password, phone, address, passport;
	
	
	public Customer() {
		super();
	}


	public Customer(String uname, String email, String password, String phone, String address, String passport) {
		super();
		this.uname = uname;
		this.email = email;
		this.password = password;
		this.phone = phone;
		this.address = address;
		this.passport = passport;
	}


	public String getUname() {
		return uname;
	}


	public void setUname(String uname) {
		this.uname = uname;
	}


	public String getEmail() {
		return email;
	}


	public void setEmail(String email) {
		this.email = email;
	}


	public String getPassword() {
		return password;
	}


	public void setPassword(String password) {
		this.password = password;
	}


	public String getPhone() {
		return phone;
	}


	public void setPhone(String phone) {
		this.phone = phone;
	}


	public String getAddress() {
		return address;
	}


	public void setAddress(String address) {
		this.address = address;
	}


	public String getPassport() {
		return passport;
	}


	public void setPassport(String passport) {
		this.passport = passport;
	}
	
	
}
