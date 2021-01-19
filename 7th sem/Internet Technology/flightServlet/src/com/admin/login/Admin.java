package com.admin.login;

public class Admin {
	private String eid, ecode;
	
	
	public Admin() {
		super();
	}


	public Admin(String eid, String ecode) {
		super();
		this.eid = eid;
		this.ecode = ecode;
	}


	public String getEid() {
		return eid;
	}


	public void setEid(String eid) {
		this.eid = eid;
	}


	public String getEcode() {
		return ecode;
	}


	public void setEcode(String ecode) {
		this.ecode = ecode;
	}
	
	
}
