package cheight;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collection;



import cheight.UserForm;

public class UserDao {
	
	/**
	 * 获取所有用户列表
	 * @param conn
	 * @return
	 */
	public Collection<UserForm> getUserList(Connection conn){
		Statement stmt = null;
		ResultSet rs = null;
		UserForm userForm = null;
		
		Collection<UserForm> alistUser = new ArrayList<UserForm>();
		
		try{
			stmt = conn.createStatement();
			rs = stmt.executeQuery("select * from user");
			while(rs.next()){
				userForm = new UserForm();
				
				userForm.setId(rs.getString("id"));
				userForm.setUsername(rs.getString("username"));
				userForm.setAge(rs.getString("age"));
				userForm.setTel(rs.getString("tel"));
				userForm.setAddress(rs.getString("address"));
				
				alistUser.add(userForm);
			}
			rs.close();
			stmt.close();
			return alistUser;
		}catch(SQLException e){
			e.printStackTrace();
			return null;
		}
		
	}
	/**
	 * 添加用户
	 * @param conn
	 * @return
	 * @throws SQLException 
	 */
	public boolean addUser(Connection conn,UserForm form) throws SQLException{
		Statement stmt = null;
		long id = Calendar.getInstance().getTimeInMillis();
		System.out.println(id);
		try{
			conn.setAutoCommit(false);
			stmt = conn.createStatement();
			stmt.executeUpdate("insert into user value("+nextval()+",'"+form.getUsername()+"','"+form.getPassword()+"','"+form.getAge()+"','"+form.getSex()+"','"+form.getTel()+"','"+form.getAddress()+"')");
			stmt.close();
			conn.commit();
			conn.setAutoCommit(true);
			return true;
		}catch(SQLException e){
			e.printStackTrace();
			conn.rollback();
			conn.setAutoCommit(true);
			return false;
		}
		
	}

	/**
	 * 修改用户
	 * @param conn
	 * @return
	 * @throws SQLException 
	 */
	public boolean updUser(Connection conn,UserForm form) throws SQLException{
		Statement stmt = null;
		
		try{
			conn.setAutoCommit(false);
			stmt = conn.createStatement();
			stmt.executeUpdate("update user " +
							   "set username='"+form.getUsername()+"',"+
							   "age='"+form.getAge()+"',"+
							   "tel='"+form.getTel()+"',"+
							   "address='"+form.getAddress()+"' where id="+form.getId());
			
			stmt.close();
			conn.commit();
			conn.setAutoCommit(true);
			return true;
		}catch(SQLException e){
			e.printStackTrace();
			conn.rollback();
			conn.setAutoCommit(true);
			return false;
		}
		
	}
	
	/**
	 * 删除用户
	 * @param conn
	 * @return
	 * @throws SQLException 
	 */
	public boolean delUser(Connection conn,long id) throws SQLException{
		Statement stmt = null;
		
		try{
			conn.setAutoCommit(false);
			stmt = conn.createStatement();
			stmt.executeUpdate("delete from user where id="+id);
			stmt.close();
			conn.commit();
			conn.setAutoCommit(true);
			return true;
		}catch(SQLException e){
			e.printStackTrace();
			conn.rollback();
			conn.setAutoCommit(true);
			return false;
		}
		
	}
	
	/**
	 * 根据id获取用户信息
	 * @param conn
	 * @return
	 */
	public UserForm getUserById(Connection conn,long id){
		Statement stmt = null;
		ResultSet rs = null;
		UserForm userForm = new UserForm();
		
		try{
			stmt = conn.createStatement();
			rs = stmt.executeQuery("select * from user where id="+id);
			
			if(rs.next()){
				
				userForm.setId(rs.getString("id"));
				userForm.setUsername(rs.getString("username"));
				userForm.setAge(rs.getString("age"));
				userForm.setTel(rs.getString("tel"));
				userForm.setAddress(rs.getString("address"));
			}
			rs.close();
			stmt.close();
			return userForm;
		}catch(SQLException e){
			e.printStackTrace();
			return null;
		}
		
	}
	

}
