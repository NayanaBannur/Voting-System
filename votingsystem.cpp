#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>

class graphics
{
	public:
	void drawbox(int,int,int,int);
	void firstpage();
	void displaylist(int, int);
	void nominate_display(int);
	void vote_menu(int);
	void outline(int);
	void vote_display(char[],char[]);
}objgraphics;

class user:public graphics
{
	public:
	void nominate_names();
	void accept_nom_names(char[],char[]);
	void vote();
	void vote_category(char[],char[]);
};

class admin:public user
{
	public:
	void admin_firstpg();
	void house_names_modify();
	void init_files();
	void compile_nominations_cat(char[],char[]);
	void compile_nominations();
	void sort(char[],int);
	void vote_display_admin(int);
	void compile_results();
	void display_results(int);
}objadmin;

class teacher:public user
{
	public:
	void teacher_firstpg();
}objteacher;

class student:public user
{
}objstudent;


void graphics::drawbox(int x, int y, int a, int b)
{
	//function to draw a box with width 2a, height 2b, coordinates of centre (x,y)
	bar(x-a,y-b,x+a,y+b);
}

void graphics::firstpage()
{
	//function to generate main menu
	cleardevice();
	setfillstyle(SOLID_FILL,CYAN);
	drawbox(315,100,150,25);
	drawbox(315,175,150,25);
	drawbox(315,250,150,25);
	drawbox(315,325,150,25);
	char* c;
	setcolor(CYAN);
	settextstyle(0,0,2);
	for(int i=1;i<=4;i++)
	{
		outtextxy(138,100+(75*(i-1)),itoa(i,c,10));
	}
	setcolor(BLUE);
	settextstyle(0,0,2);
	settextjustify(1,1);
	outtextxy(315,100,"ADMIN");
	outtextxy(315,175,"TEACHER");
	outtextxy(315,250,"STUDENT");
	outtextxy(315,325,"EXIT");
}

void teacher::teacher_firstpg()
{
	//function to generate main menu for teacher first page
	closegraph();
	int gd = DETECT, gm; //initialise graphic card
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	setfillstyle(SOLID_FILL,CYAN);
	drawbox(315,100,150,25);
	drawbox(315,175,150,25);
	drawbox(315,250,150,25);
	char* c;
	setcolor(CYAN);
	settextstyle(0,0,2);
	for(int i=1;i<=3;i++)
	{
		outtextxy(138,100+(75*(i-1)),itoa(i,c,10));
	}
	setcolor(BLUE);
	settextstyle(0,0,2);
	settextjustify(1,1);
	outtextxy(315,100,"NOMINATE");
	outtextxy(315,175,"VOTE");
	outtextxy(315,250,"BACK");
}

void admin::admin_firstpg()
{
	//function to generate main menu for admin first page
	closegraph();
	int gd = DETECT, gm; //initialise graphic card
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	setfillstyle(SOLID_FILL,CYAN);
	drawbox(315,100,150,20);
	drawbox(315,150,150,20);
	drawbox(315,200,150,20);
	drawbox(315,250,150,20);
	drawbox(315,300,150,20);
	drawbox(315,350,150,20);
	drawbox(315,400,150,20);
	drawbox(315,450,150,20);
	char* c;
	setcolor(CYAN);
	settextstyle(0,0,2);
	for(int i=1;i<=8;i++)
	{
		outtextxy(138,100+(50*(i-1)),itoa(i,c,10));
	}
	setcolor(BLUE);
	settextstyle(0,0,2);
	settextjustify(1,1);
	outtextxy(315,100,"NOMINATE");
	outtextxy(315,150,"VOTE");
	outtextxy(315,200,"COMPILE NOMINATIONS");
	outtextxy(315,250,"VIEW VOTING");
	outtextxy(315,300,"COMPILE RESULTS");
	outtextxy(315,350,"DISPLAY RESULTS");
	outtextxy(315,400,"MODIFY HOUSE NAMES");
	outtextxy(315,450,"BACK");
}

