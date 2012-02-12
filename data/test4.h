/*
 * test4.h: Unsupported structs!!!
 */ 

/* Fails: typedef + __attribute__ */
typedef struct { 
	int a1; 
	unsigned short a2; 
} __attribute__((packed)) chido_st;

