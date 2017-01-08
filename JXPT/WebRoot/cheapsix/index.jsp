<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>无标题文档</title>
</head>

<body>
<form action="../chatservlet" method="post">
<h2>用户留言</h2>
标题：<input name="title" type="text" size="26" /><br>
内容：<textarea name="content" cols="25" rows="5"></textarea><br><br>
<input name="" type="submit" value="留言" />
<input name="" type="reset" value="重置" />
</form>
</body>
</html>
