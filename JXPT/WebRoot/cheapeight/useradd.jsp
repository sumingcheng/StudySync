<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>无标题文档</title>
<script language="javascript">
	function checkOut(){
		if(form1.username.value==''){
			alert("用户名不能为空！");
			form1.username.focus();
			return false;
		}
		if(form1.password.value==''){
			alert("用户密码不能为空！");
			form1.password.focus();
			return false;
		}
		if(form1.age.value==''){
			alert("用户年龄不能为空！");
			form1.age.focus();
			return false;
		}else if(isNaN(form1.age.value)){
			alert("用户年龄只能为数字！");
			form1.age.focus();
			return false;
		}
		if(form1.tel.value==''){
			alert("图书价格不能为空！");
			form1.tel.focus();
			return false;
		}
		if(confirm("确定添加此用户信息？")){
			form1.submit;
		}else{
			return false;
		}
	}

		

</script>
</head>

<body>
<form action="/jxpt/useroperservlet?sign=1" method="post" name="form1" onsubmit="return checkOut()">
<table width="496" height="241" border="1" align="center" cellpadding="0" cellspacing="0">
<tr>
  <td colspan="2" align="center" bgcolor="#0066FF"><strong>用户信息添加</strong></td>
  </tr>
<tr>
	<td width="30%" align="right">用户名：</td>
	<td width="70%" align="left"><input type="text" name="username" onblur="sendRequest()" />
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">密码：</td>
	<td width="70%" align="left"><input type="text" name="paassword"/>
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">年龄：</td>
	<td width="70%" align="left">
		<input type="text" name="age"/>
		*	</td>
</tr>
<tr>
	<td width="30%" align="right">性别：</td>
	<td width="70%" align="left">
		<input type="text" name="sex"/>
		*	</td>
</tr>
<tr>
	<td width="30%" align="right">联系电话：</td>
	<td width="70%" align="left"><input type="text" name="tel"/>
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">通信地址：</td>
	<td width="70%" align="left"><input type="text" name="address"/>
	  * </td>
</tr>
<tr>
	<td colspan="2" align="center">
	<input type="submit" name="submit1" value="添加"/>&nbsp;
	<input type="reset" name="reset1" value="重置"/>	</td>
</tr>
<tr >
	<td align="right" colspan="2"><a href="/jxpt/userservlet">返回</a></td>
</tr>
</table>
</form>
</body>
</html>
