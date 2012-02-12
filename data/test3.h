/*
 * test3.h: Nested struct with attributes and macros that define structs
 */

/* Struct with attributes */
struct my_st { 
	/* Nested struct */
	struct nested_struct{
		int a1; 
		unsigned short a2; 
	} nested_st;

	/* Another nested struct */
	struct nested_attr_struct {
		int a1; 
		unsigned short a2; 
	} nested_attr_st;

} __attribute__((packed));

/* Structs defined inside a macro */
#define def_struct_data(prefix,number,code_number)\
\
struct prefix##buttons_event\
{\
  struct prefix##buttons_mask mask;\
  uint8_t code;\
  Bool pressed :1;\
}__attribute__((packed));\
\
struct prefix##driver_data\
{\
  task_status_t tsk_sts;\
\
  struct buttons_platform_data pdata[number];\
  struct prefix##an_event event;\
\
  struct prefix##buttons_settings\
  {\
    uint8_t thresholds[3];\
    uint8_t pressed_threshold;\
    struct prefix##buttons_mask hash_table[code_number];\
  }__attribute__((packed)) settings;\
\
  uint8_t raw[((number) / 8) + 1];\
  uint8_t raw_mem[((number) / 8) + 1];\
\
}__attribute__((packed));

