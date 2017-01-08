package chsix;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ChatServlet extends HttpServlet {

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
		request.setCharacterEncoding("GBK");
		String strTitle = request.getParameter("title");
		String strContent = request.getParameter("content");
		response.setContentType("text/html;charset=GBK");
		PrintWriter out = response.getWriter();
		out.println("<html><head><title>获取留言信息</title></head><bpdy>");
		out.println("留言标题："+strTitle+"<br>");
		out.println("留言内容："+strContent+"<br>");
		out.println("<a href ='cheapsix/index.jsp'>返回</a>");
		out.println("</body></html>");
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

		response.setContentType("text/html");
		doGet(request,response);
		
	}

}
