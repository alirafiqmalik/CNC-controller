// PROJECT IF ALI HAMZA MALIK AND ALI ASHARF
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include<conio.h>


void movement(int, int);
void gcodereader();
void controlmode();
int serialcom(char);
int x = 0, y = 0, X = 0, Y = 0;
int i, j;
int time =0;
int servostate = 0;


void main() {
	char check;
	printf("*********************************************************************************************\n");
	printf("*********************************************************************************************\n");
	printf("*************************CNC MACHINE CONTROLLER SOFTWARE*************************************\n");
	printf("*********************************************************************************************\n");
	printf("*******************Code Written by ALI HAMZA Malik and ALI ASHARF****************************\n");
	printf("*********************************************************************************************\n");
	printf("*********************************************************************************************\n");

	while (1){
	printf("Enter R for Reading G-Code\n");
	printf("Enter C for Control Mode \n");
	printf("Enter X for Current Coordinates \n");
	printf("Enter G to Enter Custom Coordinates\n");
	printf("Enter S to  Change servo state\n");
	printf("Enter E to terminate program\n");
	
	scanf("%s", &check);
	if (check == 'R' || check == 'r') {
		gcodereader();
	}
	else if (check == 'C' || check == 'c') {
		controlmode();
	}
	else if (check == 'E' || check == 'e') {
		exit(1);
	}
	else if (check == 'X' || check == 'x') {
		printf("\(%d,%d\)\n",X,Y);
	}
	else if (check == 'G' || check == 'g') {
		int q=0, f=0;
		printf("Enter X and Y coordinates in format X Y\n");
		scanf("%d %d",&q,&f);

		movement(q,f);
	}
	else if (check == 'S' || check == 's') {
		
		if (servostate == 0) {
			serialcom('s');
			servostate = 1;
		}
		else if (servostate == 1) {
			serialcom('a');
			servostate = 0;


		}
	}
	else {
		printf("INVALID OPTION PLEASE TRY AGAIN\n");
		continue;
	}
	printf("\n");
	}
}


void movement(int b, int c)
{
	Sleep(100);
	if (b != X) {

		while (X < b) {
			serialcom('r');
			X++;
			
			printf("\(Xfinal= %d,Yfinal= %d\)        \(Xcurrent= %d,Ycurrent= %d\)\n", b, c, X, Y);
		}
		while(X > b) {
			serialcom('l');
			X--;
			
			printf("\(Xfinal= %d,Yfinal= %d\)        \(Xcurrent= %d,Ycurrent= %d\)\n", b, c, X, Y);
		}
		}
		if (c != Y) {

			
			while (Y < c) {
				serialcom('u');
				Y++;

				printf("\(Xfinal= %d,Yfinal= %d\)        \(Xcurrent= %d,Ycurrent= %d\)\n", b, c, X, Y);
			}
			while (Y > c) {
				serialcom('d');
				Y--;

				printf("\(Xfinal= %d,Yfinal= %d\)        \(Xcurrent= %d,Ycurrent= %d\)\n", x, y, X, Y);
			}
		
	}

}



