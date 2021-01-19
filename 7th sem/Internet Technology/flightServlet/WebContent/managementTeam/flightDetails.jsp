<%@ page import="java.sql.DriverManager"%>
<%@ page import="java.sql.ResultSet"%>
<%@ page import="java.sql.Statement"%>
<%@ page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>

	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

	
	

</head>

<header>
  		<!-- Header -->
  	<jsp:include page="../template/adminHeader.jsp" />   
  </header>
  
<body>
	 <!-- Header -->
  
  <style>
  	.pos{
  		position:relative;
  		left:45%;
  	}
  	.addpos{
  		position:absolute;
  		left:80%;
  		top:80px;
  	}
  </style>
  
  <h5 class="pos">Flight Information</h5>
  <hr class="white" width="500px" align="center">
  
  <div class="row">
  
  <div class="col s6">
  		<a href="addflight.jsp" class="btn btn-primary blue addpos">Add New Data</a>
  </div>
  </div>
  
  
  <div class="row">
  	<div class="col s12">
  		
  		<div class="card">
  		
	<table class="centered">
        <thead class="grey darken-4 white-text">
          <tr>
              <th>Company</th>
              <th>Flight No.</th>
              <th>Source</th>
              <th>Destination</th>
              <th>Departure Date</th>
              <th>Departure Time</th>
              <th>Sitting Capacity</th>
              <th>Legs</th>
              <th>Price</th>
              <th>Special offer</th>
              <th>Special validity</th>
              <th>Action</th>
              
          </tr>
        </thead>

        <tbody>
        <% 
        String dburl = "jdbc:mysql://localhost:3306/firstschema";
    	String dbusername = "root";
    	String dbpassword = "Tomcat@123";
    	String dbdriver = "com.mysql.jdbc.Driver" ;
    	Connection conn = null;
    	ResultSet res = null;
    	Statement stat = null;
    	Class.forName(dbdriver);
    	conn = DriverManager.getConnection(dburl, dbusername, dbpassword);
        stat = conn.createStatement();
        String sql = "select * from firstschema.flightAdd";
        res = stat.executeQuery(sql);
        while(res.next()){
        %>
          <tr>
            <td><%=res.getString("company") %></td>
            <td><%=res.getInt("fno") %></td>
            <td><%=res.getString("src") %></td>
            <td><%=res.getString("dest") %></td>
            <td><%=res.getString("dept_date") %></td>
            <td><%=res.getString("dept_time") %></td>
            <td><%=res.getInt("capacity") %></td>
            <td><%=res.getInt("seat_left") %></td>
            <td><%=res.getInt("price") %></td>
            <td><%=res.getString("special_offer") %></td>
            <td><%=res.getString("special_limit") %></td>
            <td>
            	
			  	
					
					<%-- <button class="btn btn-primary red" name="delete" onclick="deleteData(<%=res.getInt("fno") %>);">Delete</button> --%>
					<form action="AdminFlightDelete" method="post">
			        <button class="btn btn-primary red">Delete</button>
			        <input type="hidden" name="fnum" value="<%=res.getInt("fno")%>" />
			    </form>
					
					
				</div>
				
		  		</td>
          </tr>
          <% }%>
        </tbody>
      </table>
      </div>
  	</div>
  </div>
  
      
</body>
</html>