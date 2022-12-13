CC = gcc
INC = include
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -g -Wall

LDFLAGS = -o

IFLAGS = -I $(INC)


all: main

main: $(OBJ)/main.o $(OBJ)/user.o $(OBJ)/admin.o $(OBJ)/auction.o $(OBJ)/common.o $(OBJ)/item.o $(OBJ)/message.o $(OBJ)/sales.o
	$(CC) $(LDFLAGS) $(BIN)/main $(OBJ)/main.o $(OBJ)/user.o $(OBJ)/admin.o $(OBJ)/auction.o $(OBJ)/common.o $(OBJ)/item.o $(OBJ)/message.o $(OBJ)/sales.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/user.o: $(SRC)/user.c
	$(CC) $(CFLAGS) $(SRC)/user.c $(IFLAGS)
	mv user.o $(OBJ)/

$(OBJ)/admin.o: $(SRC)/admin.c
	$(CC) $(CFLAGS) $(SRC)/admin.c $(IFLAGS)
	mv admin.o $(OBJ)/

$(OBJ)/auction.o: $(SRC)/auction.c
	$(CC) $(CFLAGS) $(SRC)/auction.c $(IFLAGS)
	mv auction.o $(OBJ)/


$(OBJ)/common.o: $(SRC)/common.c
	$(CC) $(CFLAGS) $(SRC)/common.c $(IFLAGS)
	mv common.o $(OBJ)/
    
$(OBJ)/item.o: $(SRC)/item.c
	$(CC) $(CFLAGS) $(SRC)/item.c $(IFLAGS)
	mv item.o $(OBJ)/

$(OBJ)/sales.o: $(SRC)/sales.c
	$(CC) $(CFLAGS) $(SRC)/sales.c $(IFLAGS)
	mv sales.o $(OBJ)/
	
$(OBJ)/message.o: $(SRC)/message.c
	$(CC) $(CFLAGS) $(SRC)/message.c $(IFLAGS)
	mv message.o $(OBJ)/
	
clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
