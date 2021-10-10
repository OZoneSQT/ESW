// init item-"object" as a datatype - declared in header file
typedef struct Item item;

// anonymous union inside a struct
struct Item
{
	union
	{
		int number;
		char* string;
	};
};