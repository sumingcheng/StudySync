package chfive;
import java.io.*;
public class SampleBean2{
		public SampleBean2(){
		}
		private String userName;
		private String userPass;
		public void setUserName(String userName) {
	    		this.userName = userName;
	 	}
		public void setUserPass(String userPass) { 
			this.userPass = userPass;
		}
		public String getUserName(){ 
			return userName;
		}
		public String getUserPass(){
			return userPass;
		}
}
