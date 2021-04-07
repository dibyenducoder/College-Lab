package com.admin.flight;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Types;


public class AdminFlightDao {
	
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
	
	public boolean insert(FlightDetails flightdetails) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		//String res = "Data Enter Succesfull";
		boolean res = false ;
		
		String sql = "insert into firstschema.flightAdd values(?,?,?,?,?,?,?,?,?,?,?)";
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, flightdetails.getCompany());
			st.setInt(2, flightdetails.getFno());
			st.setString(3, flightdetails.getSrc());
			st.setString(4, flightdetails.getDest());
			st.setString(5, flightdetails.getDept_date());
			st.setString(6, flightdetails.getDept_time());
			st.setInt(7, flightdetails.getCapacity());
			st.setInt(8, flightdetails.getSeat_left());
			st.setInt(9, flightdetails.getPrice());
			st.setString(10, flightdetails.getSpecial_offer());
			st.setString(11, flightdetails.getSpecial_limit());
			
			res = st.executeUpdate()>0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			//res = "Data not successed";
		}
		return res;
		
	}
	
	
public boolean delete(int fno) {
	    boolean rowdelete = false ;
		loadDriver(dbdriver);
		Connection conn = getConnection();
		//String res = "Data delete Succesfull";
		
		String sql = "delete from firstschema.flightAdd where fno="+fno;
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			
			rowdelete = st.executeUpdate() > 0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
//			res = "Data not successed";
		}
		return rowdelete;
		
	}



}
