<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<jsp:useBean id="user" class="chfive.SampleBean2"/>
<html>
	<head>
		<title>��JavaBean�д������</title>
	</head>	
	<body>
		<jsp:setProperty name="user" property="*"/>

		<center>
			�û�����<jsp:getProperty name="user" property="userName" /><br>
			��  �룺<jsp:getProperty name="user" property="userPass" /><br>
		</center>
	</body>
</html>