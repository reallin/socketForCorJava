package socketClient;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class SocketClient {
	
	BufferedReader readerFromServer = null;
	Socket socket = null;
	public static void main(String[] args){
		SocketClient client = new SocketClient();
		client.start();
	}
	public void start(){
		
		 BufferedWriter writer = null;
		 BufferedReader reader = null;
 try {	
		socket = new Socket("127.0.0.1", 9888);
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
		String string = null;
		StartReceiverFromServer();
		while(!(string = reader.readLine()).equals("end")){
			System.out.println("start send¡­¡­¡­¡­");
		writer.write("from client:"+string+'\n');
		writer.flush();
		}
	}  catch (Exception e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}finally{
		try {
			socket.close();
			writer.close();
			reader.close();
			readerFromServer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	}
	public void StartReceiverFromServer(){
		try {
			readerFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			new Thread(new Runnable() {
				
				public void run() {
					try {
						String string = null;
						while((string = readerFromServer.readLine())!=null){
							System.out.println("from server :"+string);
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}).start();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
