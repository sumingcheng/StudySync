<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
if(request.getParameter("submit1")!=null){
	response.setContentType("application/msword;charset=gb2312");
}
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
ƽƽ���������棡
������ֲ��Ǹ���
<form action="" method="post" name="form1">
<input name="submit1" type="submit" id="submit1" value="����Ϊword">
</form>
</body>
</html>
