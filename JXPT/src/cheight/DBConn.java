package cheight;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConn {

	public static Connection getConn() {
		//定义数据库链接
		Connection conn = null;
		try {
			Class.forName("org.gjt.mm.mysql.Driver").newInstance(); 
			String url ="jdbc:mysql://localhost/student?user=root&password=123456&useUnicode=true&characterEncoding=utf-8"; 
			//myDB为数据库名 
			conn= DriverManager.getConnection(url);

		} catch (Exception e) {
			e.printStackTrace();
		}

		return conn;

	}
}
