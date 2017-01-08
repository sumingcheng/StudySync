// JavaScript Document 
function chkUsername(){ 
var reUsername = /^([a-zA-Z](\d|[a-zA-Z])*)$/; 
if(document.form1.username.value.search(reUsername)==-1){ 
alert("用户名的格式不正确，请重新输入！"); 
document.form1.username.value = ""; 
return false; 
} 
return true; 
} 
function chkPwd(){ 
if(document.form1.pwd.value.length<8){ 
alert("密码无效，请重新输入!"); 
form1.pwd.value=""; 
return false; 
} 
return true; 
} 
function chkSame(){ 
if(document.form1.pwd.value!=document.form1.rePwd.value){ 
alert("两次输入密码不一致，请重新输入!"); 
form1.pwd.value=""; 
form1.rePwd.value=""; 
return false; 
} 
return true; 
} 
function chkBirthday(){ 
var reBirthday = /^\d{4}-\d{2}-\d{2}$/; 
if(document.form1.birthday.value.search(reBirthday)==-1){ 
alert("日期不正确，请重新输入!"); 
form1.birthday.value=""; 
return false; 
} 
return true; 
} 
function chkPostcode(){
var rePost = /^\d{6}$/; 
if(document.form1.postcode.value.search(rePost)==-1){ 
alert("邮编无效，请重新输入!"); 
form1.postcode.value=""; 
return false; 
} 
return true; 
} 
function chkEmail(){ 
var	reEmail	= /^\w+((-\w+)|(\.\w+))*\@[A-Za-z0-9]+((\.|-)[A-Za-z0-9]+)*\.[A-Za-z0-9]+$/; 
if(document.form1.email.value.search(reEmail)==-1){ 
alert("您输入的邮箱地址有误！"); 
form1.email.value=""; 
return false; 
} 
return true; 
} 
function chkIdenty(){ 
var reIdenty =/^(\d{15}|\d{18}|\d{17}[Xx])$/; 
if(document.form1.identy.value.search(reIdenty)==-1){ 
alert("您输入的身份证号码无效！"); 
document.form1.identy.value=""; 
return false; 
} 
var identyValue = document.form1.identy.value; 
var year = identyValue.substr(6,4); 
var mm = identyValue.substr(10,2); 
var dd = identyValue.substr(12,2); 
var birthdate = year+"-"+mm+"-"+dd; 
if(document.form1.birthday.value.search(birthdate)==-1){
 alert("请输入合法的身份证号码！"); 
document.form1.identy.value=""; 
document.form1.birthday.value=""; 
return false 
} 
return true; 
}
