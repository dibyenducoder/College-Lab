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
	<script src=""></script>
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
  <style>
      body{
          overflow:hidden;
      }
.ht-1{
    height:250px;
}
.dp-logo {
   position: relative;
     bottom: 50px;
}
  </style>
  <body>
	
	<section id="userlogin">
		<div class="card z-depth-3">
			<div class="ht-1 card-panel center grey darken-3">
				<span class="card-title white-text">Team Login</span>
                                <p class="sz-2 white-text">(only for management team)</p>
				<lottie-player class="dp-logo" src="https://assets1.lottiefiles.com/temp/lf20_MZmNdq.json"  background="transparent"  speed="1"  style="justify-content: center;" loop  autoplay></lottie-player>
			</div>
			<form action="AdminLogin" class="form" method="get">
				<div class="input-field">
					<input type="text" class="validate" name="eid">
					<label>EID</label>
				</div>
				<div class="input-field">
					<input type="password" class="validate" name="ecode">
					<label>ECode</label>
				</div>
				<div class="center">
					<button type="submit" class="btn-large grey darken-3">Submit</button>
				</div>
				<div class="center pt-1">
					<a href="../user/userlogin.jsp">Customer?</a>
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