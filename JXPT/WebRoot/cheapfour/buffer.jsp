<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
<%
out.print("��������С��"+response.getBufferSize()+"<br>");
out.print("����������ǿ���ύǰ<br>");
out.print("��������Ƿ��ύ��"+response.isCommitted()+"<br>");
response.flushBuffer();
out.print("����������ǿ���ύ��<br>");
out.print("��������Ƿ��ύ��"+response.isCommitted()+"<br>");
%>

</body>
</html>
