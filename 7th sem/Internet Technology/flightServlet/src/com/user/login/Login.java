package com.user.login;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/user/Login")
public class Login extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String email = request.getParameter("email");
		String password = request.getParameter("pass");
		
		
		Customer customer = new Customer(email, password);
		LoginDao lDao = new LoginDao();
		if(lDao.check(customer)) {
			
			HttpSession session = request.getSession();
			session.setAttribute("username", customer.getEmail());
			response.sendRedirect("../home.jsp");
		}
		else {
			
			HttpSession session = request.getSession();
			session.setAttribute("message","incorrect Email or password");
			response.sendRedirect("userlogin.jsp");
			
		}
	}

	

}
