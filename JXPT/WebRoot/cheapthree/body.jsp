<%@ page contentType="text/html; charset=GB2312" language="java" errorPage=""%>
<html>
<%!	String getDate(){	//���ص�ǰʱ��
	  String str;
	  str=new java.util.Date().toString();
	  return str;
	}
%>
<body bgcolor="#ffffff">
<div align="center">
  <!-- ʹ�ñ��ʽ -->
  <font color="#000000" size="5">��ǰʱ���ǣ�<%=getDate()%></font> 
</div>
</body>
</html>