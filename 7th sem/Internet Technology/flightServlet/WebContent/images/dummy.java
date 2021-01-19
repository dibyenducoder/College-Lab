

public class BookList extends HttpServlet {
	

	List<Books> slist = new ArrayList<Books> slist();

	protected void getGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		try {

			HttpSession session = request.getSession();
			String username = (String) session.getAttribute("username");
			String sql1 = "select * from users where username='" + username + "'";

			PreparedStatement select1;
			Connection conn = (Connection) getServletContext().getAttribute("DBConnection");
			select1 = conn.prepareStatement(sql1);
			ResultSet result1 = select1.executeQuery();
			result1.next();
			String sql2 = "select * from items where title=' "+ result1.getString("title") +" ' and price_range="
					+ result1.getString("price_range"); //+ "' and admin_id=' "+ result1.getString("admin_id");


			if(sql2==""){
				HttpSession session = request.getSession();
				session.setAttribute("message","No items are available”");
				response.sendRedirect("apparal.jsp");
			}


			PreparedStatement select2;
			select2 = conn.prepareStatement(sql2);
			ResultSet result2 = select2.executeQuery();
			request.setAttribute("update_result", result2);
			RequestDispatcher rd = request.getRequestDispatcher("get_data.jsp");
			rd.forward(request, response);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}


