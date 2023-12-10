SRC = $(wildcard *.c) #tout les fichiers .c affiché en faisant make debuf dans le terminal
OBJ = $(SRC:.c=.o)
INC = $(wildcard *.h)

all : exec

#première façon de faire le Makefile
liste_chainee.o : liste_chainee.c liste_chainee.h
	gcc -c liste_chainee.c -o liste_chainee.o

FonctionABR.o : FonctionABR.c FonctionABR.h
	gcc -c FonctionABR.c -o FonctionABR.o

hashmap.o : hashmap.c hashmap.h
	gcc -c $< -o $@

main.o : main.c $(INC)
	gcc -c $< -o $@

exec : $(OBJ)
	gcc $^ -o $@


#deuxième façon
#%.o : %.c $(INC)
#	gcc -c $< -o $@
#exec : $(OBJ)
#	gcc $^ -o $@

#permet de supprimer les fichiers inutile lors de la recompilation
clean : 
	rm -f *.o
	rm -f exec

debug :
	@echo $(SRC)	
	@echo $(OBJ)	
