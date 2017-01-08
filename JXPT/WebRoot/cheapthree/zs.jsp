<%@ page contentType="text/html; charset=GB2312" language="java" errorPage=""%>
<html>
<head>
<title>显示当前时间</title>
</head>
<%!	String getDate(){	//返回当前时间
	  String str;
	  str=new java.util.Date().toString();
	  return str;
	}
%>
<body bgcolor="#ffffff">

<!--JSP 表达式注释<%=(new java.util.Date()).toLocaleString()%>-->

<div align="center">

  <!-- 静态HTML注释 -->

  <font color="#000000" size="5">当前时间是：<%=getDate()%></font> 
</div>

<%--JSP注释隐藏注释不显示在源文件中--%>

</body>
</html>
