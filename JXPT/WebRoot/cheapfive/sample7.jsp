<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<jsp:useBean id="splBean" class="chfive.SampleBean3" scope="application"/>
<html>
	<head>
		<title>application��Χ��JavaBean</title>
	</head>	
	<body>
<center><p><font size="5">�����˴Σ�<strong><%=splBean.getNum()%></strong></font></p></center>
<p>����ֱ������²������������˴εı仯�����</p>
<p>1����F5�����ߵ������鿴��-��ˢ�¡�������ˢ��ҳ�档</p>
<p>2���������ļ���-���½���-�����ڡ������һ����ͬ���´��ڡ�</p>
<p>3���ٴ�һ������������ʴ�JSP��ҳ��</p>
<p>4���������е���һ̨������Ϸ��ʴ�JSP��ҳ��</p>
</body>
</html>