#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Players
{
	int jerNo;
	char name[20];
	char role[20];
	char team[20];
	char country[20];
	long long int mobile;
	int runs;
	int wickets;
	int age;
	int matches_played;
}Players;
void storePlayer(Players *, int);
void displayPlayer(Players *, int);
void search(Players *, int);

void update(Players *, int);
//void deleteData(Players *, int *);
//void addPlayers(Players * , int * );
void storePlayer(Players *p, int n)
{
	int i;
	printf("\n_____________Storing Players Data_____________\n");
	for (i = 0; i < n; i++)
	{
		printf("\nPLAYER : %d",i+1);
		printf("\n------------------------------------------------------------------");
		printf("\nEnter Jersey No                       :");
	    scanf("%d", &p[i].jerNo);
		fflush(stdin);
		
		printf("\nEnter Player name                     :");
	    gets(p[i].name);
		fflush(stdin);
		
		printf("\nEnter Role (Batsman/Bowler/Allrounder):");
        gets(p[i].role);
		fflush(stdin);
		
		printf("\nEnter the Team Name                   :");
	    gets(p[i].team);
		fflush(stdin);
		
		printf("\nEnter the Contry                      :");
        gets(p[i].country);
        fflush(stdin);
		
		printf("\nEnter Mobile number                   :");
		scanf("%lld", &p[i].mobile);
		fflush(stdin);
		
		printf("\nEnter total runs                      :");
		scanf("%d", &p[i].runs);
		fflush(stdin);
		
		printf("\nEnter total wickets taken             :");
		scanf("%d", &p[i].wickets);
		fflush(stdin);
		
		printf("\nEnter the age                         :");
		scanf("%d", &p[i].age);
		fflush(stdin);
		
		if(p[i].age>=18 && p[i].age<=55)
		{
			printf("\n--------------------------------------------------------------");
			printf("\nAge is valid to play cricket.");
			printf("\n---------------------------------------------------------------");
		}
		else
		{
			printf("\n--------------------------------------------------------------");
			printf("\nAge is not valid to play cricket.");
			printf("\n---------------------------------------------------------------");

		}
		
		printf("\nEnter total Matches played by player  :");
		scanf("%d", &p[i].matches_played);
		printf("\n------------------------------------------------------------------");
	}
	printf("\n");
}

void displayPlayer(Players *p, int n)
{
	int i;
	printf("\n   PLAYERS INFORMATION ");                                                                 
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\nJersey No\t        Name               Role                 Team Name            Country         Runs    Wicket\tMatch Played      Age   Mobile No");
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");

	for (i = 0; i < n; i++)
	{
	
	    printf("\n%-15d %-20s %-20s %-20s %-15s %-7d %-10d %-15d %-5d %-lld", p[i].jerNo, p[i].name, p[i].role, p[i].team, p[i].country, p[i].runs, p[i].wickets, p[i].matches_played, p[i].age, p[i].mobile);
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");

	}
}

void search(Players *p, int n)
{
	int i,ch,flag = 0;
	char playername[50];
	int search = p[0].jerNo;
	printf("\nEnter the choice to search:\n1.jersey Number\n2.Player's name\n");
	scanf("%d", &ch);
	
	if(ch==1)
	{
		printf("\nEnter the jersey number to search:");
		scanf("%d", &search);
		for (i = 0; i < n; i++)
		{
			if (p[i].jerNo == search)
			{
				flag = 1;
		    	printf("\n                                                                 PLAYER iNFORMATION ");
	        	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	        	printf("\nJersey No\tName                 Role                 Team Name            Country         Runs    Wicket\tMatch Played      Age   Mobile No");
	        	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	        	printf("\n%-15d %-20s %-20s %-20s %-15s %-7d %-10d %-15d %-5d %-lld", p[i].jerNo, p[i].name, p[i].role, p[i].team, p[i].country, p[i].runs, p[i].wickets, p[i].matches_played, p[i].age, p[i].mobile);
            	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
		
				break;
			}
		}

	}
	else if(ch==2)
	{
		printf("\nEnter the player name to search:");
		scanf(" %[^\n]s",playername);
		fflush(stdin);

		for (i = 0; i < n; i++)
		{
			if (strcmpi(p[i].name,playername)==0)
			{
				flag = 1;
		    	printf("\n                                                                 PLAYER iNFORMATION ");
	        	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	       		printf("\nJersey No\tName                 Role                 Team Name            Country         Runs    Wicket\tMatch Played      Age   Mobile No");
	       		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	       		printf("\n%-15d %-20s %-20s %-20s %-15s %-7d %-10d %-15d %-5d %-lld", p[i].jerNo, p[i].name, p[i].role, p[i].team, p[i].country, p[i].runs, p[i].wickets, p[i].matches_played, p[i].age, p[i].mobile);
           		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------");
	
				break;
			}
		}

	}	
	
	if (flag == 0)
	{
	    printf("\n Record not found.");	
		printf("\n===============================");	
	}
	
}

void update(Players *p, int n)
{
	int jersey;
	printf("\nEnter the jersey number :");
	scanf("%d", &jersey);

	int i, ch;
	for (i = 0; i < n; i++)
	{
		if (p[i].jerNo == jersey)
		{
			printf("\nEnter the choice to update the data :\n ");
			printf("\npress 1::Update Player Name");
			printf("\npress 2::Update Age");
			printf("\npress 3::Update Mobile No");
			printf("\npress 4::Update Role");
			printf("\npress 5::Update Team");
			printf("\npress 6::Update Country");
			printf("\npress 7::Update Runs");
			printf("\npress 8::Update Wickets");
			printf("\npress 9::Update Total Matches Played");
			printf("\n");

			printf("\nEnter your choice : ");
			scanf("%d", &ch);
            fflush(stdin);
            printf("\n=======================");
			switch (ch)
			{
				case 1:
					{
						printf("\nEnter new name for updation  : ");
					
                        gets(p[i].name);
						printf("Updated name of the player    : %s", p[i].name);
						break;
                    }
            } 
        }
    }
}      



int main()
{
	int n, choice;
	
	printf("\n-------------------------------------------------------------------------------");
	printf("\n                              Cricket Players                                  ");
	printf("\n-------------------------------------------------------------------------------");

	printf("\nEnter the number of players: ");
	scanf("%d", &n);
	Players * p;
	p = (Players*) malloc(n* sizeof(Players));
	while (1)
	{
		printf("\n\nChoose the Process :");
		printf("\n------------------------------");
		printf("\nPress 1::Store Data.");
		printf("\nPress 2::Display Data");
		printf("\nPress 3::Search Information.");
		printf("\nPress 4::Update Information.");
		printf("\nPress 5::Delete Information.");
		printf("\nPress 6::To Add Information.");
		printf("\nPress 0::To Exit");
		printf("\n------------------------------");
		printf("\n\nEnter the choice   : ");
		scanf("%d", &choice);
		printf("=======================\n");
		switch (choice)
		{
			case 1:
				{
					storePlayer(p, n);
					break;
				}

			case 2:
				{
					displayPlayer(p, n);
					break;
				}

			case 3:
				{
					search(p, n);
					break;
				}

			case 4:
				{
					update(p, n);
					break;
				}

			/*case 5:
				{
					deleteData(p, &n);
					break;
				}
		    case 6:
				{
					addPlayers( p , &n);
					break;
				}
*/
			case 0:
				{
					printf("\nExited");
					free(p);
					return 0;
				}

			default:
				printf("Enter Valid Input.");
		}
	}

	free(p);
	return 0;
}
