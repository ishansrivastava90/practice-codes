package car;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;

public final class CarClient {

	
	private String url;
	private int port;
	private String path;
	private Socket sock;
	private PrintWriter pr;
	
	public CarClient(String url) throws UnknownHostException, IOException {
		this.url = url;
		URL u = new URL(url);
		
		this.port = u.getPort();
		this.port = this.port != -1 ? this.port : 8080;
		this.path = u.getHost();
		
		this.sock = new Socket(path, port);
		this.pr = new PrintWriter(this.sock.getOutputStream());
	}
	
	public int getStatus() throws IOException {
		HttpURLConnection connection = (HttpURLConnection) new URL(url+"/status").openConnection();
		connection.setRequestMethod("GET");
		connection.connect();
		
		if (connection.getResponseCode() != 200) {
			throw new IOException("No response from Server");
		}
		
		InputStream is = connection.getInputStream();
		int status;
		try (BufferedReader br = new BufferedReader(new InputStreamReader(is))) {
			status = Integer.parseInt(br.readLine().trim());
		} catch(NumberFormatException | IOException e) {
			throw e;
		}
		connection.disconnect();
		return status;
	}
	
	public int throttle(int amt) throws IOException {
		String query = "amt=" + amt;
		String throttlePath = "/throttle";
		pr.write("GET " + throttlePath + "?" + query);
		pr.flush();
		
		// Get the response
		InputStream os = this.sock.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(os));
		br.readLine();
		
		
		return 200;
	}

	public void close() throws IOException {
		sock.close();
		
	}
}
