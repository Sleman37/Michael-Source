#all: words#map #limits

all: main.o word_count.o wc_sort.o
	gcc -g main.o word_count.o wc_sort.o -o words
main.o: main.c
	gcc -g -c main.c -o main.o
word_count.o: word_count.c
	gcc -g -c word_count.c -o word_count.o


#prog2: main.o factorial.o
#	gcc -g main.o factorial.o -o prog2
#main.o: main.c
#	gcc -g -c main.c -o main.o
#factorial.o: factorial.c
#	gcc -g -c factorial.c -o factorial.o

clean:
	rm main.o  word_count.o words