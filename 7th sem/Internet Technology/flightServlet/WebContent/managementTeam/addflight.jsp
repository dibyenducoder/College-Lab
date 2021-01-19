<%-- 
    Document   : addflight
    Created on : 16 Nov, 2020, 9:22:00 PM
    Author     : Dibyendu
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	
	<!-- My CSS -->
<!--	<link rel="stylesheet" href="css/home.css">-->
	
	<!-- My JS -->
	<script src="js/home.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js"></script>
	
	
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"> -->
	<!-- google CSS -->
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
       
	<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
        
        <!-- Bootstrap -->
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <script src="myjs.js"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
                
	<title>Add Flights Data</title>
    
  </head>
  
   
  
  
  <style>
      #addflight{
	position:absolute ;
	width: 350px;
	height:500px;
	padding:20px;
	top:50%; 
	left:50%;
	transform: translate(-50%, -50%);
}

      .form{
	padding : 20px;
}
  </style>
  <header>
  		<!-- Header -->
  	<jsp:include page="../template/adminHeader.jsp" />   
  </header>
  <body>
     

     <style>
         body{
             overflow-x: hidden;
         }
        .addflight{
            position:absolute ;
            width: 70%;
            height:500px;
            padding:20px;
            top:50%; 
            left:50%;
            transform: translate(-50%, -50%);
         }
        
     </style>
<section class="addflight">
		
<div class="card z-depth-3">
    <div class="card-panel center grey darken-3">
        <span class="card-title white-text">Add Flight Information</span>
    </div>
    <div class="row">
        <form class="col s12" action="AdminFlightAdd" method="get" enctype="multipart/form-data">
              	 <div class="input-field">
                    <i class="material-icons prefix">explore</i>
                   <input type="text" class="validate" name="company" required>
                  <label>Flight Company</label>
                </div>
			    
                <div class="input-field">
                    <i class="material-icons prefix">flight</i>
                   <input type="text" name="fno" required>
                  <label>Flight No.</label>
                </div>
            
                <div class="input-field col s6">
                  <i class="material-icons prefix">flight_takeoff</i>
                  <input type="text" class="validate" name="src" required>
                  <label>From</label>
                </div>
            
                <div class="input-field col s6">
                  <i class="material-icons prefix">flight_land</i>
                  <input type="text" class="validate" name="dest" required>
                  <label>To</label>
                </div>
            
                <div class="input-field col s6">
                  <i class="material-icons prefix">date_range</i>
                  <label for="Departure">Departure Date</label>									
                  <input type="date" name="dept_date" min="2017-01-01" id="Departure" required>
                </div>
            
                <div class="input-field col s6">
                  <i class="material-icons prefix">alarm</i>
                  <label>Departure Time</label>
                  <input type="time"  name="dept_time" id="" required>
                </div>
            
                <div class="input-field col s6">
                  <i class="material-icons prefix">airline_seat_recline_extra</i>
                  <label>Sitting Capacity</label>
                  <input type="text" name="capacity" required>
                </div>
            
            
              <!-- Note:- seat_left is actually legs -->
                <div class="input-field col s6">
                  <i class="material-icons prefix">people</i>
                  <label>Legs</label>
                  <input type="text" name="seat_left" id="" required>
                </div>
            
            
                <style>
                    .fa-rupee, .fa-percent{
                        position: relative;
                        top:30px;
                        right:26px;
                    }
                </style>
               <div class="input-field col s6">
                  <i class="fa fa-rupee fa-2x"></i>
                  <label>Price</label>
                  <input type="text" name="price" id="price" required>
                </div>
                
                 <div class="input-field col s3">
                  <i class="material-icons prefix">local_offer</i>
                  <label>Special Offer</label>
                  <input type="text" name="special_offer" id="" >
                </div>
                <div class="input-field col s3">
                  <i class="material-icons prefix">access_time</i>
                  <input type="date"  name="special_limit" id="Departure" value="none">
                </div>
                
               
                <button type="submit" class="btn btn-floating waves-effect waves-light color">
                	<i class="material-icons">add</i>
                </button>
                
                
                
        </form>
        <style>
            .color{
                background-color: grey;
                position: absolute;
                bottom: 20px;
                left: 945px;
            }
            .color:hover{
                background-color: red;
            }
            .hidden{
            	opacity:1;
            }
        </style>
        
       
    </div>
             
</div>  </section>
     
    <!-- JS Library -->
    
    
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" ></script>
    <!--<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" ></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script> -->
  	<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  	<script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
  </body>
</html>
