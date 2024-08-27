// Write 2 functions
/*
- call 2 fuctions output result
  -read data
    -have struct named student
      has stuID, Average(Float)
    void readData(struct Student *students, int *c)
  -Getmax average
    -finds highest average between the two functions
*/

/* THIS SERVES AS A CODE TEMPLATE FOR CS1 LAB1 ASSIGNMENT */

/*This program demonstrates an example structure, function, and pointer to
strcture. It reads data for N number of student's id numbers and their scores
for 3 courses. The program reads those scores and output the same information
and average score. Then it finds the maximum average and the student who
obtained the max average
Sample data:
5
861022 65 72 56
851102 78 45 80
860501 55 75 90
841205 75 80 95
850630 40 50 48
*/
#include <stdio.h>
#include "main.h"
#define MAXSIZE 500

// struct Student {
// 	int student_ID;
// 	int g1, g2, g3;
// 	float average;
// };

struct Student getMaxAverageStudent(struct Student *s, int n) {

  //declare int variables for i and for max index
  //declare a float variable to store the current max average
  int i, maxIndex = 0;
  float maxAverage = s[0].average;

  //loop through the number of students
  for (i = 1; i < n; i++) {
      //if a better average is found, update max and max index         accordingly
      if (s[i].average > maxAverage) {
        maxAverage = s[i].average;
        maxIndex = i;
      }
  }

  //return student whose avergae is the best
  return s[maxIndex];
}

void readData(struct Student *students, int *c) {

  // read first line using scanf and assuming n<=MAXSIZE
  scanf("%d", c);

  //loop through number of students, 
  for (int i = 0; i < *c; i++) {
    //read the student's id
    scanf("%d", &students[i].student_ID);

    //read the student's 3 grades
    scanf("%d %d %d", &students[i].g1, &students[i].g2, &students[i].g3);

    //compute the student's average, prevent integer division
    students[i].average = (float)(students[i].g1 + students[i].g2 + students[i].g3) / 3;

    //print the student's values
    printf("%d %d %d %d %.2f\n", students[i].student_ID,students[i].g1,students[i].g2,students[i].g3,students[i].average);
  }
}
int main() {
  //declare an array of students of MAXSIZE
  struct Student students[MAXSIZE];

  // call readData, passing references
  // after coming back from the function, the array should be filled up and n will also get value.
  int n;
  readData(students, &n);

  //call getMaxAverageStudent and store result
  struct Student bestStudent = getMaxAverageStudent(students, n);

  //print the best student's result and ID
  printf("\nMaximum Average is %.2f and the student is %d\n", bestStudent.average, bestStudent.student_ID);

  return 0;
}
