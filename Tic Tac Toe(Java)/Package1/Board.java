package Package1;

public class Board {
	
	private Player[][] B;
	
	public Board(){
		int i,j;
		B = new Player[3][3];
		for(i=0;i<3;i++) for(j=0;j<3;j++) B[i][j] = Player.Empty;
	}
	
	public void setplace(Player p, int row, int column){
		B[row][column] = p;
	}
	
	public Player getplace(int row, int column){
		return B[row][column];
	}
	
	public void Print(){
		int i,j;
		char T[][];
		T = new char[3][3];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(B[i][j] == Player.O) T[i][j] = 'O';
				if(B[i][j] == Player.X) T[i][j] = 'X';
				if(B[i][j] == Player.Empty) T[i][j] = '-';
			}
		}
		
		for(i=0;i<3;i++){
			System.out.println(B[i][0]+" "+B[i][1]+" "+B[i][2]);
		}
	}
	
	public Player winner(){
		int i, j;
		for(i=0;i<3;i++){
			//win in rows
			if(((B[i][0] == B[i][1])&&(B[i][0] == B[i][2]))){
				if((B[i][0] == Player.X)||(B[i][0] == Player.O)) return B[i][0];
			}
			//win in columns
			if((B[0][i] == B[1][i])&&(B[0][i] == B[2][i])){
				if((B[0][i] == Player.X)||(B[0][i] == Player.O)) return B[0][i];
			}			
		}
		
		//win in diagonal
		if((B[0][0] == B[1][1])&&(B[0][0] == B[2][2])) if((B[1][1] == Player.X)||(B[1][1] == Player.O)) return B[1][1];
		if((B[0][2] == B[1][1])&&(B[0][2] == B[2][0])) if((B[1][1] == Player.X)||(B[1][1] == Player.O)) return B[1][1];
		
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if (B[i][j] == Player.Empty) return Player.Empty;
		
		return Player.Draw;
	}
}
