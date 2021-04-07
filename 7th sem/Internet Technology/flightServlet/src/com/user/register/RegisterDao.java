package com.user.register;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class RegisterDao {
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
	
	public boolean insert(Customer customer) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		boolean res = false;
		
		String sql = "insert into firstschema.customer values(?, ?, ?, ?, ?, ?)";
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, customer.getUname());
			st.setString(2, customer.getEmail());
			st.setString(3, customer.getPassword());
			st.setString(4, customer.getPhone());
			st.setString(5, customer.getAddress());
			st.setString(6, customer.getPassport());
			res = st.executeUpdate()>0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			//res = "Data not successed";
		}
		return res;
		
	}
}
