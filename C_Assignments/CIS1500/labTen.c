#include <stdio.h>
#include <string.h>
#define MAX 100

struct Movie
{

     int mid;
     char title[MAX];
     int year;
     char director[30];

};

typedef struct Movie movies;

void readMoreMovie(movies myMovies[], int nextRead, int howMany);
void printOldest(movies myMovies[], int howMany);
void printAllMovies(movies myMovies[], int howMany);

int main (void)
{

     int index = 0;
     const int numsData = 8;

     movies myMovies[numsData];

      for(index = 0; index < 2; index++){

         printf("Enter the information for the movie\n");

         printf("Enter movie ID: ");
         scanf("%d", &myMovies[index].mid);
         getchar();

         printf("Enter movie title: ");
         fgets(myMovies[index].title, MAX, stdin);
         myMovies[index].title[strlen(myMovies[index].title) - 1] = '\0';

         printf("Enter release date: ");
         scanf("%d", &myMovies[index].year);
         getchar();

         printf("Enter director's name: ");
         fgets(myMovies[index].director, MAX, stdin);
         myMovies[index].director[strlen(myMovies[index].director) - 1] = '\0';

         printf("\n");

     }

     readMoreMovie(myMovies, index, numsData);
     printOldest(myMovies, numsData);
     printAllMovies(myMovies, numsData);


}

void readMoreMovie(movies myMovies[], int nextRead, int howMany){

     for(int i = nextRead; i < howMany; i++){

         printf("Enter the information for the movie\n");

         printf("Enter movie ID: ");
         scanf("%d", &myMovies[i].mid);
         getchar();

         printf("Enter movie title: ");
         fgets(myMovies[i].title, MAX, stdin);
         myMovies[i].title[strlen(myMovies[i].title) - 1] = '\0';

         printf("Enter release date: ");
         scanf("%d", &myMovies[i].year);
         getchar();

         printf("Enter director's name: ");
         fgets(myMovies[i].director, MAX, stdin);
         myMovies[i].director[strlen(myMovies[i].director) - 1] = '\0';
         printf("\n");

     }

}

void printOldest(movies myMovies[], int howMany){

     int min = myMovies[0].year;

     int k = 0;

     for(int i = 0; i < howMany; i++){
         if(myMovies[i].year < min){
             min = myMovies[i].year;
             k = i;
         }
     }

     printf("Oldest Movie\n");
     printf("Movie Id: %d\n", myMovies[k].mid);
     printf("Name: %s\n", myMovies[k].title);
     printf("Year of Release: %d\n", myMovies[k].year);
     printf("Director: %s\n", myMovies[k].director);
     printf("\n");

}

void printAllMovies(movies myMovies[], int howMany){

    for(int i = 0; i < howMany; i++){
        printf("Movie Id: %d\n", myMovies[i].mid);
        printf("Name: %s\n", myMovies[i].title);
        printf("Year of Release: %d\n", myMovies[i].year);
        printf("Director: %s\n", myMovies[i].director);
        printf("\n");
    }

}
