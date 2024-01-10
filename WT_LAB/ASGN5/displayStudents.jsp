<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>Display Students Info</title>
</head>
<body>
    <h1>Students Information</h1>

    <%
        // JDBC URL, username, and password of MySQL server
        String jdbcUrl = "jdbc:mysql://localhost:3306/db123";
        String dbUser = "root";
        String dbPassword = "pict@123";
        try {
            // Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish a connection
            Connection connection = DriverManager.getConnection(jdbcUrl, dbUser, dbPassword);

            // Create a statement
            Statement statement = connection.createStatement();

            // Execute a query to select all rows from the students_info table
            ResultSet resultSet = statement.executeQuery("SELECT * FROM students_info");

            // Display the table content
            out.println("<table border='1'>");
            out.println("<tr><th>ID</th><th>Name</th><th>Class</th><th>Division</th><th>City</th></tr>");

            while (resultSet.next()) {
                out.println("<tr>");
                out.println("<td>" + resultSet.getInt("stud_id") + "</td>");
                out.println("<td>" + resultSet.getString("stud_name") + "</td>");
                out.println("<td>" + resultSet.getString("class") + "</td>");
                out.println("<td>" + resultSet.getString("division") + "</td>");
                out.println("<td>" + resultSet.getString("city") + "</td>");
                out.println("</tr>");
            }

            out.println("</table>");

            // Close resources
            resultSet.close();
            statement.close();
            connection.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        }
    %>

</body>
</html>

