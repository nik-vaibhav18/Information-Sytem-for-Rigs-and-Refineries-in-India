#include <stdio.h>//For standard I/O Operation
#include <stdlib.h>//To use functions like system(); system("dos command"); - this performs the dos command given. Eg. system("del abc.txt"); - This command deletes the file abc.txt from current location of project
#include <windows.h>//Used in making gotoxy(int, int) function
#include <conio.h>//For getch(); getche() type of functions
#include <time.h>//To get system date and time
#include <math.h>//To calculate mathematical problems, used esp. in distance calculation
#include <string.h>
#define PI 3.14159265
void gotoxy(int x,int y); //To move the cursor to x column and y row of output screen
void rectangle(int x,int y,int l,int b);// To make a rectangle starting from (x,y) with length l and breadth b
void welcome();// Displays welcome screen that you see as soon as program is executed
float r= 6373;
char loc1[100];
char loc2[100];
float lat1, long1, lat2, long2;
int res;
int choice, list, match;
int i;
FILE *ptr_file;
char buf[100000];
struct student
{
	
	char name[20];
	char blog[400];
};

// variables used in searching
char key[20];
FILE *fp;
int line_num = 1;
int find_result = 0;
char temp[512];

static int j=0;
struct web
{
char name[30],pass[30];
}w[99];


int n;
    
COORD coord = {0, 0};

void gotoxy (int x, int y)
        {
        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}

void mainmenu()
	{
		system("cls"); //Clears the screen
		
		rectangle(0,0,80,23);
    	gotoxy(15,4); printf("INFORMATION SYSTEM FOR RIGS AND REFINERIES IN INDIA");
    	gotoxy(15,5); for(i=0;i<51;i++) printf("%c",196);
		printf("\n");
		gotoxy(2,9);printf("MENU");
		printf("(Note: Select any one of the below mention choices)");
		gotoxy(2,10);for(i=0;i<55;i++) printf("%c",196);
		gotoxy(2,12);printf("1. Rigs and Refineries in India");
		gotoxy(2,13);printf("2. Search with a Keyword");
		gotoxy(2,14);printf("3. Shortest Distance from Particular Rig/Refinery to other Rigs/Refineries");
		gotoxy(2,15);printf("4. Write Blog");
		gotoxy(2,16);printf("5. Logout");
		//gotoxy(2,16);printf("5. Logout");
		//printf("1. Rigs and Refineries in India \n2. Search with a Keyword \n3. Shortest Distance from Particular Rig/Refinery to other Rigs/Refineries \n4. Write a Blog \n5. Logout \n");
		gotoxy(2,19);printf("Enter the choice: ");
		scanf("%d",&choice);
	}
	
	
	
void information()
{
	system("cls");
					rectangle(0,0,80,24);
    				gotoxy(23,2); printf("LIST OF RIGS AND REFINERIES IN INDIA");
    				gotoxy(23,3); for(i=0;i<36;i++) printf("%c",196);
    				gotoxy(2,5);printf(" 1. Baruni Refinery");
    				gotoxy(2,6);printf(" 2. Gujarat Refinery");
    				gotoxy(2,7);printf(" 3. Haldia Refinery");
    				gotoxy(2,8);printf(" 4. Jamnagar Refinery");
    				gotoxy(2,9);printf(" 5. Kochi Refinery");
    				gotoxy(2,10);printf(" 6. Mangalore Refinery");
    				gotoxy(2,11);printf(" 7. Mathura Refinery");
    				gotoxy(2,12);printf(" 8. Mumbai Refinery");
    				gotoxy(2,13);printf(" 9. Panipat Refinery");
    				gotoxy(2,14);printf("10. Vishakapatnam Refinery");
    				gotoxy(2,15);printf("11. Barmer Rig");
    				gotoxy(2,16);printf("12. Bombay High Rig");
    				gotoxy(2,17);printf("13. Cambay Rig");
    				gotoxy(2,18);printf("14. Digboi Rig");
    				gotoxy(2,19);printf("15. Panna Mukta Rig");
    				gotoxy(2,20);printf("16. GoTo Main Menu");
					//printf("1. Baruni Refinery \n2. Gujarat Refinery \n3. Haldia Refinery \n4. Jamnagar Refinery \n5. Kochi Refinery \n6. Mangalore Refinery \n7. Mathura Refinery \n8. Mumbai Refinery \n9. Panipat Refinery \n10. Vishakapatnam Refinery \n11. Barmer Rig \n12. Bombay High Rig \n13. Cambay Rig \n14. Digboi Rig \n15. Panna Mukta Rig \n16. GoTo Main Menu \n");
					//printf("\n \n");
					gotoxy(2,22);printf("Enter the choice: ");
					scanf("%d", &list);
					
}

