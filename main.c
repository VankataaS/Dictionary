#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define size_row 128 // kolko sa dulgi dumite + obqsneniqta za tqh
#define size_word 20 // kolko sa dulgi samite dumi
#define point " " // kak shte razdelqme samite dumi (priemame che nqma da ima 2 dumi tam kadeto shte e samata duma). ne izpolzvame "-" tui kato moje da ima duma s tire

int main()
{
	// definirame samata enciklopediq
	char row[size_row]; // masiv v koito shte slojim kolko line-a shte ima vuv file-a
	char word[size_word]; // masiv v koito shte slojim samite dumi + opisaniq
	char* piece; // promenliva koqto proverqva tursena duma
	FILE* fpointer; // FILE promenliva v koqta da preglejdame dumite
	char Name[20]; // ime na choveka koito shte polzva enciklopediqta
	int  r = 0; // promenliva koqto priema vhod ot potrebitelq za rabota s programata
	printf("Hello, please enter your nickname \n");
	scanf("%[^\n]s", &Name);
	while (r != 3)
	{

		printf("\n%s Enter your choice\n1.View Dictionary\n2.Search word in Dictioanary\n3.Quit\n", Name);
		scanf("%d", &r);

		switch (r) {
			// Kogato potrebitelq iska da vidi sudurjanieto na enciklopediqta
		case 1:

			//otvarqme file-a
			fpointer = fopen("encyclopedia.txt", "r");
			//proverqvame dali ima takuv file
			if (fpointer != NULL) {
				char row[128];
				//chetem vsichki line-ove na file-a i gi printirame
				while (fgets(row, sizeof row, fpointer) != NULL)
				{
					fputs(row, stdout);
				}
				//zatvarqme file-a sled kato sme go polzvali
				fclose(fpointer);
			}
			//Ako ne e nameren file-a idvame tuk
			else
			{
				perror(fpointer);
			}
			break;

			// Kogato potrebitelq iska da vidi dali ima dadena duma
		case 2:
			printf("Please enter your word here\n");
			scanf("%s", &word); // priemame duma za tursene
			fpointer = fopen("encyclopedia.txt", "r"); // otvarqme file-a
			//proverka dali ima takuv file
			if (fpointer != NULL)
			{
				//Cikul koito da proverqva vsqki line za tursenata duma
				while (fgets(row, size_row, fpointer) != NULL)
				{
					piece = strtok(row, point); //razdelq stringa
					if (strcmp(piece, word) == 0)//proverqva dumata
					{
						// ako dumata syvpada printirame znachenieto
						while (piece != NULL)
						{
							printf("%s", piece);
							piece = strtok(NULL, point);

						}
						break;
					}

				}
				// Ako ne e namerena dumata izpisvame che nqma takava duma
				if (fgets(row, size_row, fpointer) == NULL)
				{
					printf("\nNot in encyclopedia\nSorry :( \n\n");
				}
			}
			// Ako nqma tusreniq file idvame tuk
			else
			{
				perror(fpointer);
			}
			break;

		default: break;
		}
	}
	return 0;
}