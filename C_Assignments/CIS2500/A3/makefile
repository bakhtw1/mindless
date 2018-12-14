all: init_aim register sort schedule add class_schedule class_list grade report

# aim.c file
aim.o: aim.c aim.h
	gcc -Wall -ansi -pedantic -c aim.c -o aim.o

# init_aim
init_aim.o: init_aim.c aim.h
	gcc -Wall -ansi -pedantic -c init_aim.c -o init_aim.o

init_aim: init_aim.o aim.o
	gcc -Wall -pedantic init_aim.o aim.o -o init_aim

# register
register.o: register.c aim.h 
	gcc -Wall -ansi -pedantic -c register.c -o register.o

register: register.o aim.o
	gcc -Wall -pedantic register.o aim.o -o register

# sort
sort.o: sort.c aim.h
	gcc -Wall -ansi -pedantic -c sort.c -o sort.o

sort: sort.o aim.o
	gcc -Wall -pedantic sort.o aim.o -o sort

# schedule
schedule.o: schedule.c aim.h
	gcc -Wall -ansi -pedantic -c schedule.c -o schedule.o

schedule: schedule.o aim.o
	gcc -Wall -pedantic schedule.o aim.o -o schedule

# add
add.o: add.c aim.h
	gcc -Wall -ansi -pedantic -c add.c -o add.o

add: add.o aim.o
	gcc -Wall -pedantic add.o aim.o -o add
 
# class_schedule
class_schedule.o: class_schedule.c aim.h
	gcc -Wall -ansi -pedantic -c class_schedule.c -o class_schedule.o

class_schedule: class_schedule.o aim.o
	gcc -Wall -pedantic class_schedule.o aim.o -o class_schedule

# class_list
class_list.o: class_list.o aim.h
	gcc -Wall -ansi -pedantic -c class_list.c -o class_list.o

class_list: class_list.o aim.o
	gcc -Wall -pedantic class_list.o aim.o -o class_list

# grade
grade.o: grade.c aim.h
	gcc -Wall -ansi -pedantic -c grade.c -o grade.o

grade: grade.o aim.o
	gcc -Wall -pedantic grade.o aim.o -o grade

# report
report.o: report.c aim.h
	gcc -Wall -ansi -pedantic -c report.c -o report.o

report: report.o aim.o
	gcc -Wall -pedantic report.o aim.o -o report
