program = PrintBigCharI

source_file = $(program).c
source_path = src
sources = $(source_path)/$(source_file)

object_file = $(program).o
object_path = build
objects = $(object_path)/$(object_file)

dist_file = $(program)
dist_path = dist
dist = $(dist_path)/$(dist_file)


Program: ProgramMid
	gcc -Wall -o $(dist) $(objects)
ProgramMid: ProgramSource
	gcc -Wall -o $(objects) -c $(sources)
ProgramSource: $(sources)

.PHONY:
clean:
	rm -rf $(dist) $(objects)
run:
	$(dist)