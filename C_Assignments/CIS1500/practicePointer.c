#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Movie{

    int mid;
    char title[30];

};

typedef struct Movie movies;

void readAMovie(movies * aMovie){

    printf("Enter a movie id: ");
    scanf("%d", &aMovie.mid);

    printf("Enter a movie title: ");
    scanf("%s", aMovie.title);

}

int main(void) {

    movies aMovies;

    readAMovie(&aMovies);

    printf("%d --- %s", aMovies.mid, aMovies.title);
}
