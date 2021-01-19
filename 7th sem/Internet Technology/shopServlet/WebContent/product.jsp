<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@page import="java.sql.*"%>
<%@page import="shop.user.login.UserDao"%>
<%@page import="shop.user.login.UserRegister"%>
<%@ page import="java.sql.DriverManager"%>
<%@ page import="java.sql.ResultSet"%>
<%@ page import="java.sql.Statement"%>
<%@ page import="java.sql.Connection"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Apparel Store</title>
<link rel="stylesheet" href="css/home.css">
<link rel="shortcut icon" href="images/store-logo.png">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>

  <style>
    
.product-sort form .apply-btn {
  display: inline-block;
  padding: 1rem 5rem;
  border-radius: 4rem;
  margin-right: 1rem;
  background-color: #0b9d8a;
  color: white;
  transition: all 300ms ease-in-out;
}

.product-sort form .apply-btn:hover {
  background-color: #f76b6a;
  text-decoration:none;
}
    
    </style>
    
<body>

	<% response.setHeader("Cache-Control", "no-cache no-store must-revalidate");
	   response.setHeader("Pragma", "no-cache");
	   response.setHeader("Expires", "0");
	   
	   if((UserRegister)session.getAttribute("user")==null)
		{
		   response.sendRedirect("login_register.jsp");
			
		}
	   
	  
		   
	   %>
	   
	   <% String dburl = "jdbc:mysql://localhost:3306/app_store";
	String dbusername = "root";
	String dbpassword = "Tomcat@123";
	String dbdriver = "com.mysql.jdbc.Driver" ;
	Connection conn = null;
	
	Class.forName(dbdriver);
	conn = DriverManager.getConnection(dburl, dbusername, dbpassword);
	%>
	
	
<!-- Navigation Menu -->
	<nav class="navbar navbar-light"> 
      
    <div class="navigation">
        <!--logo------------>
        <!-- <a href="#" class="logo"><img src="images/store-logo.png"></a> -->
        <a class="logo" href="https://pngimage.net/garments-logo-png-8/"><img src="https://pngimage.net/wp-content/uploads/2018/06/garments-logo-png-8.png" alt="garments logo png 8"></a>
        <p class="logo-text">Apparel Store</p>
        <!--menu-icon------------->
        
        <!--menu----------------->
        <ul class="menu">
             
            <li><a href="home.jsp">Home</a></li>
           
            <li><a href="product.jsp">Product</a>
                <!--lable---->
                <span class="sale-lable">Sale</span>
            </li>
            
        </ul>
        <!--right-menu----------->
        <div class="right-menu">
            <a href="javascript:void(0);" class="search">
                <i class="fa fa-search"></i>
            </a>
            <a href="#">
                <i class="fa fa-shopping-basket">
                    <span class="num-cart-product">0</span>
                </i>
            </a>
            
            <a href="Logout" class="user">
                <i class="fa fa-user"></i>
            </a>
            
        </div>
        </div>
    </nav>
    
    <!--search-bar----------------------------------->
    <div class="search-bar">
    
        <!--search-input------->
        <div class="search-input">
        <input type="text" placeholder="Search For Product" name="search" autocomplete="off"/>
        <!--cancel-btn--->
        <a href="javascript:void(0);" class="search-cancel">
            <i class="fa fa-times"></i>
        </a>
    
    </div>
    </div>
  
    <!--NEW ARRIVAL-------------------------------->
          <section class="new-arrival">
         
         <div class="product-sort"> 
         <form method="post">
          <div class="item">
            <label for="gender">Sort By</label>
            <select name="gender" id="sort-by">
              <option value="men" >Men</option>
              <option value="women">Women</option>
              <option value="kids">Kids</option>
              
            </select>
          </div>
          <div class="item">
            <label for="prefer">Order By</label>
            <select name="prefer" id="sort-by">
              <option value="new" >New Arrivals</option>
              <option value="discounts">Discounts</option>
            </select>
          </div>
          <input type="submit" class="apply-btn" name="apply" value="Apply">
          <!-- <a href="">Apply</a>  -->
        </form>
        
        <%
  ResultSet rs = null;
  Statement stat = null;
  stat = conn.createStatement();
  
 
  String gender = request.getParameter("gender");
  String prefer = request.getParameter("prefer");
  
  
  if(gender==null) {
	  gender = "men";
	  prefer = "new";
  }
  
 // System.out.print("\nproduct gender"+gender+"\n\t\t product prefer"+prefer);
  
  %>
  
  
        </div>
            <!--heading-------->
            <div class="arrival-heading">
            
             <%
            if(prefer.equals("new"))
             { %>
                <strong>New Arrival</strong>
                <p>We Provide You New Fashion Design Clothes</p>
              <%
            }
            else if(prefer.equals("discounts"))
              {
            	  %>
              <strong>Discounts</strong>
                <p>We Provide You Discount Clothes</p>
           
            <%
              }
            

           
        	String sql =  "select * from app_store.clothesData where gender='"+ gender +"' and prefer='"+ prefer +"'";
        	//rs = (ResultSet)udao.getClothes(((UserRegister)(session.getAttribute("user"))).getGender(), ((UserRegister)(session.getAttribute("user"))).getPrefer());	  
        	rs = stat.executeQuery(sql);
        	if(rs.next()) 
        		do{
            
            %>
            
          
            </div>
              <!--products----------------------->
              <div class="product-container">
                  
                <!--product-box-1---------->
                  <div class="product-box">
                      <!--product-img------------>
                      <div class="product-img">
                          <!--add-cart---->
                          <a href="#" class="add-cart">
                              <i class="fa fa-shopping-cart"></i>
                            </a>
                          <!--img------>
                         <!--img------>
                          <% if(gender.equals("men")) 
                          { %>
                        <img src="images/men/<%=rs.getString("image")%>"> 
                        
                        <%} else if(gender.equals("women")) { %> 
                        <img src="images/women/<%=rs.getString("image")%>"> 
                        
                        <%} else{ %> 
                        	<img src="images/kids/<%=rs.getString("image")%>"> 
                        <%} %>     
                       <!-- <img src="images/p-1.png">
 -->                      </div>
                      <!--product-details-------->
                      <div class="product-details">
                          <a href="#" class="p-name"><%=rs.getString("ctype")%></a>
                          <%-- <span class="p-price"><i class="fa fa-rupee"></i><%=rs.getString("price")%></span> --%>
                          
                          <a href="#" class="p-name">Dress</a>
                           <span class="p-price"><i class="fa fa-rupee"></i><%=rs.getString("price")%></span> 
                          <!-- <span class="p-price"><i class="fa fa-rupee"></i>1200</span> -->
                      </div>
                  </div>
                  
                  
                   
              </div>
               <% 
          } while(rs.next());
			else{
				  
				%>
				  <h3 class="text-danger center">Sorry for disappointing you... ! &#128546; </h3>
				  <h3>We are not offering for your preference...</h3>
				<%} %>
</section>
          
          
</body>

<script>
  /*-----For Search Bar-----------------------------*/
  $(document).on('click','.search',function(){
      $('.search-bar').addClass('search-bar-active')
  });

  $(document).on('click','.search-cancel',function(){
      $('.search-bar').removeClass('search-bar-active')
  });
 

  </script>
  
   <script>
  $(document).ready(function(){
	   
	   var counts = 0;
	   $(".add-cart").click(function () {
	  
	      counts += +1;
	      $(".num-cart-product").animate({
	   
	                opacity: 1
	            }, 300, function () {
	  
	                $(this).text(counts);
	            });
	        }); 
	});
  
  </script>
</html>