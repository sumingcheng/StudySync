<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
<%
request.setCharacterEncoding("gb2312");
String strUserName = request.getParameter("username");
String strPwd = request.getParameter("password");
out.println("�û���Ϊ��"+strUserName);
out.println("�û�����Ϊ��"+strPwd);
if(strUserName.equals("gufeng")&&strPwd.equals("123456")){
	response.sendRedirect("frame.jsp");
}else{
	response.sendRedirect("index.jsp");
}
%>
</body>
</html>
