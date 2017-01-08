<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<%@ page import="java.util.*"%>
<%@ page import="cheight.UserForm"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>无标题文档</title>
</head>

<body>
<table width="896" height="135" border="1" align="center" cellpadding="0" cellspacing="0">
<tr >
  <td height="29" colspan="5" align="center" bgcolor="#0066FF"><strong>用户信息列表</strong></td>
</tr>
<tr >
	<td height="33" colspan="5" align="right">
	
	<a href="cheapeight/useradd.jsp">添加</a>
	</td>
</tr>
<tr>
	<td width="20%" align="center" bgcolor="#FFFFCC">用户名</td>
	<td width="9%" align="center" bgcolor="#FFFFCC">年龄</td>
	<td width="19%" align="center" bgcolor="#FFFFCC">联系电话</td>
	<td width="34%" align="center" bgcolor="#FFFFCC">联系地址</td>
	<td width="18%" align="center" bgcolor="#FFFFCC">操作</td>
</tr>
<%
	Collection alistUser = (Collection)request.getAttribute("UserList");
	Iterator it = null;
	UserForm userForm = null;
	it = alistUser.iterator();
	
	while(it.hasNext()){
		userForm = (UserForm) it.next();
%>
<tr>
	<td align="center"><%=userForm.getUsername() %></td>
	<td align="center"><%=userForm.getAge() %></td>
	<td align="center"><%=userForm.getTel() %></td>
	<td align="center"><%=userForm.getAddress() %></td>
	<td align="center">修改&nbsp;删除</td>
</tr>
<%
	}
%>
</table>
</body>
</html>
