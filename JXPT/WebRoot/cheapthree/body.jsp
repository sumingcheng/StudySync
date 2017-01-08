<%@ page contentType="text/html; charset=GB2312" language="java" errorPage=""%>
<html>
<%!	String getDate(){	//返回当前时间
	  String str;
	  str=new java.util.Date().toString();
	  return str;
	}
%>
<body bgcolor="#ffffff">
<div align="center">
  <!-- 使用表达式 -->
  <font color="#000000" size="5">当前时间是：<%=getDate()%></font> 
</div>
</body>
</html>