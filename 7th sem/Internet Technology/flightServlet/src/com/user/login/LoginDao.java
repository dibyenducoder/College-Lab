package com.user.login;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class LoginDao {
	
	private String dburl = "jdbc:mysql://localhost:3306/firstschema";
	private String dbusername = "root";
	private String dbpassword = "Tomcat@123";
	private String dbdriver = "com.mysql.jdbc.Driver" ;
	
	public void loadDriver(String dbDriver)
	{
		try {
			Class.forName(dbDriver);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public Connection getConnection()
	{
		Connection conn = null;
		try {
			conn = DriverManager.getConnection(dburl, dbusername, dbpassword);
		}
		catch (SQLException e) {
			e.printStackTrace();
		}
		
		return conn;
	}
	
	public boolean check(Customer customer) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		
		
		String sql = "select email, password from firstschema.customer where email=? and password=?";
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, customer.getEmail());
			st.setString(2, customer.getPassword());
			ResultSet rs = st.executeQuery();
			
			if(rs.next()) {
				return true;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
		return false;
		
	}

}
