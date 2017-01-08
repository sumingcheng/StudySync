<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>  
   <META http-equiv=Content-Type content="text/html; charset=gb2312">
   <LINK href="css/admin.css" type="text/css" rel="stylesheet">
  </head>
  <%
  	//UserInfo userbean=new UserInfo();
  	//userbean=(UserInfo)session.getAttribute("user");
   %>
  <body>
    <TABLE cellSpacing=0 cellPadding=0 width="100%" background="images/header_bg.jpg" border=0>
  		<TR height=56>
    		<TD width=260>
    			
    		</TD>
    	<TD style="FONT-WEIGHT: bold; COLOR: #fff; PADDING-TOP: 20px" 
      	align=middle>当前用户：&nbsp;&nbsp; <A style="COLOR: #fff" 
     	 href="" 
     	 target=main>修改口令</A> &nbsp;&nbsp; <A style="COLOR: #fff" 
      	 onclick="if (confirm('确定要退出吗？')) return true; else return false;" 
     	 href="" target=_top>退出系统</A> 
    </TD>
    <TD align=right width=268><IMG height=56 
      src="images/header_right.jpg" width=268></TD></TR></TABLE>
	<TABLE cellSpacing=0 cellPadding=0 width="100%" border=0>
  		<TR bgColor=#1c5db6 height=4><TD></TD></TR></TABLE>
  </body>
</html>
