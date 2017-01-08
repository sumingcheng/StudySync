<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<jsp:useBean id="calculator" scope="request" class="chfive.Caulcate">
<jsp:setProperty name="calculator" property="*"/>
</jsp:useBean>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>无标题文档</title>
</head>

<body>
<p align="center">简单计算器<br>
<hr>计算结果:<%
try{
 calculator.culcate();
 
 out.println(calculator.getFirst()+calculator.getOperator()+calculator.getSecond()+"="+calculator.getResult());
}catch(Exception e){

}

 %>
<form name ="form1" action="caulate.jsp" method="get">
<table>
<tr><td>第一个数</td><td><input name="first" type="text"></td>
</tr>
<tr><td>操作符</td><td><select name="operator" >
<option value="+">+</option>
<option value="-">-</option>
<option value="*">*</option>
<option value="/">/</option>
</select>
</td>
</tr>
<tr><td>第二个数</td><td><input name="second" type="text"></td>
</tr>
</table>
<input name="submit"type="submit" value="计算"/><input name="reset"type="submit1" value="重置"/>
</form>
</body>
</html>
