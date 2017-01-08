<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<jsp:useBean id="splBean" class="chfive.SampleBean1"/>
<html>
	<head>
		<title>一个简单的JavaBean程序</title>
	</head>	
	<body>
		<center>
			<%
				splBean.setStr("这是我的第一个JavaBean程序！");
			%>
			<%=splBean.getStr()%>
		</center>
	</body>
</html>
