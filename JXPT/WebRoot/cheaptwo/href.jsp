<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
   

  </head>
  
  <body>
    <A  href=""  target=_blank title="_blank">超链接一</A>  <br>
    <A  href=""  target=_top title= "_top">超链接二</A> <br>
    <A  href=""  target=_self title="_self">超链接三</A> <br>
    <A  href=""  target=_parent title="_parent">超链接四</A> <br>
  </body>
</html>
