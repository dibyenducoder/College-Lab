package com.admin.login;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


/**
 * Servlet implementation class AdminLogin
 */
@WebServlet("/managementTeam/AdminLogin")
public class AdminLogin extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String eid = request.getParameter("eid");
		String ecode = request.getParameter("ecode");
		PrintWriter out = response.getWriter();
		
		Admin admin = new Admin(eid, ecode);
		AdminLoginDao alDao = new AdminLoginDao();
		if(alDao.check(admin)) {
			
			HttpSession session = request.getSession();
		//	session.setAttribute("username", customer.getEmail());
			response.sendRedirect("addflight.jsp");
		}
		else {
			
			out.println("<script src='https://cdnjs.cloudflare.com/ajax/libs/limonte-sweetalert2/6.11.4/sweetalert2.all.js'></script>");
			out.println("<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>");
			out.println("<script>");
			out.println("$(document).ready(function(){");
			out.println("swal('incorrect Employee ID or Employee CODE', '', 'error');");
			out.println("});");
			out.println("</script>");
			
			
			//request.setAttribute("error","Invalid Username or Password");
			RequestDispatcher rd=request.getRequestDispatcher("managerlogin.jsp");            
			rd.include(request, response);
			//response.sendRedirect("userlogin.jsp");
	
		}
	}
}
