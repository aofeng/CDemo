source_path = src/array
program = array

source_file = $(program).c
sources = $(source_path)/$(source_file)

object_file = $(program).o
object_path = build
objects = $(object_path)/$(object_file)

dist_file = $(program)
dist_path = dist
dist = $(dist_path)/$(dist_file)

all: Compile
	gcc -Wall --std=c99 -g -o $(dist) $(objects)
Compile: Source
	gcc -Wall --std=c99 -g -o $(objects) -c $(sources)
Source: $(sources)

.PHONY:
clean:
	rm -rf $(dist) $(objects)
run:
	$(dist)