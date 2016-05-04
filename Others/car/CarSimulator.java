package car;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;

public class CarSimulator {
	
	private static final int DEFAULT_CRUISE_SPEED = 30;
	private static final int DEFAULT_MEAS_THROTTLE = 5;
	
	private int cruiseSpeed;
	private String serverUrl;
	private CarClient client;
	
	
	public CarSimulator(String serverUrl, int cruiseSpeed) 
			throws UnknownHostException, IOException {
		this.serverUrl = serverUrl;
		this.cruiseSpeed = cruiseSpeed;
		this.client = new CarClient(serverUrl);
	}
	
	public CarClient getClient() {
		return client;
	}
	
	public int getCruiseSpeed() {
		return cruiseSpeed;
	}
	
	public int calculateTimeStep() throws IOException {
		int initSpeed = client.getStatus();
		client.throttle(DEFAULT_MEAS_THROTTLE);
		
		int newSpeed = client.getStatus();
		return (newSpeed - initSpeed)/DEFAULT_MEAS_THROTTLE;
		
	}
	
	public boolean isCruiseModeActivated(int currSpeed) 
			throws IOException {
		int speed2 = client.getStatus();
		int speed3 = client.getStatus();
		
		if (currSpeed != cruiseSpeed || speed2 != cruiseSpeed 
			|| speed3 != cruiseSpeed ) {
			return false;
		}
		return true;
	}
	
	/** Driver Program to run CarSimulator */
	public static void main(String [] args) throws MalformedURLException, IOException {
		
		String carControlServerUrl = args[0];
		
		CarSimulator simulator = new CarSimulator(carControlServerUrl,
				DEFAULT_CRUISE_SPEED);
		
		int timeStep = simulator.calculateTimeStep();
		CarClient client = simulator.getClient();
		while (simulator.isCruiseModeActivated(client.getStatus())) {
			
			// Calculate Throttle needed
			int currSpeed = client.getStatus();
			
			int amt = (simulator.getCruiseSpeed() - currSpeed)/timeStep;
			client.throttle(amt);
		}
		
		client.close();		
	}
}
