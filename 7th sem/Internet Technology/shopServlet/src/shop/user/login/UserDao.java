package shop.user.login;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



public class UserDao {
	
	
	private String dburl = "jdbc:mysql://localhost:3306/app_store";
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
	
public ResultSet checkLogin(String email, String pass) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		
		
		String sql = "select * from app_store.user where email='"+ email +"' and password='"+ pass +"'";
		//String sql = "select * from app_store.user where email=\'"+email+"'\" and password=\'"+pass+"\'";;
		
		try {
			PreparedStatement st = conn.prepareStatement(sql);
//			st.setString(1, email);
//			st.setString(2, pass);
			ResultSet rs = st.executeQuery();
			
			if(rs.next()) {
				return rs;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		}
		return null;
		
	}
public boolean insertUserData(UserRegister user) {
		
		loadDriver(dbdriver);
		Connection conn = getConnection();
		boolean res = false;
		
		String sql = "insert into app_store.user values(?, ?, ?, ?, ?, ?)";
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, user.getFname());
			st.setString(2, user.getLname());
			st.setString(3, user.getEmail());
			st.setString(4, user.getPassword());
			st.setString(5, user.getGender());
			st.setString(6, user.getPrefer());
			
			res = st.executeUpdate()>0;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			//res = "Data not successed";
		}
		return res;
		
	}

public ResultSet getClothes(String gender, String prefer) {
	
	loadDriver(dbdriver);
	Connection conn = getConnection();
	
	
	String sql = "select * from app_store.clothesData where gender='"+ gender +" and prefer='"+ prefer +"'";
	
	try {
		PreparedStatement st = conn.prepareStatement(sql);

//		st.setString(1, user.getFname());
//		st.setString(2, user.getLname());
//		st.setString(3, user.getEmail());
//		st.setString(4, user.getPassword());
//		st.setString(5, user.getGender());
//		st.setString(6, user.getPrefer());
		ResultSet rs = st.executeQuery();
		
		if(rs.next()) {
			return rs;
		}
	} catch (SQLException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		
	}
	return null;
	
}

}
