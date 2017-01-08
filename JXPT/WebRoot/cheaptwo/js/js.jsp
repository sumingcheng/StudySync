<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
   <script language="javascript" type="text/javascript">
   document.write("JS脚本学习！");
   </script>
	

  </head>
  
  <body>
  <script language="javascript" type="text/javascript">
   alert("弹出提示框！");
   prompt("请输入数字","0");
   confirm("是否真的删除？");
   </script>
    
  </body>
</html>