int baruni()
{
	system("cls");
	//rectangle(0,0,80,120);
	printf("\t \t \t \tBaruni Refinery");
	printf("\n \n");

	ptr_file =fopen("baruni.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int gujarat()
{
	system("cls");
	printf("\t \t \t \tGujarat Refinery");
	printf("\n \n");

	ptr_file =fopen("gujarat.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int haldia()
{
	system("cls");
	printf("\t \t \t \tHaldia Refinery");
	printf("\n \n");

	ptr_file =fopen("haldia.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int jamnagar()
{
	system("cls");
	printf("\t \t \t \tJamnagar Refinery");
	printf("\n \n");

	ptr_file =fopen("jamnagar.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int kochi()
{
	system("cls");
	printf("\t \t \t \tKochi Refinery");
	printf("\n \n");

	ptr_file =fopen("kochi.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int mangalore()
{
	system("cls");
	printf("\t \t \t \tMangalore Refinery");
	printf("\n \n");

	ptr_file =fopen("mangalore.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int mathura()
{
	system("cls");
	printf("\t \t \t \tMathura Refinery");
	printf("\n \n");

	ptr_file =fopen("mathura.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int mumbai()
{
	system("cls");
	printf("\t \t \t \tMumbai Refinery");
	printf("\n \n");

	ptr_file =fopen("mumbai.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int panipat()
{
	system("cls");
	printf("\t \t \t \tPanipat Refinery");
	printf("\n \n");

	ptr_file =fopen("panipat.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int vishakapatnam()
{
	system("cls");
	printf("\t \t \t \tVishakapatnam Refinery");
	printf("\n \n");

	ptr_file =fopen("vishakapatnam.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int barmer()
{
	system("cls");
	printf("\t \t \t \tBarmer Rig");
	printf("\n \n");

	ptr_file =fopen("barmer.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int bombay_high()
{
	system("cls");
	printf("\t \t \t \tBombay High Rig");
	printf("\n \n");

	ptr_file =fopen("bombay high.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int cambay()
{
	system("cls");
	printf("\t \t \t \tCambay Rig");
	printf("\n \n");

	ptr_file =fopen("cambay.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int digboi()
{
	system("cls");
	printf("\t \t \t \tDigboi Rig");
	printf("\n \n");

	ptr_file =fopen("digboi.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}

int panna_mukta()
{
	system("cls");
	printf("\t \t \t \tPanna Mukta Rig");
	printf("\n \n");

	ptr_file =fopen("panna mukta.txt","r");
    if (!ptr_file)
    return 1;
	
    while (fgets(buf,100000, ptr_file)!=NULL)
    	{
    		printf("%s",buf);
		}
        					

	fclose(ptr_file);
 
	getch();
	return 0;	
}
	
	
void search_menu()
{
	system("cls");
					rectangle(0,0,80,23);
					gotoxy(28,2);printf("SEARCHING WITH A KEYWORD");
					gotoxy(28,3); for(i=0;i<24;i++) printf("%c",196);
						gotoxy(2,6);printf("1. Enter a Keyword");
						gotoxy(2,7);printf("2. Exit ");
					//printf("1. Enter a Keyword \n2. Exit \n\n");
					gotoxy(2,9);printf("Enter the choice: ");
					scanf("%d", &match);
}


void calc_dis()
{
	double dlon = long2 - long1;
	double dlat = lat2 - lat1;
	
	double val= PI/180;
	//double val1= 180/PI;
	double dlat1=dlat*val;
	double dlon1=dlon*val;
	double a = (sin(dlat1/2)*sin(dlat1/2))+ (cos(lat1*val) * cos(lat2*val) * sin(dlon1/2)*sin(dlon1/2));
	double c = 2 * atan2( sqrt(a), sqrt(1-a));
	double d = r * c; //(where R is the radius of the Earth)
	
	printf("Distance is %lf kms.",d);
	
	//printf("\n\n\n");
	
	
	getch();
	
}
 

void print_loc1()
{
	printf("Enter your First location: ");
    scanf("%s", loc1);
    //printf("%s",loc1);
    if(strstr(loc1, "barauni"))
   {
   	lat1=25.4313;
   	long1=86.0600;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
   else if(strstr(loc1, "gujarat"))
   {
   	lat1=22.3702;
   	long1=73.1202;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "haldia"))
   {
   	lat1=22.0495;
   	long1=88.1079;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "jamnagar"))
   {
   	lat1=22.34516;
   	long1=69.8596;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "kochi"))
   {
   	lat1=9.9722;
   	long1=76.378;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "mangalore"))
   {
   	lat1=12.9869;
   	long1=74.84739;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "mathura"))
   {
   	lat1=27.3771;
   	long1=77.6860;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "mumbai"))
   {
   	lat1=19.01794;
   	long1=72.90321;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "panipat"))
   {
   	lat1=29.5149;
   	long1=76.9081;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "vishakapatnam"))
   {
   	lat1=17.7048;
   	long1=83.24465;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "barmer"))
   {
   	lat1=25.7531;
   	long1=71.4180;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "bombay_high"))
   {
   	lat1=19.4167;
   	long1=71.3333;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "cambay"))
   {
   	lat1=22.3180;
   	long1=72.6189;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "digboi"))
   {
   	lat1=27.3932;
   	long1=95.6183;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
    else if(strstr(loc1, "panna_mukta"))
   {
   	lat1=19.3629;
   	long1=71.9412;
   	gotoxy(2,7);printf("Latitude1 : %f",lat1);
   	//printf("\n");
   	gotoxy(2,8);printf("Longitude1 : %f",long1);
   }
   else
   {
   	gotoxy(2,8);printf("Enter the valid rig/refinery name!!");
   }
    //printf("\n");
   // printf("Your first location is: %s", loc1);
   getch();
}

void print_loc2()
{
	 	printf("Enter your second location: ");
    scanf("%s", loc2);
  
   if(strstr(loc2, "barauni") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=25.4313;
   	long2=86.0600;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
   else if(strstr(loc2, "gujarat") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=22.3702;
   	long2=73.1202;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "haldia") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=22.0495;
   	long2=88.1079;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "jamnagar") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=22.34516;
   	long2=69.8596;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "kochi") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=9.9722;
   	long2=76.378;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "mangalore") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=12.9869;
   	long2=74.84739;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "mathura") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=27.3771;
   	long2=77.6860;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "mumbai") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=19.01794;
   	long2=72.90321;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "panipat") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=29.5149;
   	long2=76.9081;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "vishakapatnam") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=17.7048;
   	long2=83.24465;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "barmer") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=25.7531;
   	long2=71.4180;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "bombay_high") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=19.4167;
   	long2=71.3333;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "cambay") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=22.3180;
   	long2=72.6189;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "digboi") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=27.3932;
   	long2=95.6183;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
    else if(strstr(loc2, "panna_mukta") &&(strcmp(loc2,loc1)!=0))
   {
   	lat2=19.3629;
   	long2=71.9412;
   	gotoxy(2,11);printf("Latitude2 : %f",lat2);
   	//printf("\n");
   	gotoxy(2,12);printf("Longitude2 : %f",long2);
   }
   else
   {
   	gotoxy(2,12);printf("Enter the valid rig/refinery name!!");
   }
    gotoxy(2,13);printf("\n");
   // printf("Your second location is: %s", loc2);
   
   getch();
}	
	
void reg()
  {
  	system("cls");
  	rectangle(0,0,80,23);
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("user.txt","w");
    
	
    
	gotoxy(27,2);printf("WELCOME TO REGISTER ZONE");
	gotoxy(27,3);
	for(int i=0;i<24;i++)
	{
		printf("%c",196);
	}
    printf("\n");
    for(j=0;j<100;j++)
    {
      gotoxy(2,5);printf("ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[j],sizeof(w[j]),1,fp);
          if(strcmp(checker,w[j].name)==0)
            {
            gotoxy(2,7);printf("USERNAME ALREDY EXISTS");
            
            reg();
            }
          else
          {
            strcpy(w[j].name,checker);
            break;
          }
        }
      gotoxy(2,7);printf("ENTER PASSWORD: ");
      while((c=getch())!=13)
        {
          w[j].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[j],sizeof(w[j]),1,fp);
      fclose(fp);
      gotoxy(2,9);printf("PRESS ENTER IF YOU AGREE TO USERNAME AND PASSWORD");
      if((c=getch())==13)
        {
       	
        gotoxy(2,11);printf("YOU ARE SUCCESSFULLY REGISTERED!!");
        gotoxy(2,13);printf("TRY LOGIN YOUR ACCOUNT?");
        gotoxy(2,14);printf("1. YES");
		gotoxy(2,15);printf("2. NO");
		gotoxy(2,16);printf("ENTER CHOICE: ");
        scanf("%d", &n);
        
          
        }
        break;
      }
    getch();
  }

void blogmenu()
{
	 
					
			gotoxy(2,5);printf("1.Write blog");
			gotoxy(2,6);printf("2.Read Blog");
			gotoxy(2,8);printf("Enter choice: ");
			scanf("%d",&res);	
}
void writeblog()
{
		rectangle(0,0,80,23);
		gotoxy(30,2);printf("Write Blog");
		gotoxy(30,3);for(i=0;i<10;i++) printf("%c",196);
		struct student rec;
		FILE *fp;
		fp=fopen("record.dat","a");
		gotoxy(2,4);printf("Enter name: ");
								//gets(rec.name);
		scanf("%s",rec.name);
		gotoxy(2,6);printf("Write blog");
		printf("\n");
								//gets(rec.blog);
		scanf("%s",rec.blog);
		fwrite(&rec,sizeof(struct student),1,fp);
			fclose(fp);
			getch();
			
}

void readblog()
{
	rectangle(0,0,80,23);
	gotoxy(35,2);printf("Read Blog");
	gotoxy(35,3);for(i=0;i<9;i++) printf("%c",196);
	struct student re;
		FILE *f;
		f=fopen("record.dat","r");
								
		while(fread(&re,sizeof(struct student),1,f)==1)
		{
			gotoxy(2,4);printf("\n name:%s",re.name);
			gotoxy(2,6);printf("\nBlog: %s",re.blog);
		}
			fclose(f);
								//getch();
									
		getch();
			
}

int working()
{
		mainmenu();
	do
	{
		
		switch(choice)
		{
			case 1:
					information();
				do
				{
					
					switch(list)
					{
					case 1:
							
							baruni();
							information();
							break;
							
					
					case 2:
							
							gujarat();
							information();
							break;
					case 3:
							
							haldia();
							information();
							break;		
					
					case 4:
							
							jamnagar();
							information();
							break;
							
					case 5:
							
							kochi();
							information();
							break;
							
					case 6:
							
							mangalore();
							information();
							break;
					
					case 7:
							
							mathura();
							information();
							break;
					
					case 8:
							
							mumbai();
							information();
							break;
					
					case 9:
							
							panipat();
							information();
							break;
					
					case 10:
							
							vishakapatnam();
							information();
							break;
							
					case 11:
							
							barmer();
							information();
							break;		
							
					case 12:
							
							bombay_high();
							information();
							break;
							
					case 13:
							
							cambay();
							information();
							break;
							
					case 14:
							
							digboi();
							information();
							break;
							
					case 15:
							
							panna_mukta();
							information();
							break;
							
											
					case 16:
							mainmenu();	
							break;	
							
					default:
							//system("cls");
							gotoxy(2,22);printf("Enter a Valid Choice!!");
							
							getch();
							information();
							break;
							//information();
							//return 0;
							
								
					}
			}
				
			while(list != 16);
			break;
			
			case 2:
				do
				{
					//char key[20];
				/*	system("cls");
					rectangle(0,0,80,23);
					gotoxy(28,2);printf("SEARCHING WITH A KEYWORD");
					gotoxy(28,3); for(i=0;i<24;i++) printf("%c",196);
						gotoxy(2,6);printf("1. Enter a Keyword");
						gotoxy(2,7);printf("2. Exit ");
					//printf("1. Enter a Keyword \n2. Exit \n\n");
					gotoxy(2,9);printf("Enter the choice: ");
					scanf("%d", &match); */
					search_menu();
					switch(match)
					{
						case 1:
								//printf("\n\n");
								gotoxy(2,9);printf("Enter a keyword: ");
								scanf("%s",&key);
								if((fp = fopen("baruni.txt", "r")) == NULL) 
								{
									return(-1);
								}
								while(fgets(temp, 512, fp) != NULL) 
								{
									if((strstr(temp, key))) 
									{
										gotoxy(2,11);printf("A match found on line: %d", line_num);
										gotoxy(2,12);printf("%s", temp);
										find_result++;
									}
									line_num++;
								}
	
								if(find_result == 0) 
								{
									gotoxy(2,11);printf("Sorry, couldn't find a match.");
								}
	
								//Close the file if still open.
								if(fp) {
								fclose(fp);
								}
   								//return 0;
   								getch();
								break;
								search_menu();
							
						case 2:	
							
									mainmenu();
									break;
									
						default:
									gotoxy(2,11);printf("Enter a Valid Choice!!");
									getch();
									break;
									search_menu();
												
									
					}
				}
				while(match !=2);
				break;
				case 3:
				system("cls");
				rectangle(0,0,80,65);
				gotoxy(30,2);printf("DISTANCE CALCULATION");
				gotoxy(30,3); for(i=0;i<20;i++) printf("%c",196);
				gotoxy(2,6);print_loc1();
				gotoxy(2,10);print_loc2();
   				gotoxy(2,14);calc_dis();
    				//return 0;
    				//getch();
				mainmenu();
				break;
				
				
					
				case 4:
					  system("cls");
					  rectangle(0,0,80,23);
					 gotoxy(30,2);printf("Blogs From the User");
					 gotoxy(30,3); for(i=0;i<19;i++) printf("%c",196);
					 blogmenu();
					do
					{
					
							switch(res)
							{
								case 1:
									{
										system("cls");
										writeblog();
										blogmenu();
							
								
										break;
									}
									
								
								case 2:
									{
									system("cls");
									readblog();
									blogmenu();
									break;
									}
									
										default:
									printf("wrong choice");
							}
							
								
						}while(res!=3);
						return 0;
									
				
								
							
								case 5:
								gotoxy(2,22);printf("YOU ARE SUCCESSFULLY LOGEED OUT!!");
					
					//exit(0);
					//welcome();
									exit(0);
									
								
						
					  
											
				
				default:
					gotoxy(2,21);printf("Please Enter a valid Chhoice!!");
					getch();
					mainmenu();
					break;
					
					
		}
	}
	while(choice != 4);
	getch();
	return 0;
}

void login()
    {
    	system("cls");
    	rectangle(0,0,80,23);
    	
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("user.txt","rb");
      gotoxy(30,2);printf("WELCOME TO LOGIN ZONE");
      gotoxy(30,3);
	for(int i=0;i<21;i++)
	{
		printf("%c",196);
	}
      printf("\n");
      for(j=0;j<1000;j++)
      {
        gotoxy(2,5);printf("ENTER USERNAME: ");
        scanf("%s",name);
        gotoxy(2,7);printf("ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[j],sizeof(w[j]),1,fp);
          checku=strcmp(name,w[j].name);
          checkp=strcmp(pass,w[j].pass);
          if(checku==0&&checkp==0)
          {
            
            gotoxy(2,9);printf("YOU HAVE LOGGED IN SUCCESSFULLY!!");
            gotoxy(2,11);printf("WELCOME, HAVE A NICE DAY");
            working();
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            gotoxy(2,9);printf("WRONG PASSWORD!! Not %s??",name);
            gotoxy(2,11);printf("PRESS 'Y' TO RE-LOGIN ");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            gotoxy(2,10);printf("YOU ARE NOT A REGISTERED USER!!");
			gotoxy(2,12);printf("PRESS ENTER TO REGISTER YOURSELF!!");
            if(getch()==13)
            
            reg();
          }
        }
        break;
      }
      getch();
    }
    

void first()
{
	system("cls");
rectangle(0,0,80,23);
gotoxy(9,2);printf("WELCOME TO INFORMATION SYSTEM FOR RIGS AND REFINERIES IN INDIA");
gotoxy(9,3);
	for(int i=0;i<62;i++)
	{
		printf("%c",196);
	}
//if(getch()==13)

//XY:
gotoxy(2,5);printf("1. USER LOGIN");
gotoxy(2,6);printf("2. REGISTRATION");
gotoxy(2,7);printf("3. EXIT");
gotoxy(2,9);printf("ENTER YOUR CHOICE: ");
scanf("%d",&n);
}

void welcome()
{
    int i;
    system("cls");
    rectangle(0,0,80,23);
    gotoxy(15,4); printf("INFORMATION SYSTEM FOR RIGS AND REFINERIES IN INDIA");
    gotoxy(15,5); for(i=0;i<51;i++) printf("%c",196);
    gotoxy(25,8); printf("Designed and Programmed by:");
    gotoxy(25,9);for(i=0;i<27;i++) printf("%c",196);
    gotoxy(33,11); printf("Money Jain");
    gotoxy(33,13); printf("Nikhil Vaibhav");
    gotoxy(33,15); printf("Parth Agarwal");
    gotoxy(24,20);

    printf("Press Any key to continue...");


    getch();

}










int main()
{
	welcome();
	
	first();
	do
{
	
switch(n)
  {
    case 1:
    	login();
        break;
    case 2: 
        reg();
        switch(n)
		{
              case 1: 
                    login();
                    break;
              case 2: 
                    gotoxy(2,18);printf("THANK YOU FOR REGISTERING!!");
                    break;
          }
        break;
    case 3:
       gotoxy(2,11);printf("THANKYOU!!");
       gotoxy(2,12);printf("HAVE A NICE DAY!!");
       exit(0);
    default: 
	gotoxy(2,11);printf("ENTER A VALID CHOICE!!");
	getch();
	first();
	break;
	}
}
  while(n !=3);
	getch();
	return 0;
	
}
