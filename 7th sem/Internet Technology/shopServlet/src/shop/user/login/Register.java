package shop.user.login;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/Register")
public class Register extends HttpServlet {
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String fname = request.getParameter("first_name");
		String lname = request.getParameter("last_name");
		String email = request.getParameter("email");
		String pass = request.getParameter("password");
		String gender = request.getParameter("gender");
		String prefer = request.getParameter("prefer");
		
		UserRegister user = new UserRegister(fname, lname, email, pass, gender, prefer);
		UserDao uDao = new UserDao();
		boolean res = uDao.insertUserData(user);
		
		response.getWriter().print(res);
		
		if(res) {
			HttpSession session = request.getSession();
			session.setAttribute("message","Register Success");
			response.sendRedirect("login_register.jsp");
		}
		else {
			HttpSession session = request.getSession();
			session.setAttribute("message","Register Fails");
			response.sendRedirect("login_register.jsp");
		}
		
		
	}

	
}
