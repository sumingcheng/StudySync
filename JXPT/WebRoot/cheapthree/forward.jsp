<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
<%
  System.out.println("Hello");
%>
<jsp:forward page="confirm.jsp" >
  <jsp:param name="username" value="fhfhfh" />
  <jsp:param name="password" value="453214" />
</jsp:forward>
<%
  System.out.println("World!");
%>
</body>
</html>