void graphics::displaylist(int a, int pos)
{
	//function to display the list of categories(head boy, head girl, etc)
	ifstream fi("hname.txt",ios::in);
	char h[3][20];
	int i;
	for(i=0;i<3;i++)
	{
		fi>>h[i];
	}
	fi.close();

	char *c;
	for(i=1;i<=10;i++)
	{
		outtextxy(a-pos-45,100+(25*(i-1)),itoa(i,c,10));
	}
	outtextxy(a-pos,100,"HEAD BOY");
	outtextxy(a-pos,125,"HEAD GIRL");
	outtextxy(a-pos,150,"SPORTS CAPTAIN (BOY)");
	outtextxy(a-pos,175,"SPORTS CAPTAIN (GIRL)");
	for (i=0;i<6;i++)
	{
		char printtxt[50];
		strcpy(printtxt,h[i/2]);
		strcat(printtxt, " HOUSE ");
		if ((i%2) == 0)
		{
			strcat(printtxt, "(BOY)");
		}
		else
		{
			strcat(printtxt, "(GIRL)");
		}
		outtextxy(a-pos,200+(i*25),printtxt);
	}
}

void graphics::nominate_display(int b)
{
	//function to display nominations page
	closegraph();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	drawbox(b-200,70,150,15);
	drawbox(b+200,70,150,15);
	setcolor(BLUE);
	settextstyle(0,0,2);
	settextjustify(1,1);
	outtextxy(b-190,70,"POST");
	outtextxy(b+190,70,"NOMINEE");
	setcolor(WHITE);
	settextjustify(0,1);
	displaylist(b,315);
	outline(315);
	getch();
}

void graphics::vote_menu(int b)
{
	//function to display menu for voting
	cleardevice();
	setcolor(WHITE);
	settextjustify(0,1);
	outtextxy(b-50,70,"VOTE FOR");
	displaylist(b,150);
	getch();
}

void graphics::outline(int a)
{
	//function to draw the outlines of boxes for input
	int i;
	for(i=99; i<=330; i=i+19)
	{
	rectangle(a+50,i-10,a+323,i+9);
	i=i+6;
	}
}

void admin::init_files()
{
	//function to initialise all files
	ofstream fo1;
	fo1.open("hname.txt", ios::out|ios::noreplace);
	fo1<<"Nihal"<<endl;
	fo1<<"Kamal"<<endl;
	fo1<<"Vishal"<<endl;
	fo1.close();

	ofstream fo2;
	fo2.open("nominations_check.txt",ios::out|ios::noreplace);
	fo2<<'0'<<endl;
	fo2.close();

	ofstream fo3;
	fo3.open("results_check.txt",ios::out|ios::noreplace);
	fo3<<'0'<<endl;
	fo3.close();
}

void admin::house_names_modify()
{
	//function to modify house names
	closegraph();
	ifstream fi;
	fi.open("hname.txt", ios::in); //file storing house names
	ofstream fo;
	fo.open("newhname.txt", ios::out); //file storing modified house names
	if (!fi)
	{
		cout<<"Error! File not found.\n";
	}
	char name[20];
	char ch;
	while (fi.getline(name,20))
	{
		cout<<"Current house name: "<<name<<endl;
		cout<<"Change name? (Y/N)\n";
		cin>>ch;
		if ((ch=='y')||(ch=='Y'))
		{
			char newname[20];
			cout<<"New house name: ";
			cin>>newname;
			fo<<newname<<endl;
		}
		else
		fo<<name<<endl;
	}
	fi.close();
	fo.close();
	remove("hname.txt");
	char a[] = {"newhname.txt"};
	char b[] = {"hname.txt"};
	rename(a,b);
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

}

struct person
{
	//global structure for handling candidate details
	char name[25];
	int no_of_noms;
	int no_of_votes;
}pnew;

void user::accept_nom_names(char categoryname[],char filename[])
{
	//function to accept nominations for a particular category
	closegraph();
	fstream fio;
	if(!fio)
	{
		cout<<"Error! File not found.\n";
	}
	person pfile;
	cout<<"Enter the full name of nominee for post of "<<categoryname<<":\n";
	gets(pnew.name);

	fio.open(filename,ios::out|ios::in|ios::binary);
	while(fio.read((char*)&pfile,sizeof(pfile)))
	{
		if(strcmpi(pnew.name,pfile.name)==0)
		{
			pfile.no_of_noms++;
			int move;
			move = (-1)*sizeof(pfile);
			fio.seekg(move,ios::cur);
			fio.write((char*)&pfile,sizeof(pfile));
			fio.close();
			return;
		}
	}
	fio.close();
	fstream fiot;
	fiot.open(filename,ios::out|ios::in|ios::binary|ios::app);
	pnew.no_of_noms = 1;
	fiot.write((char*)&pnew,sizeof(pnew));
	fiot.close();
}

