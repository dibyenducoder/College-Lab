package shop.user.login;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/Login")
public class Login extends HttpServlet {
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String email = request.getParameter("email");
		String pass = request.getParameter("pass");
		
		//PrintWriter out = response.getWriter();
		
		HttpSession session=request.getSession();
	    UserDao uDao = new UserDao();
		ResultSet rs = null;
		rs = uDao.checkLogin(email, pass);
		
       if(rs!=null)
		{
   	   UserRegister user = null;
		
		try
		{
			user = new UserRegister( rs.getString("fname"), rs.getString("lname"), rs.getString("email"), rs.getString("password"), rs.getString("gender"), rs.getString("prefer"));
		} 
		catch (SQLException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("hello");
			
//			
	//	    session.setAttribute("user", user);
	//		session.setAttribute("udao", uDao);
			session.setAttribute("user", user);
//			
//			System.out.println("hiiiiiii");
			//response.sendRedirect("home.jsp");
//			out.println("<font color=red size=10px>Helllllllooo</font>");
			RequestDispatcher rd = request.getRequestDispatcher("home.jsp");
            rd.forward(request, response);   
//			response.sendRedirect("home.jsp");
            
 //           out.println("<font color=red size=10px>Helllllllooo</font>");
			return;
			
//			System.out.println("world");
		}
		else {
			session.invalidate();
            request.setAttribute("errorMessage", "Invalid Email or wrong password");
            RequestDispatcher rd = request.getRequestDispatcher("login_register.jsp");
            rd.forward(request, response);       
			
		}
	}

}
