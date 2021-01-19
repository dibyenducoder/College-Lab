package com.user.register;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/user/Register")
public class Register extends HttpServlet {
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String uname = request.getParameter("uname");
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		String phone = request.getParameter("phone");
		String address = request.getParameter("address");
		String passport = request.getParameter("passport");
		
		Customer customer = new Customer(uname, email, password, phone, address, passport);
		RegisterDao rDao = new RegisterDao();
		boolean res = rDao.insert(customer);
		response.getWriter().print(res);
		
		if(res) {
			HttpSession session = request.getSession();
			session.setAttribute("message","Success");
			response.sendRedirect("user_register.jsp");
		}
		else {
			HttpSession session = request.getSession();
			session.setAttribute("message","Fails");
			response.sendRedirect("user_register.jsp");
		}
	}

}
