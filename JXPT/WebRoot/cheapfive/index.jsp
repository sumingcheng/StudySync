<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<%String pwd="123";%>
<jsp:useBean id="user" class="chfive.SampleBean2"/>
<html>
	<head>
		<title>在JavaBean中存放数据</title>
	</head>	
	<body>
		<jsp:setProperty name="user" property="userName" value="leifeng"/>
		<jsp:setProperty name="user" property="userPass" value="<%=pwd%>"/>

		<center>
			用户名：<jsp:getProperty name="user" property="userName" /><br>
			密  码：<jsp:getProperty name="user" property="userPass" /><br>
		</center>
	</body>
</html>