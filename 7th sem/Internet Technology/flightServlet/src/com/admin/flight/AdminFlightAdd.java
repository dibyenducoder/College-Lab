package com.admin.flight;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/managementTeam/AdminFlightAdd")


public class AdminFlightAdd extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String company = request.getParameter("company");
		int fno = Integer.parseInt(request.getParameter("fno"));
		String src = request.getParameter("src");
		String dest = request.getParameter("dest");
		String dept_date = request.getParameter("dept_date");
		String dept_time = request.getParameter("dept_time");
		int capacity = Integer.parseInt(request.getParameter("capacity"));
		int seat_left = Integer.parseInt(request.getParameter("seat_left"));
		int price = Integer.parseInt(request.getParameter("price"));
		String special_offer = request.getParameter("special_offer");
		String special_limit = request.getParameter("special_limit");
		
//
		System.out.print("Hi"+special_offer);
		FlightDetails admin = new FlightDetails(company, fno, src, dest, dept_date, dept_time, capacity, seat_left, price, special_offer, special_limit);
		AdminFlightDao afDao = new AdminFlightDao();
		boolean res = afDao.insert(admin);
		//response.getWriter().print(res);
		
		
		if(res) {
			RequestDispatcher rd=request.getRequestDispatcher("flightDetails.jsp");            
			rd.include(request, response);
		}
		else {
			HttpSession session = request.getSession();
			session.setAttribute("message","Flight Number must be unique or maybe there is internal server problem!");
			response.sendRedirect("flightDetails.jsp");
		}
//		System.out.println(5);
		
	}

}
