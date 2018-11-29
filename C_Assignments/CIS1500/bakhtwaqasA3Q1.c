#include <stdio.h>

//Waqas Bakht
//0981571
//wbakht@uoguelph.ca
//Tuesday November 28, 2017


//function prototypes
float percentage(float actualMark, float maximumMark);
float contribution(float actMark, float maxMark, float percMark);
float assignmentContribution(float assn1, float assn2, float assn3);
float dailyPracticeContribution(float zyChaps[11]);
float labContribution(float labs[9], float labExam1, float labExam2);
float totalTermMark(float assnCont, float dPracCont, float labCont);
float finalMarkRequired(float totalTerm, float desiredMark);



int main(void){
    printf("Get the shit out");
}


//first function gets you a percentage result for any individual piece of evaluation
float percentage(float actualMark, float maximumMark){
     float percentage = (actualMark/maximumMark) * 100;
     return percentage;
}

//this function returns the contribution your mark in this particular test/assignment had on your final mark.
float contribution(float actMark, float maxMark, float percMark){
     float rawCont = (actMark/maxMark) * percMark;
     return rawCont;
}

//this returns the contribution your three assignments had on your final grade
float assignmentContribution(float assn1, float assn2, float assn3){
     float assn1Cont = (assn1/50) *  5;
     float assn2Cont = (assn2/60) * 10;
     float assn3Cont = (assn3/60) * 10;
     float totAssnCont = assn1Cont + assn2Cont + assn3Cont; 
     return totAssnCont;
}

//this returns the contribution your zybook chapter grades had on your final grade
float dailyPracticeContribution(float zyChaps[11]){
     float min = zyChaps[0];
     int k = 0; //indicates which value in the array needs to be DESTROYED!!
     for(int i = 0; i < 11; i++){
         if(zyChaps[i] < min){
             min = zyChaps[i];
             k = i;
         }
     }
     zyChaps[k] = 0;
     float total = 0; 
     for(int i = 0; i < 11; i++){
         total = total + zyChaps[i];
     }

     //since we are removing the lowest mark the number of items in the average also becomes lower by 1
     float zyMarkCont = total/10;
     return zyMarkCont;
}

//this returns the contribution your labs marks had on your final
float labContribution(float labs[9], float labExam1, float labExam2){
     float totalLabMarks = 0;
     for(int i = 0; i < 9; i++){
         totalLabMarks = totalLabMarks + labs[i];
     }

     float labMarksCont = (totalLabMarks/9) * 10;
     float labE1Cont    = (labExam1/50) * 10;
     float labE2Cont    = (labExam2/50) * 10;
     float totLabCont = (labMarksCont + labE1Cont + labE2Cont);

     return totLabCont;
}

//returns your mark for your entire term
float totalTermMark(float assnCont, float dPracCont, float labCont){

     float totalTermCont = 0.0;
     float bonusPerc = 3.25;

     //an extra 5 percent is added if you've gotten perfect on all the termwork
     if(assnCont == 25 && dPracCont == 10 && labCont == 30){
         totalTermCont = assnCont + dPracCont + labCont + bonusPerc;
     }
     else{
         totalTermCont = assnCont + dPracCont + labCont;
     }

     return (totalTermCont/65) * 100;

}

//returns required mark on the final based on the inputted term marks and desired final marks
float finalMarkRequired(float totalTerm, float desiredMark){
     float requiredMark = ((desiredMark - totalTerm)/35.00) * 100.0;
     return requiredMark;
}
