package cheight;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import cheight.UserDao;
import cheight.UserForm;
import cheight.DBConn;

public class UserOperServlet extends HttpServlet {

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		Connection conn = null;
		UserForm userForm = null;
		long id = 0;
		int sign = 0;
		try{
			request.setCharacterEncoding("GBK");
			
			if(request.getParameter("sign") != null){
				sign = Integer.parseInt(request.getParameter("sign"));
			}
			
			if(request.getParameter("id") != null){
				id = Long.parseLong(request.getParameter("id"));
			}
			
			conn = DBConn.getConn();
			UserDao userDao = new UserDao();
			
			switch(sign){
				case 1://add
					userForm = new UserForm();
					
					userForm.setUsername(request.getParameter("username"));
					userForm.setPassword(request.getParameter("password"));
					userForm.setAge(request.getParameter("age"));
					userForm.setSex(request.getParameter("sex"));
					userForm.setTel(request.getParameter("tel"));
					userForm.setAddress(request.getParameter("address"));
					
					if(userDao.addUser(conn, userForm)){
						response.sendRedirect("/jxpt/userservlet");
					}else{
						response.sendRedirect("/jxpt/error.jsp");
					}
					
					break;
				case 2://select
					request.setAttribute("UserForm", userDao.getUserById(conn,id));
					request.getRequestDispatcher("/bookUpd.jsp").forward(request,response);
					break;
				case 3://update
					userForm = new UserForm();
					
					userForm.setId(String.valueOf(id));
					userForm.setUsername(request.getParameter("username"));
					userForm.setPassword(request.getParameter("password"));
					userForm.setAge(request.getParameter("age"));
					userForm.setSex(request.getParameter("sex"));
					userForm.setTel(request.getParameter("tel"));
					userForm.setAddress(request.getParameter("address"));
					if(userDao.updUser(conn, userForm)){
						response.sendRedirect("/jxpt/userservlet");
					}else{
						response.sendRedirect("/jxpt/error.jsp");
					}
					break;
				case 4://delete
					
					if(userDao.delUser(conn, id)){
						response.sendRedirect("/jxpt/userservlet");
					}else{
						response.sendRedirect("/jxpt/error.jsp");
					}
					break;
			
			}
			
			
		}catch(Exception e){
			e.printStackTrace();
		}finally{
			try {
				if(conn != null)
					conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

}
