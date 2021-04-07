package com.admin.login;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.user.login.Customer;

public class AdminLoginDao {
	
	private String dburl = "jdbc:mysql://localhost:3306/firstschema";
	private String dbusername = "root";
	private String dbpassword = "";
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
	
	public boolean check(Admin admin) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		
		
		String sql = "select * from firstschema.admin where eid=? and ecode=?";
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, admin.getEid());
			st.setString(2, admin.getEcode());
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
