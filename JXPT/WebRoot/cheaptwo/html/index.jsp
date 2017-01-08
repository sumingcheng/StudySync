<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <table width="75%" border="1" align="center" cellpadding="2" cellspacing="0" bgcolor="#CCCCCC">
  			<caption >HTML基础</caption>
  			
 			<tr align="center"> 
    				
    				<td width="50%"><A style="COLOR: #003399" 
     	 href="cheaptwo/html/bt.html" 
     	 target="_blank">标题</a></td>
    				<td width="50%"><A style="COLOR: #003399" 
     	 href="cheaptwo/html/fd.html" 
     	 target="_blank">分段</a></td>
    				
  			</tr>
 			
  			<tr align="center"> 
    				
    				<td><A style="COLOR: #003399" 
     	 href="cheaptwo/html/hh.html" 
     	 target="_blank">换行</a></td>
    				<td><A style="COLOR: #003399" 
     	 href="cheaptwo/html/yp.html" 
     	 target="_blank">预排1</a></td>
    				
  			</tr>
  			<tr align="center"> 
    				
    				<td><A style="COLOR: #003399" 
     	 href="cheaptwo/html/ypp.html" 
     	 target="_blank">预排2</a></td>
    				<td><A style="COLOR: #003399" 
     	 href="cheaptwo/html/zt.html" 
     	 target="_blank">字体1</a></td>
    				
  			</tr>
  			<tr > 
    				
    				<td align="center"><A style="COLOR: #003399" 
     	 href="cheaptwo/html/ztt.html" 
     	 target="_blank">字体2</a></td>
    				<td align="center"><A style="COLOR: #003399" 
     	 href="cheaptwo/html/tszf.html" 
     	 target="_blank">特殊字符</a></td>
    				
  			</tr>
</table> <br>
  </body>
</html>
