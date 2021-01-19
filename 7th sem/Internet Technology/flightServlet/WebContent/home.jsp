<%@ page import="java.sql.DriverManager"%>
<%@ page import="java.sql.ResultSet"%>
<%@ page import="java.sql.Statement"%>
<%@ page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	
	<!-- My CSS -->
	<link rel="stylesheet" href="css/home.css">
	<link rel="shortcut icon" type="image/x-icon" href="images/penguin.ico?">
	
	<!-- My JS -->
	<script src="js/home.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
	
	
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"> -->
	<!-- google CSS -->
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<title>Home Page</title>
    
  </head>
  
  <!-- Header -->
  <jsp:include page="template/header.jsp" />  
  
  <body style="background-color:#110a08;">
  
  <% String dburl = "jdbc:mysql://localhost:3306/firstschema";
	String dbusername = "root";
	String dbpassword = "Tomcat@123";
	String dbdriver = "com.mysql.jdbc.Driver" ;
	Connection conn = null;
	
	Class.forName(dbdriver);
	conn = DriverManager.getConnection(dburl, dbusername, dbpassword);%>
  
  <!-- Style -->
  <style>
  	
  		.ridge
  		{
  			border-style:ridge;
  		}
		.to{
			position: absolute;
    		bottom: 74%;
    		left: 10px;
		}
		.from{
			position: absolute;
    		bottom: 74%;
    		left: 255px;
		}
		.bottom-right {
  position: absolute;
  bottom: 8px;
  right: 16px;
}
.bottom-right img {
	width:60px;
	position: relative;
    bottom: 650px;
}
	</style>
	
	<!-- End of style -->
	
	
	
  <div class="slider">
    <ul class="slides">
      <li>
        <img src="images/aeroplane.jpg"> <!-- random image -->
        <div class="caption center-align">
          <h3>You are Welcome</h3>
          <h5 class="light grey-text text-lighten-3">Explore with us !</h5>
        </div>
      </li>
      <li>
        <img src="images/safe_travel.jpg"> <!-- random image -->
        <div class="caption left-align">
          <h3>Safe Travel</h3>
          <h5 class="light grey-text text-lighten-3">We are ensured that you will be safe with us.</h5>
        </div>
      </li>
      <li>
        <img src="images/people.jpg"> <!-- random image -->
        <div class="caption right-align">
          <h3>Meet Different People</h3>
          <h5 class="light grey-text text-lighten-3">Join with them and have fun!</h5>
        </div>
      </li>
      <li>
        <img src="images/aerplane2.jpg"> <!-- random image -->
        <div class="caption left-align">
          <h3>Enjoy the journey</h3>
          <h5 class="light grey-text text-lighten-3">Glad to join with us.</h5>
        </div>
      </li>
      <li>
        <img src="images/firstClass.jpg"> <!-- random image -->
        <div class="caption right-align">
          <h3>First Class!</h3>
          <h5 class="light grey-text text-lighten-3">Enjoy the privilege of first class.</h5>
        </div>
      </li>
    </ul>
  </div>
<script type="text/javascript">
	 $(document).ready(function(){
      $('.slider').slider({full_width: true});
    });
</script>



<jsp:include page="searchflights.jsp" />  

<%
  ResultSet res = null;
  Statement stat = null;
  stat = conn.createStatement();
  
 
  String srcQuery = request.getParameter("search_src");
  String destQuery = request.getParameter("search_dest");
  String dateQuery = request.getParameter("search_date");
  %>
  
  <% if(srcQuery==null && destQuery==null && dateQuery==null){ %>
 <h5 class="white-text center">SPECIAL DEALS</h5>
 
 <%} else {%>
 	<h5 class="white-text center">ALL DEALS</h5>
 	<%} %>
  <!-- List -->
  <div class="row">
  
  <%
 
  
  String sql;
  //String sql = "select * from firstschema.flightAdd where src like '%kol%' and dest like '%lahore%'";
