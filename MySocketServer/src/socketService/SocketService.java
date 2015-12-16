package socketService;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;

public class SocketService {
	public static void main(String[] args){
		ServerSocket Server = null;
		Socket socket = null;
		try {
		Server = new ServerSocket(9888);
		while(true){
			socket = Server.accept();
			StartReceiverFromClient(socket);
		}
		}
		catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			try {
				socket.close();
				Server.close();
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	public static void StartReceiverFromClient(final Socket socket){
		new Thread(new Runnable() {
			BufferedWriter writer = null;
			BufferedReader reader = null;
			@Override
			public void run() {
				// TODO Auto-generated method stub
					try {
						writer = new BufferedWriter(new OutputStreamWriter (socket.getOutputStream()));
						reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
						String s = "";
						while((s = reader.readLine()) != null){
							System.out.print(s);
							writer.write("hi client\n");
							writer.flush();
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					
				}
		}).start();
	}
}
