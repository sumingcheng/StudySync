<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<jsp:useBean id="splBean" class="chfive.SampleBean1"/>
<html>
	<head>
		<title>һ���򵥵�JavaBean����</title>
	</head>	
	<body>
		<center>
			<%
				splBean.setStr("�����ҵĵ�һ��JavaBean����");
			%>
			<%=splBean.getStr()%>
		</center>
	</body>
</html>
