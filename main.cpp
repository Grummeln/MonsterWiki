#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct monsterwiki
{
  char *name;
  char *challenger;
  char *type;
  char *size;
  char *allignment;
  char *environment;
  char *tags;
};
struct monsterwiki monsters[200];
int n = 0;
struct monsterwiki makemonster (char *npc)
{
  struct monsterwiki temp;
  char *p = strtok (npc, ",");
  int cnt = 0;
  while (p != NULL)
    {
      switch (cnt)
	{
	case 0:
	  temp.name = p;
	  cnt++;
	  break;
	case 1:
	  temp.challenger = p;
	  cnt++;
	  break;
	case 2:
	  temp.type = p;
	  cnt++;
	  break;
	case 3:
	  temp.size = p;
	  cnt++;
	  break;
	case 4:
	  temp.allignment = p;
	  cnt++;
	  break;
	case 5:
	  temp.environment = p;
	  cnt++;
	  break;
	case 6:
	  temp.tags = p;
	  break;

	}
      p = strtok (NULL, ",");
    }
  return temp;
}
void read (char array[][256])
{
  FILE *ptr;
  char ch[256];

  ptr = fopen ("text.txt", "r");
  while (fgets (ch, 256, ptr))
    {
      strcpy (array[n], ch);
      n++;
    }
  fclose (ptr);
}
void printall ()
{
  FILE *fptr;

  char text[100], c;
  fptr = fopen ("text.txt", "r");
  c = fgetc (fptr);
  while (c != EOF)
    {
      printf ("%c", c);
      c = fgetc (fptr);
    }

  fclose (fptr);
}
void removal ()
{
  char name[256];
  printf ("Beefy Monsta you no longer want:");
  scanf (" %[^\n]s", name);
  FILE *TEXT1 = fopen ("text.txt", "r");
  FILE *TEXT2 = fopen ("temp.txt", "w");
  char p[256];
  while (fgets (p, 256, TEXT1))
    {
      char variable[256] = "";
      int i = 0;
      while (p[i] != ',')
	{
	  variable[i] = p[i];
	  i++;

	}
      if (strcmp (name, variable) != 0)
	fputs (p, TEXT2);
    }
  fclose (TEXT1);
  fclose (TEXT2);
  rename ("temp.txt", "text.txt");

}
void add()
{
      FILE *ptr =fopen("text.txt" , "a");
      char name[20], challenger[10], type[20], size[20], allignment[20], environment[20], tags[20];
      printf("Start inputting stuff. Name: ");
      scanf (" %[^\n]s", name);
      printf("Challenge Rating: ");
      scanf (" %[^\n]s", challenger);
      printf("Type: ");
      scanf (" %[^\n]s", type);
      printf("Size: ");
      scanf (" %[^\n]s", size);
      printf("Allignment: ");
      scanf (" %[^\n]s", allignment);
      printf("Environment: ");
      scanf (" %[^\n]s", environment);
      printf("Tag: ");
      scanf (" %[^\n]s", tags );
fprintf(ptr,"%s,%s,%s,%s,%s,%s,%s\n",name,challenger,type, size,allignment,environment,tags);
  fclose(ptr);
  }
void searchforchallenger()
{    char search_string[10];
      printf("Input a challenge rating: ");
      scanf("%s", search_string);
      for(int i=0;i<n;i++)
    {
        if(strcmp(monsters[i].challenger, search_string)==0) printf("%s,%s,%s,%s,%s,%s,%s",monsters[i].name,monsters[i].challenger,monsters[i].type,monsters[i].size,monsters[i].allignment,monsters[i].environment,monsters[i].tags);
      }

}
void sortbyname()
{struct monsterwiki temp;
	int i=0,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(strcmp(monsters[i].name,monsters[j].name)<0)
			{
				temp=monsters[j];
				monsters[j]=monsters[i];
				monsters[i]=temp;
			}
    FILE* ptr;
    ptr = fopen("text.txt" , "w");
  for (i = 0; i<n;i++)
  {
        fputs(monsters[i].name , ptr);
        fputs(",", ptr);
        fputs(monsters[i].challenger , ptr);
        fputs(",", ptr);
        fputs(monsters[i].type , ptr);
        fputs(",", ptr);
        fputs(monsters[i].size , ptr);
        fputs(",", ptr);
        fputs(monsters[i].allignment , ptr);
        fputs(",", ptr);
        fputs(monsters[i].environment , ptr);
        fputs(",", ptr);
        fputs(monsters[i].tags , ptr);
}
  fclose(ptr);
  }
void sortbychallenger()
{struct monsterwiki temp;
	int i=0,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(strcmp(monsters[i].challenger,monsters[j].challenger)<0)
			{
				temp=monsters[j];
				monsters[j]=monsters[i];
				monsters[i]=temp;
			}
    FILE* ptr;
    ptr = fopen("text.txt" , "w");
  for (i = 0; i<n;i++)
  {
        fputs(monsters[i].name , ptr);
        fputs(",", ptr);
        fputs(monsters[i].challenger , ptr);
        fputs(",", ptr);
        fputs(monsters[i].type , ptr);
        fputs(",", ptr);
        fputs(monsters[i].size , ptr);
        fputs(",", ptr);
        fputs(monsters[i].allignment , ptr);
        fputs(",", ptr);
        fputs(monsters[i].environment , ptr);
        fputs(",", ptr);
        fputs(monsters[i].tags , ptr);
}
    fclose(ptr);
  }
void clearKeyboard(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int menu(void)
{
    int done = 1;
    int choice;
    do {
        printf("Monster management System\n");
        printf("-------------------------\n");
        printf("1. Display monsters\n");
        printf("2. Add a monster\n");
        printf("3. Delete a monster\n");
        printf("4. Search by challenge rating\n");
        printf("5. Sort by name\n");
        printf("6. Sort by challenge rating\n");
        printf("0. Exit\n\n");
        printf("Select an option:> ");
        scanf("%d", &choice);

        if (choice >= 0 && choice <= 6)
            done = 0;
        else {
            clearKeyboard();
            printf("*** OUT OF RANGE *** <Enter a number   between 0 and 6>: ");
            scanf("%d", &choice);
        }
    } while (done == 1);

    return choice;
}
void ManagingMonsterSystem(void)
{
    int contactchoice;
    int done = 1;
    char yesno, c;
    do {
        contactchoice = menu();
        switch (contactchoice) {
        case 1:
            printall();
            break;
        case 2:
            add();
            break;
        case 3:
            removal();
            break;
        case 4:
            searchforchallenger();
            break;
        case 5:
            sortbyname();
            break;
        case 6:
            sortbychallenger();
            break;
        case 0:
            printf("Exit the program? (Y)es/(N)o: ");
            scanf(" %c", &yesno);
            if (yesno == 'Y' || yesno == 'y') {
                done = 0;
                break;
            }
            else if (yesno == 'N' || yesno == 'n')
                break;
        default:
            break;
        }

    } while (done == 1);
}

int main ()
{
  char array[1000][256];
  read (array);
  for (int i = 0; i < n; i++)
    monsters[i] = makemonster (array[i]);
  ManagingMonsterSystem();
  return 0;
}