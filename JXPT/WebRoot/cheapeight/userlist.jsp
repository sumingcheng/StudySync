<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<%@ page import="java.util.*"%>
<%@ page import="cheight.UserForm"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
</head>

<body>
<table width="896" height="135" border="1" align="center" cellpadding="0" cellspacing="0">
<tr >
  <td height="29" colspan="5" align="center" bgcolor="#0066FF"><strong>�û���Ϣ�б�</strong></td>
</tr>
<tr >
	<td height="33" colspan="5" align="right">
	
	<a href="cheapeight/useradd.jsp">���</a>
	</td>
</tr>
<tr>
	<td width="20%" align="center" bgcolor="#FFFFCC">�û���</td>
	<td width="9%" align="center" bgcolor="#FFFFCC">����</td>
	<td width="19%" align="center" bgcolor="#FFFFCC">��ϵ�绰</td>
	<td width="34%" align="center" bgcolor="#FFFFCC">��ϵ��ַ</td>
	<td width="18%" align="center" bgcolor="#FFFFCC">����</td>
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
	<td align="center">�޸�&nbsp;ɾ��</td>
</tr>
<%
	}
%>
</table>
</body>
</html>
