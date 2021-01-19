
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
	<script src="js/home.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
	<script src="https://unpkg.com/@lottiefiles/lottie-player@latest/dist/lottie-player.js"></script>
	
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"> -->
	<!-- google CSS -->
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<title>Register Page</title>
    
  </head>
  <style>
      .card{
       width:400px;   
      }
  </style>
  <body>
	
	<section id="userlogin">
	
	<c:if test="${not empty message}">
		    <h3 style='color:green'>${message}</h3>
    <c:remove var="message"/></c:if>
    
    
		<div class="card z-depth-3">
			<div class="card-panel center grey darken-3">
				<span class="card-title white-text">Register</span>
				<lottie-player src="https://assets2.lottiefiles.com/packages/lf20_mr1kkmr2.json"  background="transparent"  speed="1"  style="justify-content: center;" loop  autoplay></lottie-player>
			</div>
			<form class="form" action="Register" method="post">
                <div class="input-field ">
                	<i class="material-icons prefix">account_circle</i>
					<input type="text" class="validate" name="uname">
					<label>Name</label>
				</div>
                                
				<div class="input-field">
					<i class="material-icons prefix">email</i>
					<input type="email" class="validate" name="email">
					<label>Email</label>
				</div>
				<div class="input-field">
					<i class="material-icons prefix">vpn_key</i>
					<input type="password" class="validate" name="password">
					<label>Password</label>
				</div>
                 
                 <div class="input-field">
                	<i class="material-icons prefix">phone</i>
					<input type="text" class="validate" name="phone">
					<label>Contact</label>
				</div>
				           
                <div class="input-field">
                	<i class="material-icons prefix">home</i>
					<input type="text" class="validate" name="address">
					<label>Address</label>
				</div>
                            
                 <div class="input-field">
                 	<i class="material-icons prefix">credit_card</i>
					<input type="text" class="validate" name="passport">
					<label>Passport Number</label>
				</div>
                            
                 <style>
                 	.color{
                 		background-color: rgb(38, 38, 38);
           
                 	}
                 	.color:hover{
                 		background-color:green;
                 	}
                 </style>           
				<div class="center">
					<button type="submit" class="btn-large color darken-3">Submit</button>
				</div>
				<div class="center pt-1">
					<a href="userlogin.jsp">Login Here</a>
				</div>
			</form>
		</div>
	</section>
    
    <!-- JS Library -->
    
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" ></script>
    <!--<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" ></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script> -->
  	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  	<script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
  </body>
</html>