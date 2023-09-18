run: compile
	@./main

compile: main
	@gcc  -o   main *.o -lsqlite3

main: library
	@gcc -c -g  main.c main.h 

library:
	@gcc -c -g   addTask/*.c addTask/*.h initDB/*.c initDB/*.h showTask/*.c showTask/*.h editTask/*.c editTask/*.h deleteTask/*.c deleteTask/*.h   task.h

clean:
	@rm main .*.swp .*/*.swp *.h.gch */*h.gch *.o .*.c.swp .*/*.c.swp

push: commit
	git push

commit: add
	git commit -m "$(M)"

add: pull
	git add .

pull: fetch
	git pull

fetch:
	git fetch