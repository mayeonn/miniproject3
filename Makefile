CC = gcc
CFLAGS = -W -Wall 
TARGET = test

OBJECTS = p_main.c product.o manager.o 
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
clean :
	rm *.o test

