<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
�ͻ��ύ��Ϣ�ķ�ʽ��<%=request.getMethod()%>
<br>ʹ�õ�Э�飺<%=request.getProtocol()%>
<br>��ȡ���������ַ����Ŀͻ��˵�ַ��<%=request.getRequestURI()%>
<br>��ȡ�ύ���ݵĿͻ���IP��ַ��<%=request.getRemoteAddr()%>
<br>��ȡ�������˿ںţ�<%=request.getServerPort()%>
<br>��ȡ�����������ƣ�<%=request.getServerName()%>
<br>��ȡ�ͻ��˵Ļ������ƣ�<%=request.getRemoteHost()%>
<br>��ȡ�ͻ���������Ľű��ļ����ļ�·��:<%=request.getServletPath()%>
<br>���HttpЭ�鶨����ļ�ͷ��ϢHost��ֵ:<%=request.getHeader("host")%>
<br>���HttpЭ�鶨����ļ�ͷ��ϢUser-Agent��ֵ:<%=request.getHeader("user-agent")%>
</body>

</html>
