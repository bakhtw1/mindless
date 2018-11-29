#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Waqas Bakht
//0981571
//wbakht@uoguelph.ca
//Tuesday November 28, 2017

//function prototypes
bool isValidTweet (char tweet[]);
bool isTweetAReply (char reply[]);
void shorterTweet (char tweet1[], char tweet2[], char result[]);
int  numTweetsRequired (char message[]);


//returns either true or false depending on the length of the string
bool isValidTweet(char tweet[]){

     const int maxTweetLength = 60;
     bool validTweet;
     int tweetLength = strlen(tweet);

     //a valid tweet is between 1 and 60 (inclusive)
     if(tweetLength <= maxTweetLength && tweetLength > 0){
         validTweet = true;
     }
     else{
         validTweet = false;
     }

     return validTweet;
}

//returns either true or false depending on weather the the tweet is a reply or not
bool isTweetAReply(char reply[]){

     bool validReply;
         //a reply begins with a username which is a @ symbol followed charecters
         if (reply[0] == '@' && reply[1] != ' '){
             validReply = true;
         }
         else{
             validReply = false;
         }

     return validReply;

}

//this function takes two strings and compares the length of each and tells you which is the shorter of the two
void shorterTweet(char tweet1[60], char tweet2[60], char result[20]){

     int t1Length = strlen(tweet1);
     int t2Length = strlen(tweet2);

     //various branch statements to compare string lengths
     if(t1Length < t2Length){
         strcpy(result, "Tweet 1");
     }
     if(t1Length == t2Length){
         strcpy(result, "Same Length");
     }
     if(t1Length > t2Length){
         strcpy(result, "Tweet 2");
     }

}

//returns the number of tweets required
int numTweetsRequired(char message[]){

     int messageLength = strlen(message);
     int numTweetsRequired;
     const int maxTweetLength = 60;
     int i, j;

     //the number of tweets is dependant on the length of the string

     //i represents how many times 60 goes into the length of the string
     i = messageLength / maxTweetLength;

     //j represents the remainder of the division of 60 and the length of the string
     j = messageLength % maxTweetLength;

     //if the string cannot be divisible evenly into sixty another tweet is required to display the remainder of the tweet
     if(j != 0){
          numTweetsRequired = i + 1;
     }
     else{
         numTweetsRequired = i;
     }

     return numTweetsRequired;

}
