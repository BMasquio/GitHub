#include <mpi.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdlib.h>
 
using namespace std;
 
double gap, L, sendO;
double arrg[200], arrL[200], arrO[200];
 
 void rcvN(int Parameter1){
	 int i;
	 //int n = Parameter1*4;
	 int n = 104857600/2; //50M
	 char *temp;
	 temp = (char *)malloc(sizeof(char)*n);
	 

	MPI_Recv(temp,n,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	MPI_Send(temp,1,MPI_CHAR,0,0,MPI_COMM_WORLD);
	
	free(temp);
	return;
 }
 
 void gapcalc(int Parameter1){ //receive N

	//inicialize the variables
	gap = 0;
	//int n = Parameter1*4;
	int n = 104857600/2; //50M
	double sendTime1 = 0;
	double sendTime2 = 0;
	double currentTime;
	int i;
	int cont = 0;
	MPI_Request *sndarray;
	sndarray = (MPI_Request *)malloc(sizeof(MPI_Request)*n);
	
	char *temp;
	temp = (char *)malloc(sizeof(char)*n);
	for(i=0;i<n;i++) temp[i] = 'a';
	
	MPI_Status *statusarray;
	statusarray = (MPI_Status *)malloc(sizeof(MPI_Status)*n);
	//measure the beggining time
	double initialTime = MPI_Wtime();
	
	MPI_Isend(temp,n,MPI_CHAR,1,0,MPI_COMM_WORLD,&sndarray[0]);
	MPI_Wait(&sndarray[0],&statusarray[0]);

	MPI_Recv(temp,1,MPI_CHAR,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

	/*
	for (i=0; i<(n/4); i++){
			MPI_Isend(&temp,n,MPI_CHAR,1,i*4,MPI_COMM_WORLD,&sndarray[cont++]);
			MPI_Isend(&temp,n,MPI_CHAR,1,i*4+1,MPI_COMM_WORLD,&sndarray[cont++]);
			MPI_Isend(&temp,n,MPI_CHAR,1,i*4+2,MPI_COMM_WORLD,&sndarray[cont++]);
			MPI_Isend(&temp,n,MPI_CHAR,1,i*4+3,MPI_COMM_WORLD,&sndarray[cont++]);
			
			//MPI_Send(&temp,1,MPI_CHAR,1,i*4,MPI_COMM_WORLD);
			//MPI_Send(&temp,1,MPI_CHAR,1,i*4+1,MPI_COMM_WORLD);
			//MPI_Send(&temp,1,MPI_CHAR,1,i*4+2,MPI_COMM_WORLD);
			//MPI_Send(&temp,1,MPI_CHAR,1,i*4+3,MPI_COMM_WORLD);
	}
	*/
	double finalTime = MPI_Wtime() - initialTime;
	//cout << "final time = " << finalTime << endl;
	//MPI_Waitall(n-1, sndarray, statusarray);
	
	gap = (finalTime - (2*L + 4*sendO))/n;
	
	//printf ("\n***g = %.15f ms\npot = %d", gap*1000);
	
	free(temp);
	free(statusarray);
	free(sndarray);
	return;
}
 
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
 
    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
 
    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
 
    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
 
 
    //world_rank 0 and 1
    int i = 0,j;
    double inittime,totaltime;
    MPI_Request rcv,snd;
    MPI_Status status;
    int testtimes=200; 
	int c=0; double temptime;
     
    if(world_rank == 0){
		
		MPI_Request *sndarray;
		sndarray = (MPI_Request *)malloc(sizeof(MPI_Request)*testtimes);
	
		MPI_Status *statusarray;
		statusarray = (MPI_Status *)malloc(sizeof(MPI_Status)*testtimes);
		
        //SYNC
        MPI_Send(&j,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(&j,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         
        //OVERHEAD
		c = 0;
        sendO = 0;
		totaltime = 0;
		for(i=0;i<testtimes;i++){
			inittime = MPI_Wtime();
			MPI_Isend(&j,1,MPI_INT,1,1,MPI_COMM_WORLD,&sndarray[i]);
			totaltime += (MPI_Wtime() - inittime);
			temptime = (MPI_Wtime() - inittime);
			arrO[c++] = temptime;
			totaltime += temptime;
		}
        MPI_Waitall(testtimes-1, sndarray, statusarray);
        sendO = totaltime/testtimes;
         
        //L
		c = 0;
		totaltime = 0;
		L = 0;
		for(i=0;i<testtimes;i++){
			inittime = MPI_Wtime();
			MPI_Send(&j,1,MPI_INT,1,2,MPI_COMM_WORLD);
			MPI_Recv(&j,1,MPI_INT,1,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			temptime = (MPI_Wtime() - inittime);
			arrL[c++] = temptime;
			totaltime += temptime;
		}
        L = ((totaltime - (4*sendO))/2)/testtimes;
		
		//g
		c = 0;
		//testtimes /= 10;
		double totalgap=0;
		for (i=0;i<testtimes;i++){
			gapcalc(10);
			totalgap+=gap;
			arrg[c++] = gap;
		}
		gap = totalgap/testtimes;
		
		
        //printf ("\nO = %.15lf ms\nL = %.15lf ms\ng = %.15f ms\n", sendO*1000, L*1000, gap*1000);
		
		cout << "g values" << endl;
		for(i=0;i<testtimes;i++){
			printf ("%.15f	", arrg[i]*1000);
		}
		cout << endl;
		
		//testtimes *= 10;
	
		cout << "L values" << endl;
		for(i=0;i<testtimes;i++){
			printf ("%.15f	", arrL[i]*1000);
		}
		cout << endl;
		
		cout << "O values" << endl;
		for(i=0;i<testtimes;i++){
			printf ("%.15f	", arrO[i]*1000);
		}
		cout << endl;
         
    }else{
        
        //SYNC
        MPI_Recv(&j,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Send(&j,1,MPI_INT,0,0,MPI_COMM_WORLD);
         
		//OVERHEAD
		for(i=0;i<testtimes;i++) 
			MPI_Recv(&j,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);        
         
        //L
		for(i=0;i<testtimes;i++){
			MPI_Recv(&j,1,MPI_INT,0,2,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			MPI_Send(&j,1,MPI_INT,0,1,MPI_COMM_WORLD);
		}         
		 
		//g
		//testtimes /= 10;
		for (i=0;i<testtimes;i++){
			rcvN(10);
		}
		//
    }
 
    // Finalize the MPI environment.
    MPI_Finalize();
}