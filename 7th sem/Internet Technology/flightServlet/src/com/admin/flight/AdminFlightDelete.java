package com.admin.flight;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class AdminFlightDelete
 */
@WebServlet("/managementTeam/AdminFlightDelete")
public class AdminFlightDelete extends HttpServlet {
	

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		int fnum = Integer.parseInt(request.getParameter("fnum"));
		AdminFlightDao afDao = new AdminFlightDao();
		boolean rowdelete = afDao.delete(fnum);
		//response.getWriter().print(res);
		if(rowdelete) {
			RequestDispatcher rd=request.getRequestDispatcher("flightDetails.jsp");            
			rd.include(request, response);
		}
		else {
			HttpSession session = request.getSession();
			session.setAttribute("message","Delete Fails");
			response.sendRedirect("flightDetails.jsp");
		}
		
	}

}
