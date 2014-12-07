all: fire_emp
fire_emp: fire_emp.o utils.o
	gcc --std=c99 -lm -o fire_emp fire_emp.o utils.o
fire_emp.o: fire_emp.c
		gcc --std=c99 -c -lm fire_emp.c
utils.o: utils.c
		gcc --std=c99 -c -lm utils.c
clean: 
	rm -rf *.o fire_emp


