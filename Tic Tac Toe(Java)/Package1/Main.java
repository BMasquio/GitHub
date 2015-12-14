/*
 *  RESOLVER PROBLEMA
 *  IP E PORTA REAL ????
 */

package Package1;

import java.awt.EventQueue;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JRadioButton;
import javax.swing.Icon;
import javax.swing.JOptionPane;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedWriter;

public class Main {

	private JFrame frame;
	private JTextField IP;
	public JRadioButton Client, Server;
	JButton ConnectButt;
	static JButton row1column1,row1column2,row1column3,row2column1,row2column2,row2column3,row3column1,row3column2,row3column3;
	static Player current,enemy;
	static Board game;
	static Icon currenticon, enemyicon;
	ServerSocket listener;
	static Socket server,client;
	static ButtonsActions actions;
	static BufferedReader input;
	static PrintWriter output;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Main window = new Main();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		while(true){
		try {
				String[] parts = input.readLine().split(",");
				actions.enablesquares(true);
				//System.out.println(parts[0]+" "+parts[1]);
				game.setplace(enemy,Integer.parseInt(parts[0]),Integer.parseInt(parts[1]));
				//game.Print();
				switch(Integer.parseInt(parts[0])){
				case 0:
					switch(Integer.parseInt(parts[1])){
						case 0:
							row1column1.setIcon(enemyicon);
							break;
						case 1:
							row1column2.setIcon(enemyicon);
							break;
						case 2:
							row1column3.setIcon(enemyicon);
							break;
					}
					break;
				case 1:
					switch(Integer.parseInt(parts[1])){
					case 0:
						row2column1.setIcon(enemyicon);
						break;
					case 1:
						row2column2.setIcon(enemyicon);
						break;
					case 2:
						row2column3.setIcon(enemyicon);
						break;
					}
					break;
				case 2:
					switch(Integer.parseInt(parts[1])){
					case 0:
						row3column1.setIcon(enemyicon);
						break;
					case 1:
						row3column2.setIcon(enemyicon);
						break;
					case 2:
						row3column3.setIcon(enemyicon);
						break;
					}
					break;
				}
				Player winner = game.winner();
				if(winner != Player.Empty){
					actions.enablesquares(false);
					if(winner == current){
						//YOU WIN
						JOptionPane.showMessageDialog(null, "You win");
						client.close();
						server.close();
					}else if(winner == Player.Draw){
						//DRAW
						JOptionPane.showMessageDialog(null, "Draw");
						client.close();
						server.close();
					}else{
						JOptionPane.showMessageDialog(null, "You lose.");
						client.close();
						server.close();
						//YOU LOSE
					}
				}
			} catch (Exception e1) {
			}
		}
		
	}

	/**
	 * Create the application.
	 */
	public Main() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	
	
	private void initialize() {
		game = new Board();
		
		current = Player.O;
		enemy = Player.X;
		currenticon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/O.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
		enemyicon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/X.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
		
		frame = new JFrame();
		frame.setBounds(100, 100, 300, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel connection = new JPanel();
		frame.getContentPane().add(connection, BorderLayout.NORTH);
		connection.setLayout(new GridLayout(2, 2, 0, 0));
		
		Server = new JRadioButton("Server");
		Server.addActionListener(new RadioServer());
		connection.add(Server);
		
		Client = new JRadioButton("Client");
		Client.setSelected(true);
		Client.addActionListener(new RadioClient());
		connection.add(Client);
		
		IP = new JTextField();
		connection.add(IP);
		IP.setColumns(10);
		
		ConnectButt = new JButton("Connect");
		ConnectButt.addActionListener(new Connect());
		connection.add(ConnectButt);
		
		JPanel board = new JPanel();
		frame.getContentPane().add(board, BorderLayout.CENTER);
		board.setLayout(new GridLayout(3, 3, 0, 0));
		
		row1column1 = new JButton("");
		row1column1.setIcon(null);
		board.add(row1column1);
		
		row1column2 = new JButton("");
		board.add(row1column2);
		
		row1column3 = new JButton("");
		board.add(row1column3);
		
		row2column1 = new JButton("");
		row2column1.setIcon(null);
		board.add(row2column1);
		
		row2column2 = new JButton("");
		board.add(row2column2);
		
		row2column3 = new JButton("");
		board.add(row2column3);
		
		row3column1 = new JButton("");
		board.add(row3column1);
		
		row3column2 = new JButton("");
		board.add(row3column2);
		
		row3column3 = new JButton("");
		board.add(row3column3);
		
		row1column1.addActionListener(new Square());
		row1column2.addActionListener(new Square());
		row1column3.addActionListener(new Square());
		row2column1.addActionListener(new Square());
		row2column2.addActionListener(new Square());
		row2column3.addActionListener(new Square());
		row3column1.addActionListener(new Square());
		row3column2.addActionListener(new Square());
		row3column3.addActionListener(new Square());
		
		actions = new ButtonsActions();
		actions.enablesquares(false);
	}

	public class RadioServer implements ActionListener{
		public void actionPerformed(ActionEvent e){
			Server.setSelected(true);
			if (Server.isSelected()){
				Client.setSelected(false);
				current = Player.X;
				enemy = Player.O;
				currenticon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/X.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
				enemyicon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/O.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
				/*
				URL whatismyip = null;
				try {
					whatismyip = new URL("http://checkip.amazonaws.com");
				} catch (MalformedURLException e1) {
					e1.printStackTrace();
				}
		        BufferedReader in = null;
		        try {
		            in = new BufferedReader(new InputStreamReader(
		                    whatismyip.openStream()));
		            IP.setText(in.readLine());
		        }catch(Exception erro){}
		        finally {
		            if (in != null) {
		                try {
		                    in.close();
		                } catch (IOException erro) {
		                    erro.printStackTrace();
		                }
		            }
		        }
		    	*/
								
				//ConnectButt.setEnabled(false);
				try {
					IP.setText(InetAddress.getLocalHost().getHostAddress());
				} catch (UnknownHostException e1) {
					e1.printStackTrace();
				}
				ConnectButt.setText("Open connection");
			}
		}
	}
	
	public class RadioClient implements ActionListener{
		public void actionPerformed(ActionEvent e){
			Client.setSelected(true);
			current = Player.O;
			enemy = Player.X;
			currenticon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/O.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
			enemyicon = new ImageIcon(((new ImageIcon(Main.class.getResource("/Package1/X.jpg")).getImage().getScaledInstance(64, 64,java.awt.Image.SCALE_SMOOTH))));
			if (Client.isSelected()){
				Server.setSelected(false);
				IP.setText("ENTER THE SERVER IP");
				ConnectButt.setText("Connect");
				
				ConnectButt.setEnabled(true);
				
			}
		}
	}
	
	public class Square implements ActionListener{
		public void actionPerformed(ActionEvent e){
			int row=0, column=0;
			if(e.getSource().equals(row1column1)) {row = 1; column = 1;}
			if(e.getSource().equals(row1column2)) {row = 1; column = 2;}
			if(e.getSource().equals(row1column3)) {row = 1; column = 3;}
			if(e.getSource().equals(row2column1)) {row = 2; column = 1;}
			if(e.getSource().equals(row2column2)) {row = 2; column = 2;}
			if(e.getSource().equals(row2column3)) {row = 2; column = 3;}
			if(e.getSource().equals(row3column1)) {row = 3; column = 1;}
			if(e.getSource().equals(row3column2)) {row = 3; column = 2;}
			if(e.getSource().equals(row3column3)) {row = 3; column = 3;}
			row--; column--;
			
			//not possible move
			if(game.getplace(row, column) != Player.Empty){
				JOptionPane.showMessageDialog(null, "Not possible move.");
				return;
			}
			
			game.setplace(current, row, column);
			
			//ADD PICTURE
			if(e.getSource().equals(row1column1)) {row1column1.setIcon(currenticon);}
			if(e.getSource().equals(row1column2)) {row1column2.setIcon(currenticon);}
			if(e.getSource().equals(row1column3)) {row1column3.setIcon(currenticon);}
			if(e.getSource().equals(row2column1)) {row2column1.setIcon(currenticon);}
			if(e.getSource().equals(row2column2)) {row2column2.setIcon(currenticon);}
			if(e.getSource().equals(row2column3)) {row2column3.setIcon(currenticon);}
			if(e.getSource().equals(row3column1)) {row3column1.setIcon(currenticon);}
			if(e.getSource().equals(row3column2)) {row3column2.setIcon(currenticon);}
			if(e.getSource().equals(row3column3)) {row3column3.setIcon(currenticon);}
			
			//Transmission of the board
			output.println(String.valueOf(row)+","+String.valueOf(column));
			
			Player winner = game.winner();
			if(winner != Player.Empty){
				actions.enablesquares(false);
				if(winner == current){
					//YOU WIN
					JOptionPane.showMessageDialog(null, "You win");
					return;
				}else if(winner == Player.Draw){
					//DRAW
					JOptionPane.showMessageDialog(null, "Draw");
					return;
				}else{
					JOptionPane.showMessageDialog(null, "You lose.");
					return;
					//YOU LOSE
				}
			}
			
			actions.enablesquares(false);
							
			//Receive the enemy's move
		}
	}
	
	
	public class Connect implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(Client.isSelected()){
				try{
					client = new Socket(IP.getText(), 46329);
					
					//set input stream
			        input =  new BufferedReader(new InputStreamReader(client.getInputStream()));
			        //set output stream
			        output = new PrintWriter(client.getOutputStream(), true);;
			        
			        JOptionPane.showMessageDialog(null, "The game has began");
			        /*
			        Server.setEnabled(false);
			        Client.setEnabled(false);
			        IP.setEnabled(false);
			        ConnectButt.setEnabled(false);
			        */
			        actions.enablesquares(false);
				}catch(Exception erro){
					erro.printStackTrace();
				}
			}else if(Server.isSelected()){
				try {
					listener = new ServerSocket(46329);
		            server = listener.accept();
		            
		            //set input stream
		            input =  new BufferedReader(new InputStreamReader(server.getInputStream()));
		            //set output stream
			        output = new PrintWriter(server.getOutputStream(), true);;
		            
		            JOptionPane.showMessageDialog(null, "The game has began");
		            JOptionPane.showMessageDialog(null, "It's your turn");
		            /*
		            Server.setEnabled(false);
			        Client.setEnabled(false);
			        IP.setEnabled(false);
			        ConnectButt.setEnabled(false);*/
		            actions.enablesquares(true);
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
			Server.setEnabled(false);
	        Client.setEnabled(false);
	        IP.setEnabled(false);
	        ConnectButt.setEnabled(false);
		}
	}
	
	public class ButtonsActions{
		public ButtonsActions() {
		}
		
		public void enablesquares(boolean b){
			row1column1.setEnabled(b);
			row1column2.setEnabled(b);
			row1column3.setEnabled(b);
			
			row2column1.setEnabled(b);
			row2column2.setEnabled(b);
			row2column3.setEnabled(b);
			
			row3column1.setEnabled(b);
			row3column2.setEnabled(b);
			row3column3.setEnabled(b);
		}
	}
	
	
}


