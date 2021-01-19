<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	
	<!-- My CSS -->
	<link rel="stylesheet" href="../css/userlogin.css">
	
	<!-- My JS -->
	
     <script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
	<script src="https://unpkg.com/@lottiefiles/lottie-player@latest/dist/lottie-player.js"></script>
	
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"> -->
	<!-- google CSS -->
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<title>Login Page</title>
    
  </head>
  
  

  
  <body>
	<%-- <%
	String login_msg=(String)request.getAttribute("error");  
	if(login_msg!=null)
	out.println("<font color=red size=4px>"+login_msg+"</font>");
%> --%>
	<section id="userlogin">
		<div class="card z-depth-3">
			<div class="card-panel center grey darken-3">
				<a href="user_register.jsp"><i class="tooltipped material-icons right white-text" data-position="bottom" data-tooltip="Click me for Register" style="cursor:pointer;">account_circle</i></a>
				
				<span class="card-title white-text">Login</span>
				<lottie-player src="https://assets2.lottiefiles.com/packages/lf20_mr1kkmr2.json"  background="transparent"  speed="1"  style="justify-content: center;" loop  autoplay></lottie-player>
			</div>
			<form action="Login" class="form" method="get">
				<div class="input-field">
					
					<i class="material-icons prefix" id="email">email</i>
					<input type="email" class="validate" name="email" id="email" required>
					<label>Email</label>
				</div>
				<div class="input-field">
					<i class="material-icons prefix">vpn_key</i>
					<input type="password" class="validate" name="pass">
					<label>Password</label>
				</div>
				<div class="center">
					<button type="submit" class="btn-large grey darken-3">Submit</button>
				</div>
				
				<div class="center pt-1 col">
					<a href="#">Forgot Password?</a>
				</div>
				
				 
			</form>
		</div>
	</section>
	
    
    <!-- JS Library -->
    <script>
    $(document).ready(function(){
        $('.tooltipped').tooltip();
      });
    </script>
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" ></script>
    <!--<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" ></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script> -->
  	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  	<script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
  </body>
</html>