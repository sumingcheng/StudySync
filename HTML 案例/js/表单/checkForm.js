// JavaScript Document 
function chkUsername(){ 
var reUsername = /^([a-zA-Z](\d|[a-zA-Z])*)$/; 
if(document.form1.username.value.search(reUsername)==-1){ 
alert("�û����ĸ�ʽ����ȷ�����������룡"); 
document.form1.username.value = ""; 
return false; 
} 
return true; 
} 
function chkPwd(){ 
if(document.form1.pwd.value.length<8){ 
alert("������Ч������������!"); 
form1.pwd.value=""; 
return false; 
} 
return true; 
} 
function chkSame(){ 
if(document.form1.pwd.value!=document.form1.rePwd.value){ 
alert("�����������벻һ�£�����������!"); 
form1.pwd.value=""; 
form1.rePwd.value=""; 
return false; 
} 
return true; 
} 
function chkBirthday(){ 
var reBirthday = /^\d{4}-\d{2}-\d{2}$/; 
if(document.form1.birthday.value.search(reBirthday)==-1){ 
alert("���ڲ���ȷ������������!"); 
form1.birthday.value=""; 
return false; 
} 
return true; 
} 
function chkPostcode(){
var rePost = /^\d{6}$/; 
if(document.form1.postcode.value.search(rePost)==-1){ 
alert("�ʱ���Ч������������!"); 
form1.postcode.value=""; 
return false; 
} 
return true; 
} 
function chkEmail(){ 
var	reEmail	= /^\w+((-\w+)|(\.\w+))*\@[A-Za-z0-9]+((\.|-)[A-Za-z0-9]+)*\.[A-Za-z0-9]+$/; 
if(document.form1.email.value.search(reEmail)==-1){ 
alert("������������ַ����"); 
form1.email.value=""; 
return false; 
} 
return true; 
} 
function chkIdenty(){ 
var reIdenty =/^(\d{15}|\d{18}|\d{17}[Xx])$/; 
if(document.form1.identy.value.search(reIdenty)==-1){ 
alert("����������֤������Ч��"); 
document.form1.identy.value=""; 
return false; 
} 
var identyValue = document.form1.identy.value; 
var year = identyValue.substr(6,4); 
var mm = identyValue.substr(10,2); 
var dd = identyValue.substr(12,2); 
var birthdate = year+"-"+mm+"-"+dd; 
if(document.form1.birthday.value.search(birthdate)==-1){
 alert("������Ϸ������֤���룡"); 
document.form1.identy.value=""; 
document.form1.birthday.value=""; 
return false 
} 
return true; 
}
