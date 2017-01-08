<%@ page language="java" contentType="text/html; charset=gb2312"%> 
<jsp:useBean id="splBean" class="chfive.SampleBean3" scope="application"/>
<html>
	<head>
		<title>application范围的JavaBean</title>
	</head>	
	<body>
<center><p><font size="5">访问人次：<strong><%=splBean.getNum()%></strong></font></p></center>
<p>请你分别做如下操作，看访问人次的变化情况：</p>
<p>1、按F5键或者单击【查看】-【刷新】命令来刷新页面。</p>
<p>2、单击【文件】-【新建】-【窗口】命令打开一个相同的新窗口。</p>
<p>3、再打开一个浏览器并访问此JSP网页。</p>
<p>4、在网络中的另一台计算机上访问此JSP网页。</p>
</body>
</html>