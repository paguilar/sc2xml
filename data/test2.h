/*
 * test2.h: Example with the most common cases
 */ 

typedef struct { 
	/* Simple */
	char c1;
	my_type x4;

	/* Bit */
	unsigned int x1:7;
	int x3:3;
	my_type x2:3;

	/* Pointers */
	char * ptr1;
	char **ptr2;
	my_type *ptr3;
	my_type **ptr4;

	/* Arrays */
	char array1 [5];
	const char array2 [NUM];
	my_datatype *array3 [2];
	int raw[(BUTTONS_NUMBER / 8) + 1]; 
	struct section_buf * poll_section_bufs[SIL];

	/* Structs */
	struct chido_st chido;

	/* Nested structs */
	struct nested_struct{
		int a1;
		unsigned short a2;
		float a3;
		char *a4;
	} hola[10];

	/* Function pointers */
	int (*func)(int, char *);
	int (*func2)(char chido[10], int);
	void (*func3)(struct buttons_pressure* event);
	my_type (*func4)(struct buttons_pressure* event);
	my_type * (*func5)(int *another, struct buttons_pressure* event);

} my_st;

struct buttons_driver_data
{
	char status;
};

