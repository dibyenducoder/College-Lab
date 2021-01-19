package shop.user.login;

public class UserRegister {
	String fname, lname, email, password, gender, prefer ;

	
	
	public UserRegister() {
		super();
		
	}

	public UserRegister(String fname, String lname, String email, String password, String gender, String prefer) {
		super();
		this.fname = fname;
		this.lname = lname;
		this.email = email;
		this.password = password;
		this.gender = gender;
		this.prefer = prefer;
	}

	public String getFname() {
		return fname;
	}

	public void setFname(String fname) {
		this.fname = fname;
	}

	public String getLname() {
		return lname;
	}

	public void setLname(String lname) {
		this.lname = lname;
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

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getPrefer() {
		return prefer;
	}

	public void setPrefer(String prefer) {
		this.prefer = prefer;
	}
	
}
