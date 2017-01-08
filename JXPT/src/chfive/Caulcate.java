package chfive;


public class Caulcate {
	private String first;
	private String second;
	private double result;
	private String operator;
	public String getFirst() {
		return first;
	}
	public void setFirst(String first) {
		this.first = first;
	}
	public String getOperator() {
		return operator;
	}
	public void setOperator(String operator) {
		this.operator = operator;
	}
	public double getResult() {
		return result;
	}
	public void setResult(double result) {
		this.result = result;
	}
	public String getSecond() {
		return second;
	}
	public void setSecond(String second) {
		this.second = second;
	}
	
	
 public void culcate(){
	 
	 double one =Double.parseDouble(first);
	 double two =Double.parseDouble(second);
	 
	 if(operator.equals("+")){
		 result= one+two;
		 
	 }else if(operator.equals("-")){
		 result= one-two;
		 
	 }else if(operator.equals("*")){
		 result= one*two;
	 }else if(operator.equals("/")){
		 result= one/two;
	 }
	 
 }
}
