package cheight;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConn {

	public static Connection getConn() {
		//�������ݿ�����
		Connection conn = null;
		try {
			Class.forName("org.gjt.mm.mysql.Driver").newInstance(); 
			String url ="jdbc:mysql://localhost/student?user=root&password=123456&useUnicode=true&characterEncoding=utf-8"; 
			//myDBΪ���ݿ��� 
			conn= DriverManager.getConnection(url);

		} catch (Exception e) {
			e.printStackTrace();
		}

		return conn;

	}
}