//  String sql;
 //  System.out.print(srcQuery); 
 if(srcQuery!=null && destQuery!=null && dateQuery!=null){
  sql = "select * from firstschema.flightAdd where src like '%"+srcQuery+"%' and dest like '%"+destQuery+"%' and dept_date like '%"+dateQuery+"%' ";
 }
 else{
	 sql = "select * from firstschema.flightAdd where special_offer !=''";
 }
  res = stat.executeQuery(sql);
  
  String off =""; 
  if(res.next()) do{
	 String offer = res.getString("special_offer") ;
	 
  %>
  	
  	<div class="column">
	<div class="card">
		<div>
		  <p class="to orange-text"><%=res.getString("src") %></p>
		  <img class="ridge" src="images/travel.jpg">
		  <p class="from green-text"><%=res.getString("dest") %></p>
		  </div>
		  
		  <% if(!res.getString("special_offer").matches("")) { %>
		<div class="bottom-right">
		
		
			<img src="images/special-offer.svg">
		
			
		</div> 
		<%} %>
		  
		  <div class="card-body">
		    <h5 class="card-title"><%=res.getString("company") %></h5>
		  </div>
		  
		  <table>
	        <tbody>
	          <tr>
	            <th>Flight No. :-</th>
	            <td><%=res.getString("fno") %></td>
	          </tr>
	          
	          <tr>
	            <th>Source :-</th>
	            <td><%=res.getString("src") %></td> 
	          </tr>
	          
	           <tr>
	            <th>Destination :-</th>
	            <td><%=res.getString("dest") %></td>  
	          </tr>
	          
	          <tr>
	          	<th>Departure Date :-</th>
	          	<td><%=res.getString("dept_date") %></td>
	          </tr>
	          
	          <tr>
	          	<th>Departure Time:-</th>
	          	<td><%=res.getString("dept_time") %></td>
	          </tr>
	          
	          <tr>
	            <th>Capacity :-</th>
	            <td><%=res.getInt("capacity") %></td>  
	          </tr>
	          
	          <tr>
	            <th>Legs :-</th>
	            <td><%=res.getInt("seat_left") %></td>  
	          </tr>
	          
	          <tr>
	            <th>MRP :-</th>
	            <td><i class="fa fa-rupee"></i> <%=res.getInt("price") %></td>  
	          </tr>
	          
	          
	           <% if(!res.getString("special_offer").matches("")) {%>
	          <tr>
	          
	            <th class="special-offer green-text">SPECIAL OFFER:-</th>
	            <td><%=res.getString("special_offer")%></td> 
	              
	          </tr>
	          
	           <tr>
	          	<th class="special-time">OFFER VALIDITY</th>
	          	<td class="special-time"><%=res.getString("special_limit") %></td>
	          </tr>
	           <%} %>
	           
	           
	          </tbody>
	          </table>
	          
		  <div class="card-action">
		    <a href="user/booking.jsp"><button class="btn waves-effect waves-light" type="submit" name="">Book
			    <i class="material-icons right">send</i>
			  </button></a>
		  </div>
	</div>
	</div>
	
	
	<% 
	} while(res.next());
  else{
	  
	%>
	  <h3 class="red-text center">Sorry! Records not found !</h3>
	<%} %>
	</div>
	
	
	
    
   
  </body>
  <!-- Footer -->
	<footer class="page-footer grey darken-4">
          <div class="container">
            <div class="row">
              <div class="col l6 s12">
                <h5 class="white-text">Welcome to AirTravel</h5>
                <hr class="white" width="30px" align="center">
                <p class="grey-text text-lighten-4">Let's explore to the world !
                	<i class="material-icons">explore</i>
                </p>
              </div>
              <div class="col l4 offset-l2 s12">
                
                <ul class="icons">
                  <li><a class="fa fa-twitter grey-text text-lighten-3" href="#!"></a></li>
                  <li><a class="fa fa-facebook grey-text text-lighten-3" href="#!"></a></li>
                  <li><a class="fa fa-instagram grey-text text-lighten-3" href="#!"></a></li>
                  <li><a class="fa fa-envelope grey-text text-lighten-3" href="#!"></a></li>
                </ul>
              </div>
            </div>
          </div>
          <div class="footer-copyright black">
            <div class="container">
            © 2020 Dibyendu
            <a class="grey-text text-lighten-4 right" href="#!">Coffee</a>
                    <span class="right">
                                 Made with <i class="fa fa-heart"></i>
                         </span>
			
            </div>
          </div>
       </footer>
       
        <!-- JS Library -->
    
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" ></script>
    <!--<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" ></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script> -->
  	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  	<script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
</html>