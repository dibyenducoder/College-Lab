<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">

<title>Login Page</title>

<link rel="shortcut icon" href="images/store-logo.png">
<link rel="stylesheet" href="css/login.css">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

</head>

<body class="form-v4">
    
	<div class="page-content">
		<div class="form-v4-content">
			<div class="form-left">
			
				<img src="images/shop-bag.png">
				<p class="text-1">Hello.... Welcome to the Apparel Store</p>
				<p class="text-2"><span>Note:- </span> The store keeps records for its items in our data where
							some items may be discounted and some other items should be displayed as “new arrivals”. 
							You may search for a specific item. 
							By default, when you sign in, based on your profile such as gender male/female,
						  show you preferred set of clothing. In product store, you will be able to look for
                          discounted items mainly, as well as look for new arrivals. 
                           So, depending on your preference already available in our store, 
                           your shopping experience would be different from other site.</p>
                
				<div class="form-left-last">
					<div class="tab-inner">
					    <input type="submit" name="account" class="account" value="New Member?" onclick="openCity(event, 'sign-up')" >
						
					</div>
					<div class="tab-inner">
						<input type="submit" name="account" class="account" value="Have An Account" onclick="openCity(event, 'sign-in')" id="defaultOpen">
					</div>
					
					
				</div>
			</div>
			
			
			<form class="form-detail" action="Register" method="post">
				<div class="tabcontent" id="sign-up">
				<% 
					String register_msg=(String)request.getAttribute("message");  
					if(register_msg!=null && register_msg=="Register Success")
						out.println("<font color=green size=4px>"+register_msg+"</font>");
					
					else if(register_msg!=null && register_msg=="Registered Fails")
						out.println("<font color=red size=4px>"+register_msg+"</font>");
				%> 
				<h2>REGISTER FORM</h2>
				<div class="form-group">
					<div class="form-row form-row-1">
						<label for="first_name">First Name</label>
						<input type="text" name="first_name" id="first_name" class="input-text">
					</div>
					<div class="form-row form-row-1">
						<label for="last_name">Last Name</label>
						<input type="text" name="last_name" id="last_name" class="input-text">
					</div>
				</div>
				<div class="form-row">
					<label for="your_email">Your Email</label>
					<input type="text" name="email" id="your_email" class="input-text" required pattern="[^@]+@[^@]+.[a-zA-Z]{2,6}">
				</div>
				<div class="form-group">
					<div class="form-row form-row-1 ">
						<label for="password">Password</label>
						<input type="password" name="password" id="password" class="input-text" required>
					</div>
					<div class="form-row form-row-1">
						<label for="comfirm-password">Comfirm Password</label>
						<input type="password" name="comfirm_password" id="comfirm_password" class="input-text" required>
					</div>
				</div>
				
				
				<div class="form-radiobox">
				<label for="gender">Gender</label>
				  <ul>
				  <li>
				    <input type="radio" id="f-option" name="gender" value="men">
				    <label for="f-option" >Men</label>
				    
				    <div class="check"></div>
				  </li>
				  
				  <li>
				    <input type="radio" id="s-option" name="gender" value="women">
				    <label for="s-option" >Women</label> 
				    <div class="check"><div class="inside"></div></div>
				  </li>
				  
				</ul>
				</div>
				
				<div class="form-selection"> 
				    <div class="select-wrapper">
				    <label>Select Your Preference</label>
				      <select class="select" name="prefer">
				    
				        <option value="discounts">Discounts</option>
				        <option value="new">New Arrivals</option>
				       
				      </select>
				    </div>
				</div>
				
				<div class="form-checkbox">
					<label class="container">
						<p>I agree to the<a href="#" class="text">Terms and Conditions</a></p>
					  	<input type="checkbox" name="checkbox">
					  	<span class="checkmark"></span>
					</label>
				</div>
				<div class="form-row-last">
					<input type="submit" name="register" class="register" value="Register"></input>
				</div>
				</div>
			</form>
			
			<form class="form-detail" action="Login" method="post">
			
				<div class="tabcontent" id="sign-in">
				<h2>SIGN IN!</h2>
				     <div class="form-row2">
					<label for="your_email">Your Email</label>
					<input type="text" name="email" id="your_email" class="input-text" required pattern="[^@]+@[^@]+.[a-zA-Z]{2,6}">
				</div>
				
					<div class="form-row2">
					<label for="your_pass">Your Password</label>
					<input type="password" name="pass" id="your_pass" class="input-text" required>
				</div>
				<div class="form-row-last">
					<input type="submit" name="register" class="register" value="Submit">
				</div>
				
				<div class="error-msg">
				<% 
					String login_msg=(String)request.getAttribute("errorMessage");  
					if(login_msg!=null)
					out.println("<font color=red size=4px>"+login_msg+"</font>");
				%> 
				
				
			</div>
				</div>
			</form>
			
			<!-- Sign in -->
			
		</div>
		
	</div>
	<script src="https://code.jquery.com/jquery-1.11.1.min.js"></script>
	

	<script type="text/javascript">
		function openCity(evt, cityName) {
		    var i, tabcontent, tablinks;
		    tabcontent = document.getElementsByClassName("tabcontent");
		    for (i = 0; i < tabcontent.length; i++) {
		        tabcontent[i].style.display = "none";
		    }
		    tablinks = document.getElementsByClassName("tablinks");
		    for (i = 0; i < tablinks.length; i++) {
		        tablinks[i].className = tablinks[i].className.replace(" active", "");
		    }
		    document.getElementById(cityName).style.display = "block";
		    evt.currentTarget.className += " active";
		}

		// Get the element with id="defaultOpen" and click on it
		document.getElementById("defaultOpen").click();
	</script>
</body>
</html>