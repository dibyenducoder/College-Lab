
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        
        <!-- Compiled and minified CSS -->
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">

        <!-- Compiled and minified JavaScript -->
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js"></script>
        
        <script>
        function validate_and_submit(){
    		var src=document.getElementById("search_src").value;
    		var dest=document.getElementById("search_dest").value;
    		
    		
    		if(src!="" && dest!="" && src===dest)
    		{
    			//Error
    			alert("Source and destination city cannot be same");
    		}
    		else
    			document.getElementById("search-travel").submit();
    	}
        
        </script>
    </head>
    <body>
        <style>
            .section{
                background-image: url("https://media.giphy.com/media/Y4W4wScqoaDGXM6vhv/giphy.gif");
                background-position: right;
                background-repeat: no-repeat;
                background-size: 570px 370px;
                
            }
            .input {
                padding: 5px !important;
                font-size: 18px !important;
                width: 90% !important;
                border: #f4f4f4 3px solid !important;
              }
              .pos{
              	position:absolute; 
              	right:80px;
              	bottom:30px;
              	
              }

        </style>
        
        <!-- Section: Search -->
        <section id="search" class="section  blue-grey darken-4 white-text center ">
<!--            <iframe src="https://giphy.com/embed/Y4W4wScqoaDGXM6vhv" width="480" height="350" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>
            -->
            <h4>Search Flights !</h4>
            <hr class="white" width="150px" align="center">
            
            <form class="search-travel" action="" method="post" >
          <div class="container">
          
            <div class="row">
          
             
               <div class="col s3">
                <h6>Journey starts</h6>
                <div class="input-field">
                  <input class="white grey-text" placeholder="Kolkata" type="text" name="search_src" id="search_src">
                </div>
              </div>
               <div class="col s3">
                <h6>Journey Ends</h6>
                <div class="input-field">
                  <input class="white grey-text" placeholder="Mumbai" type="text" name="search_dest" id="search_dest">
                </div>
              </div>
              
              <div class="col s3">
                <h6>Date</h6>
                <div class="input-field">
                  <input class="white grey-text" placeholder="Date" type="date" name="search_date">
                </div>
              </div>
              
              
            	<div>
            		<button class="btn btn-primary black pos" onclick="validate_and_submit()">Search
            		<i class="material-icons left">search</i>
            		</button>
            	</div>
            </div>
          </div></form>
        </section>
    </body>
</html>
