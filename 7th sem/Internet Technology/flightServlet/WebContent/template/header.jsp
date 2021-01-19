<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>

<!-- My JS -->
	<script src="js/home.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
	
	
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"> -->
	<!-- google CSS -->
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
	<div class="navbar-fixed">
	<% if(session.getAttribute("username")==null)
	  { 
	  %>
	  		<!-- Navigation -->
  <ul id="dropdown1" class="dropdown-content grey darken-4 white-text">
  	<li><a href="user/userlogin.jsp">User</a></li>
  	<li><a href="managementTeam/managerlogin.jsp">Management Team</a></li>
  </ul>

  <nav class="grey darken-4">
    <div class="nav-wrapper">
      <a href="#" class="brand-logo">AirTravel</a>
      <ul id="nav-mobile" class="right hide-on-med-and-down">
        <li><a href="">Home</a></li>
        <li><a href="">Flight</a></li>
        <li><a class="dropdown-trigger" href="" data-target="dropdown1">Hi, Guest<i class="material-icons right">arrow_drop_down</i></a></li>
      	

  
      </ul>
    </div>
  </nav>
	 <% 
	 } 
	  
	else { %>
	 		  		<!-- Navigation -->
  <ul id="dropdown1" class="dropdown-content grey darken-4 white-text">
  	<li><a href="#!">Your Profile</a></li>
  	<li><a href="template/Logout">Logout</a></li>
  </ul>

  <nav class="grey darken-4">
    <div class="nav-wrapper">
      <a href="#" class="brand-logo">AirTravel</a>
      <ul id="nav-mobile" class="right hide-on-med-and-down">
        <li><a href="">Home</a></li>
        <li><a href="">Flight</a></li>
        <li><a class="dropdown-trigger" href="#!" data-target="dropdown1">Hi, ${username}<i class="material-icons right">arrow_drop_down</i></a></li>
      	

  
      </ul>
    </div>
  </nav>
	 <% 
	 } 
	
	 %>
</div>
 
<script type="text/javascript">
	 $(document).ready(function(){
      $(".dropdown-trigger").dropdown();
    });
</script>
  
  <!-- End of Nav -->
  
  
</body>
</html>