void user::nominate_names()
{
	//function for nominations
	nominate_display(315);
	int n,j,x;
	x=0;
	int gd = DETECT, gm;
	char names[10][25];
	char housenames[3][30];
	char tempname[50];
	int check[10];//array to check if name is present
	for(int z=0;z<10;z++)
	check[z]=0;
	fstream fi("hname.txt",ios::in);
	while (fi.getline(housenames[x],20))
	{
		x++;
	};
	char flag = 'y';
	while ((flag=='y')||(flag=='Y'))
	{
		cout<<"Enter choice (1-10).";
		cin>>n;
		switch(n)
		{
			case 1:
			accept_nom_names("head boy","headbn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 2:
			accept_nom_names("head girl","headgn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 3:
			accept_nom_names("sports captain (boy)","spcbn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 4:
			accept_nom_names("sports captain (girl)","spcgn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 5:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (boy)");
			accept_nom_names(tempname,"h1boyn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 6:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (girl)");
			accept_nom_names(tempname,"h1girln.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 7:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (boy)");
			accept_nom_names(tempname,"h2boyn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 8:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (girl)");
			accept_nom_names(tempname,"h2girln.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 9:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (boy)");
			accept_nom_names(tempname,"h3boyn.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			case 10:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (girl)");
			accept_nom_names(tempname,"h3girln.dat");
			strcpy(names[n-1],pnew.name);
			check[n-1] = 1;
			initgraph(&gd,&gm,"C:\\TC\\BGI");
			nominate_display(315);
			break;

			default:
			cout<<"Wrong choice.\n";
			break;
		}

		setcolor(WHITE);
		settextjustify(0,1);
		for (j=0;j<10;j++)
		{
			if (check[j]==1)
			outtextxy(315+50,99+(j*25),names[j]);
		}
		cout<<"Enter 'y' to continue and 'n' to exit.";
		cin>>flag;
	}
	getch();
}

void admin::sort(char fname[], int k)
{
	//function to sort nominations in descending order of number of nominations or votes
	int c=0, i;
	person obj[20];
	person t;
	fstream f;
	if(!f)
	{
		cout<<"Error! File not found.\n";
	}
	f.open(fname, ios::in|ios::binary);
	while(f.read((char*)&obj[c],sizeof(obj[c])))
	{
		c++;
	}
	f.close();
	for (i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if (k==0)
			{
				if(obj[i].no_of_noms<obj[j].no_of_noms)
				{
					t = obj[i];
					obj[i] = obj[j];
					obj[j] = t;
				}
			}
			if (k==1)
			{
			     if(obj[i].no_of_votes<obj[j].no_of_votes)
			     {
					t = obj[i];
					obj[i] = obj[j];
					obj[j] = t;
			     }
			}
		}
	}
	f.open(fname,ios::out|ios::binary);
	for(i=0;i<c;i++)
	{
		f.write((char*)&obj[i],sizeof(obj[i]));
	}
	f.close();
}

void admin::compile_nominations_cat(char fname[],char fname_vote[])
{
	//function to compile nominations for each category
	sort(fname,0);
	ifstream fi(fname,ios::in|ios::binary);
	ofstream fo(fname_vote,ios::out|ios::binary|ios::noreplace);
	person temp;
	for(int i=0;i<3;i++)
	{
		fi.read((char*)&temp,sizeof(temp));
		temp.no_of_votes = 0;
		fo.write((char*)&temp,sizeof(temp));
	}
	fi.close();
	fo.close();
}


void admin::compile_nominations()
{
	//function to compile nominations
	compile_nominations_cat("headbn.dat","headbv.dat");
	compile_nominations_cat("headgn.dat","headgv.dat");
	compile_nominations_cat("spcbn.dat","spcbv.dat");
	compile_nominations_cat("spcgn.dat","spcgv.dat");
	compile_nominations_cat("h1boyn.dat","h1boyv.dat");
	compile_nominations_cat("h1girln.dat","h1girlv.dat");
	compile_nominations_cat("h2girln.dat","h2girlv.dat");
	compile_nominations_cat("h2boyn.dat","h2boyv.dat");
	compile_nominations_cat("h3boyn.dat","h3boyv.dat");
	compile_nominations_cat("h3girln.dat","h3girlv.dat");

	fstream fo;
	fo.open("nominations_check.txt",ios::out|ios::trunc);
	fo<<'1'<<endl;

	cleardevice();
	settextstyle(0,0,2);
	settextjustify(1,1);
	setcolor(WHITE);
	outtextxy(315,60,"Nominations Compiled");
	settextstyle(0,0,1);
	outtextxy(315,80,"Click enter to return to menu");
	getch();
}

void user::vote_category(char catname[],char fname[])
{
	//function to vote for a candidate in a particular category
	closegraph();
	int gd = DETECT, gm; //initialise graphic card
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	settextstyle(0,0,2);
	settextjustify(1,1);
	setcolor(WHITE);
	outtextxy(315,60,"Nominees for the post of");
	outtextxy(315,80,catname);
	person nom,nomlist[3];
	int i=1;
	char *c;
	ifstream fi(fname,ios::in|ios::binary);
	while(fi.read((char*)&nom,sizeof(nom)))
	{
		outtextxy(138,90+(i*20),itoa(i,c,10));
		outtextxy(315,90+(i*20),nom.name);
		nomlist[i-1]=nom;
		i++;
	}
	fi.close();
	int v;
	cout<<"Enter choice (1-3).";
	cin>>v;
	switch(v)
	{
		case 1:
		nomlist[0].no_of_votes++;
		break;

		case 2:
		nomlist[1].no_of_votes++;
		break;

		case 3:
		nomlist[2].no_of_votes++;
		break;

		default:
		cout<<"Wrong choice. Please enter a number between 1 and 3.";
		break;
	}
	ofstream fo(fname,ios::out|ios::binary);
	for(int j=0;j<3;j++)
	{
		fo.write((char*)&nomlist[j],sizeof(nomlist[j]));
	}
	fo.close();
	getch();
}

void graphics::vote_display(char catname[],char fname[])
{
	//function to display number of votes for a category at any point of time
	closegraph();
	int gd = DETECT, gm; //initialise graphic card
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	settextstyle(0,0,2);
	settextjustify(1,1);
	setcolor(WHITE);
	person nom;
	int i=1;
	outtextxy(315,60,"Votes for the post of ");
	outtextxy(315,80,catname);
	ifstream fi(fname,ios::in|ios::binary);
	while(fi.read((char*)&nom,sizeof(nom)))
	{
		char strv[100]="", strnum[3];
		strcat(strv,nom.name);
		strcat(strv," - ");
		itoa(nom.no_of_votes,strnum,10);
		strcat(strv,strnum);
		outtextxy(315,90+(i*20),strv);
		i++;
	}
	settextstyle(0,0,1);
	outtextxy(315,200,"Click enter to return to menu");
	settextstyle(0,0,2);
	getch();
}

void user::vote()
{
	//function for voting
	char c;
	ifstream fi;
	fi.open("nominations_check.txt",ios::in);
	fi>>c;
	if(c!='1')
	{
		cleardevice();
		settextstyle(0,0,2);
		settextjustify(1,1);
		setcolor(WHITE);
		outtextxy(315,80,"Voting is not open. Try again later.");
		getch();
		return;
	}
	fi.close();
	int n;
	char tempname[100]="";
	char housenames[3][30];
	fstream fin("hname.txt",ios::in);
	for(int i=0;i<3;i++)
	{
		fin.getline(housenames[i],20);
	}
	fin.close();
	char ch = 'y';
	while((ch=='y')||(ch=='Y'))
	{
		cleardevice();
		vote_menu(315);
		cout<<"Enter choice (1-10).";
		cin>>n;
		switch(n)
		{
			case 1:
			vote_category("head boy","headbv.dat");
			break;

			case 2:
			vote_category("head girl","headgv.dat");
			break;

			case 3:
			vote_category("sports captain (boy)","spcbv.dat");
			break;

			case 4:
			vote_category("sports captain (girl)","spcgv.dat");
			break;

			case 5:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (boy)");
			vote_category(tempname,"h1boyv.dat");
			break;

			case 6:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (girl)");
			vote_category(tempname,"h1girlv.dat");
			break;

			case 7:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (boy)");
			vote_category(tempname,"h2boyv.dat");
			break;

			case 8:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (girl)");
			vote_category(tempname,"h2girlv.dat");
			break;

			case 9:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (boy)");
			vote_category(tempname,"h3boyv.dat");
			break;

			case 10:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (girl)");
			vote_category(tempname,"h3girlv.dat");
			break;

			default:
			cout<<"Wrong choice.\n";
			break;

		}
		vote_menu(315);
		cout<<"Enter 'y' to continue and 'n' to exit.";
		cin>>ch;
	}
}

void admin::vote_display_admin(int b)
{
	//function for vote display page
	cleardevice();
	char c;
	ifstream fi1;
	fi1.open("nominations_check.txt",ios::in);
	fi1>>c;
	if(c!='1')
	{
		cleardevice();
		settextstyle(0,0,2);
		settextjustify(1,1);
		setcolor(WHITE);
		outtextxy(315,50,"Voting is not open. Try again later.");
		getch();
		return;
	}
	fi1.close();
	setcolor(WHITE);
	settextjustify(0,1);
	int n,x;
	char tempname[30]="";
	char ch= 'y';
	char housenames[3][30];
	fstream fi("hname.txt",ios::in);
	for(x=0;x<3;x++)
	{
		fi.getline(housenames[x],20);
	}
	while((ch=='y')||(ch=='Y'))
	{
		cleardevice();
		outtextxy(50,80,"View Current Vote Tallies For");
		displaylist(b,150);
		cout<<"Enter choice (1-10).";
		cin>>n;
		switch(n)
		{
			case 1:
			vote_display("head boy","headbv.dat");
			break;

			case 2:
			vote_display("head girl","headgv.dat");
			break;

			case 3:
			vote_display("sports captain (boy)","spcbv.dat");
			break;

			case 4:
			vote_display("sports captain (girl)","spcgv.dat");
			break;

			case 5:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (boy)");
			vote_display(tempname,"h1boyv.dat");
			break;

			case 6:
			strcpy(tempname,housenames[0]);
			strcat(tempname," house captain (girl)");
			vote_display(tempname,"h1girlv.dat");
			break;

			case 7:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (boy)");
			vote_display(tempname,"h2boyv.dat");
			break;

			case 8:
			strcpy(tempname,housenames[1]);
			strcat(tempname," house captain (girl)");
			vote_display(tempname,"h2girlv.dat");
			break;

			case 9:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (boy)");
			vote_display(tempname,"h3boyv.dat");
			break;

			case 10:
			strcpy(tempname,housenames[2]);
			strcat(tempname," house captain (girl)");
			vote_display(tempname,"h3girlv.dat");
			break;

			default:
			cout<<"Wrong choice.\n";
			break;

		}
		cleardevice();
		settextjustify(0,1);
		outtextxy(50,80,"View Current Vote Tallys For");
		displaylist(b,150);
		cout<<"Enter 'y' to continue and'n' to exit.";
		cin>>ch;
	}
}

void admin::compile_results()
{
	//function to compile results of voting
	ofstream fout("final_results.dat",ios::out|ios::binary|ios::noreplace|ios::app);
	person temp;

	sort("headbv.dat",1);
	ifstream fi1("headbv.dat",ios::in|ios::binary);
	fi1.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi1.close();

	sort("headgv.dat",1);
	ifstream fi2("headgv.dat",ios::in|ios::binary);
	fi2.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi2.close();

	sort("spcbv.dat",1);
	ifstream fi3("spcbv.dat",ios::in|ios::binary);
	fi3.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi3.close();

	sort("spcgv.dat",1);
	ifstream fi4("spcgv.dat",ios::in|ios::binary);
	fi4.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi4.close();

	sort("h1boyv.dat",1);
	ifstream fi5("h1boyv.dat",ios::in|ios::binary);
	fi5.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi5.close();

	sort("h1girlv.dat",1);
	ifstream fi6("h1girlv.dat",ios::in|ios::binary);
	fi6.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi6.close();

	sort("h2boyv.dat",1);
	ifstream fi7("h2boyv.dat",ios::in|ios::binary);
	fi7.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi7.close();

	sort("h2girlv.dat",1);
	ifstream fi8("h2girlv.dat",ios::in|ios::binary);
	fi8.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi8.close();

	sort("h3boyv.dat",1);
	ifstream fi9("h3boyv.dat",ios::in|ios::binary);
	fi9.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi9.close();

	sort("h3girlv.dat",1);
	ifstream fi10("h3girlv.dat",ios::in|ios::binary);
	fi10.read((char*)&temp,sizeof(temp));
	fout.write((char*)&temp,sizeof(temp));
	fi10.close();
	fout.close();

	fstream fo;
	fo.open("results_check.txt",ios::out|ios::trunc);
	fo<<'1'<<endl;

	cleardevice();
	settextstyle(0,0,2);
	settextjustify(1,1);
	setcolor(WHITE);
	outtextxy(315,60,"Results Compiled");
	settextstyle(0,0,1);
	outtextxy(315,80,"Click enter to return to menu");
	getch();
}

void admin::display_results(int x)
{
	//function to display results of voting
	char c;
	ifstream fin;
	fin.open("results_check.txt",ios::in);
	fin>>c;
	setcolor(WHITE);
	settextjustify(0,1);
	if(c!='1')
	{
		cleardevice();
		outtextxy(x,50,"Results have not been compiled");
		return;
	}
	fin.close();
	cleardevice();
	outtextxy(x-50,50,"RESULTS");
	displaylist(x,250);
	settextstyle(0,0,1.4);
	settextjustify(1,1);
	setcolor(WHITE);
	person p;
	ifstream fi("final_results.dat",ios::in|ios::binary);
	for(int i=1;i<=10;i++)
	{
		fi.read((char*)&p,sizeof(p));
		outtextxy(x+200,75+(i*25),p.name);
	}
	settextstyle(0,0,1);
	outtextxy(315,350,"Click enter to exit");
	fi.close();
	getch();
}

void main()
{
	int gd = DETECT, gm; //initialise graphic card
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	objadmin.init_files();
	int choice, c;
	setcolor(CYAN);
	settextjustify(1,1);
	settextstyle(1,0,2.7);
	outtextxy(315,50,"National Academy For Learning");
	outtextxy(315,80,"2016-2017");
	settextstyle(1,0,6);
	outtextxy(315,150,"VOTING SYSTEM");
	settextstyle(1,0,1);
	outtextxy(315,200,"By");
	outtextxy(315,220,"Nayana Bannur");
	outtextxy(315,240,"Ananya S. Rao");
	getch();
	while(1)
	{
		objgraphics.firstpage();
		cout<<"Enter choice (1-4).";
		cin>>choice;
		switch(choice)
		{
			case 1:
			int flag1 = 0;
			while(flag1==0)
			{
				objadmin.admin_firstpg();
				cout<<"Enter choice (1-8).";
				cin>>c;
				switch(c)
				{
					case 1:
					objadmin.nominate_names();
					break;

					case 2:
					objadmin.vote();
					break;

					case 3:
					objadmin.compile_nominations();
					break;

					case 4:
					objadmin.vote_display_admin(315);
					break;

					case 5:
					objadmin.compile_results();
					break;

					case 6:
					objadmin.display_results(315);
					break;

					case 7:
					objadmin.house_names_modify();
					break;

					case 8:
					flag1=1;
					break;

					default:
					cout<<"Wrong choice.\n";
					break;
				}
			}
			break;

			case 2:
			int flag2 = 0;
			while(flag2==0)
			{
				objteacher.teacher_firstpg();
				cout<<"Enter choice (1-3)";
				cin>>c;
				switch(c)
				{
					case 1:
					objteacher.nominate_names();
					break;

					case 2:
					objteacher.vote();
					break;

					case 3:
					flag2=1;
					break;

					default:
					cout<<"Wrong choice.\n";
					break;
				}
			}
			break;

			case 3:
			objstudent.vote();
			break;

			case 4:
			closegraph();
			exit(0);
			break;
	
			default:
			cout<<"Wrong choice.\n";
			break;
		}
	}
}