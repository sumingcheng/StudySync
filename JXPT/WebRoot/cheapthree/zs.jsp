<%@ page contentType="text/html; charset=GB2312" language="java" errorPage=""%>
<html>
<head>
<title>��ʾ��ǰʱ��</title>
</head>
<%!	String getDate(){	//���ص�ǰʱ��
	  String str;
	  str=new java.util.Date().toString();
	  return str;
	}
%>
<body bgcolor="#ffffff">

<!--JSP ���ʽע��<%=(new java.util.Date()).toLocaleString()%>-->

<div align="center">

  <!-- ��̬HTMLע�� -->

  <font color="#000000" size="5">��ǰʱ���ǣ�<%=getDate()%></font> 
</div>

<%--JSPע������ע�Ͳ���ʾ��Դ�ļ���--%>

</body>
</html>
