<%@ page contentType="text/html; charset=gb2312" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ޱ����ĵ�</title>
<script language="javascript">
	function checkOut(){
		if(form1.username.value==''){
			alert("�û�������Ϊ�գ�");
			form1.username.focus();
			return false;
		}
		if(form1.password.value==''){
			alert("�û����벻��Ϊ�գ�");
			form1.password.focus();
			return false;
		}
		if(form1.age.value==''){
			alert("�û����䲻��Ϊ�գ�");
			form1.age.focus();
			return false;
		}else if(isNaN(form1.age.value)){
			alert("�û�����ֻ��Ϊ���֣�");
			form1.age.focus();
			return false;
		}
		if(form1.tel.value==''){
			alert("ͼ��۸���Ϊ�գ�");
			form1.tel.focus();
			return false;
		}
		if(confirm("ȷ����Ӵ��û���Ϣ��")){
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
  <td colspan="2" align="center" bgcolor="#0066FF"><strong>�û���Ϣ���</strong></td>
  </tr>
<tr>
	<td width="30%" align="right">�û�����</td>
	<td width="70%" align="left"><input type="text" name="username" onblur="sendRequest()" />
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">���룺</td>
	<td width="70%" align="left"><input type="text" name="paassword"/>
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">���䣺</td>
	<td width="70%" align="left">
		<input type="text" name="age"/>
		*	</td>
</tr>
<tr>
	<td width="30%" align="right">�Ա�</td>
	<td width="70%" align="left">
		<input type="text" name="sex"/>
		*	</td>
</tr>
<tr>
	<td width="30%" align="right">��ϵ�绰��</td>
	<td width="70%" align="left"><input type="text" name="tel"/>
	  * </td>
</tr>
<tr>
	<td width="30%" align="right">ͨ�ŵ�ַ��</td>
	<td width="70%" align="left"><input type="text" name="address"/>
	  * </td>
</tr>
<tr>
	<td colspan="2" align="center">
	<input type="submit" name="submit1" value="���"/>&nbsp;
	<input type="reset" name="reset1" value="����"/>	</td>
</tr>
<tr >
	<td align="right" colspan="2"><a href="/jxpt/userservlet">����</a></td>
</tr>
</table>
</form>
</body>
</html>