void gcodereader()
{
	printf("Gcode is Being Read form file \"test.txt\" on the Desktop \n");
	FILE* fp;
	fp = fopen("C:\\Users\\alira\\Desktop\\test.txt", "r");

	if (fp==NULL) {
		printf("\"test.txt\"FILE NOT FOUND PLEASE TRY AGAIN\n\n");
		return 0;
	}
	char c[5000];
	char b[5000];
	char ab[5000];
	char temp1[5000];
	char temp2[5000];


	while (fscanf(fp, "%s", c) == 1)
	{
		if (strcmp(c, "G0") == 0)
		{
			fscanf(fp, "%s", b);
			for (int i = 0; i < 100; i++)
			{
				temp1[i] = b[i + 1];
			}
			sscanf(temp1, "%d", &x);
			fscanf(fp, "%s", ab);
			for (int i = 0; i < 100; i++)
			{
				temp2[i] = ab[i + 1];
			}
			sscanf(temp2, "%d", &y);

			movement(x, y);
	
		}
		if (strcmp(c, "G1") == 0)
		{
			fscanf(fp, "%s", b);
			for (int i = 0; i < 100; i++)
			{
				temp1[i] = b[i + 1];
			}
			sscanf(temp1, "%d", &x);
			fscanf(fp, "%s", ab);
			for (int i = 0; i < 100; i++)
			{
				temp2[i] = ab[i + 1];
			}
			sscanf(temp2, "%d", &y);
		
			movement(x, y);

		}
		if (strcmp(c, "G2") == 0)
		{
			fscanf(fp, "%s", b);
			for (int i = 0; i < 100; i++)
			{
				temp1[i] = b[i + 1];
			}
			sscanf(temp1, "%d", &x);
			fscanf(fp, "%s", ab);
			for (int i = 0; i < 100; i++)
			{
				temp2[i] = ab[i + 1];
			}
			sscanf(temp2, "%d", &y);
		
			movement(x, y);
		}




		if (strcmp(c, "G3") == 0)
		{
			fscanf(fp, "%s", b);
			for (int i = 0; i < 100; i++)
			{
				temp1[i] = b[i + 1];
			}
			sscanf(temp1, "%d", &x);
			fscanf(fp, "%s", ab);
			for (int i = 0; i < 100; i++)
			{
				temp2[i] = ab[i + 1];
			}
			sscanf(temp2, "%d", &y);
			movement(x, y);
		}
		if (strcmp(c, "G28") == 0)
		{
			x = 0;
			y = 0;
			movement(x, y);
		}
		if (strcmp(c, "G91") == 0)
		{
			x++;
			y++;
			movement(x, y);
		}
		if (strcmp(c, "M30") == 0)
		{

			movement(0,0);
		}

		if (strcmp(c, "Z1") == 0)
		{
			serialcom('s');
			Sleep(1000);
		}
		if (strcmp(c, "Z0") == 0)
		{
			serialcom('a');
			Sleep(1000);
		}

	}

	
}


int serialcom(char z) {

	//windows type variables
	HANDLE	hCom; //Handle variable
	DWORD	rwlen; // read/write length

	char send[32] = { 0 };
	char receive[32] = { 0 };
	send[0] = z;
	send[1] = '\0';
	int port = 4, n;
	char port_name[20];

	//printf("Please input serial port number ");
	//scanf("%d", &port);

	/*	Open COM device	*/

	sprintf(port_name, "\\\\.\\COM%d", port);

	hCom = CreateFile(port_name, GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING, 0, 0);
	//this is the CreateFile() which creates an instance of the SerialPort
	//accessible for read or write operations
	//the code in it is self-explanatory

	if (hCom == INVALID_HANDLE_VALUE)
	{
		printf("Error: COM%d is not available.\t\t", port);

		return -2;
	}



	DCB dcbSerialParams = { 0 };

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hCom, &dcbSerialParams))
	{
		printf("Unable to get the state of serial port");
		//error getting state
	}

	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;

	if (!SetCommState(hCom, &dcbSerialParams))
	{
		printf("Unable to set serial port settings\n");
		//error setting serial port state
	}

	/* DCB optional part ends here */

	/* COMTIMEOUTS Optional Part but very usefull especially against ReadHAngs */

	COMMTIMEOUTS timeouts = { 0 };

	//timeouts.ReadIntervalTimeout = 50;
	//timeouts.ReadTotalTimeoutConstant = 50;
	//timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(hCom, &timeouts))
	{

		printf("Error setting Serial Port timeouts property\n");
		//error occureed. Inform user
	}

	//printf("COM%d opened successfully\n", port);

	//printf("enter a string to send via serial port\n")

	n = strlen(send); //number of bytes to transmit
	WriteFile(hCom, send, n, &rwlen, 0); //send data through serial port

	CloseHandle(hCom);//close the handle

	return 0;
}


void controlmode() {
	char check2='\0';
	serialcom('a');
	servostate = 0;
	printf("Press U,L,R,D for axis movement\n");
	printf("Press S for servo movement\n");
	printf("Press E to exit\n");

	while (check2 != 'e' && check2 != 'E') {//check2 != 'e' && check2 != 'E'
		check2 = getch();
		if (check2 == 'r'|| check2 == 'R') {
			serialcom('r');
			
		}
		else if (check2 == 'u') {
			serialcom('u');
		}
		else if (check2 == 'd') {
			serialcom('d');
		}
		else if (check2 == 'l') {
			serialcom('l');
		}
		else if (check2 == 'r') {
			serialcom('r');
		}
		else if (check2 == 's') {
			if (servostate == 0) {
				serialcom('s');
				servostate = 1;
			}
			else if (servostate == 1) {
				serialcom('a');
				servostate = 0;


			}
		}
		else {}
	
		}
}

