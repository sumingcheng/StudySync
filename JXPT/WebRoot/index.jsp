<%@ page language="java" import="java.util.*" contentType="text/html;charset=gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<jsp:useBean id="yzm" scope="page" class="chfive.CheckCode"/>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML><HEAD><TITLE>教学平台</TITLE>
<META http-equiv=Content-Type content="text/html; charset=gb2312">
<META content="MSHTML 6.00.2900.3268" name=GENERATOR>
<STYLE type=text/css>TD {
	FONT-SIZE: 12px; VERTICAL-ALIGN: top; COLOR: #333333
}
</STYLE>
</HEAD>
<%

 	String code=yzm.getCheckCode();
%>

<BODY background=leftMargin=0 topMargin=0 marginwidth="0" marginheight="0">
<TABLE cellSpacing=0 cellPadding=0 width="100%" border=0>
  <TBODY>
  <TR>
    <TD height=600 align="center" bgcolor="#184D73"><BR>
      <BR><BR><BR>
	<h2><font color="#FF0000">实验教学管理系统</font></h2>
	<br>
      <TABLE class=tableborder cellSpacing=0 cellPadding=0 width=427 
      align=center border=0>
        <TBODY>
        <TR>
          <TD background=images/index_hz01.gif colSpan=3 
            height=64>&nbsp; </TD></TR>
        <TR>
          <TD style="FONT-SIZE: 1px; LINE-HEIGHT: 1px" width=3 
          background=images/index_hz02.gif></TD>
          <TD style="BORDER-TOP: #666666 1px double" vAlign=top 
          background=images/index_hz03.gif height=162><BR><BR><!--
-->
            <TABLE id=adminlogin cellSpacing=0 cellPadding=0 width="100%" 
            align=center border=0>
        <form action="loginCheck.jsp" name="form1" method="post" onSubmit="return checkform(form1)" autocomplete="off">
              <TBODY>
              <TR>
                <TD class=td align=right width="33%">帐&nbsp;&nbsp;&nbsp;&nbsp;号:</TD>
                <TD class=td width="67%"><INPUT 
                  style="BORDER-RIGHT: #0d5c95 1px solid; BORDER-TOP: #0d5c95 1px solid; BACKGROUND: #fff; BORDER-LEFT: #0d5c95 1px solid; WIDTH: 140px; BORDER-BOTTOM: #0d5c95 1px solid; HEIGHT: 21px" 
                  name=username> </TD></TR>
              <TR>
                <TD class=td align=right width="33%">密&nbsp;&nbsp;&nbsp;&nbsp;码:</TD>
                <TD class=td width="67%"><INPUT 
                  style="BORDER-RIGHT: #0d5c95 1px solid; BORDER-TOP: #0d5c95 1px solid; BACKGROUND: #fff; BORDER-LEFT: #0d5c95 1px solid; WIDTH: 140px; BORDER-BOTTOM: #0d5c95 1px solid; HEIGHT: 21px" 
                  type=password size=21 name=password> </TD></TR><!---->
              <!-- <TR>
                <TD class=td align=right width="33%">类&nbsp;&nbsp;&nbsp;&nbsp;型:</TD>
                <TD class=td width="67%"><INPUT type=radio name=method value="one" checked > 管理员 
                <INPUT type=radio name=method value="two"  > 学生</TD></TR>-->
              <TR> 
                <TD class=td vAlign=center align=right width="33%">验&nbsp;证&nbsp;码:</TD>
                <TD width="67%" ><INPUT 
                  style="BORDER-RIGHT: #0d5c95 1px solid; BORDER-TOP: #0d5c95 1px solid; BACKGROUND: #fff; BORDER-LEFT: #0d5c95 1px solid; WIDTH: 70px; BORDER-BOTTOM: #0d5c95 1px solid; HEIGHT: 21px" 
                  size=8 name=yzm><%=code %> </TD></TR>
              <TR>
                <TD class=td width="33%">&nbsp;</TD>
                <TD class=td width="67%"><INPUT type=image height=33 width=83 
                  src="images/index_hz04.gif" name=Submit> 
              </TD></TR></TBODY>
              </form> </TABLE></TD>
          <TD style="FONT-SIZE: 1px; LINE-HEIGHT: 1px" width=3 
          background=images/index_hz02.gif></TD></TR>
        <TR>
          <TD background=images/index_hz05.gif colSpan=3 
            height=127>&nbsp; 
</TD></TR></TBODY>
</TABLE></TD></TR></TBODY></TABLE></BODY></HTML>
<script language=Javascript>
	
	form1.username.focus()	

	function checkform(form)
	{
		var flag=true;
		if(form("username").value==""){alert("请输入用户名!");form("username").focus();return false};
		if(form("password").value==""){alert("请输入密码!");form("password").focus();return false};
		if(form("yzm").value==""){alert("请输入验证码!");form("yzm").focus();return false};
		if(isNaN(form("yzm").value)){alert("请正确输入验证码!");form("yzm").focus();return false};
		if(form("yzm").value!=<%=code%>){alert("验证码错误!");form("yzm").focus();return false};
		return flag;
	}
</script>