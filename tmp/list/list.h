#ifndef __LIST__
#include <stdio.h>
#include <stdlib.h>

//talbe : single linked list
typedef struct PA_table
{
	struct PA_table *next;
	int address;
    int target;
} PA_table;


//useless?
static __inline PA_table* INIT_TABLE()
{
	//it points itself
	PA_table *head = (PA_table*)malloc(sizeof(PA_table));
	head->next = NULL;
	head->address = 0;
	head->target = 0;
    return head;
}


	
static __inline int PULL_TABLE(PA_table* head, int pull_address)
{
	PA_table *c_table = head->next;
	PA_table *p_table = NULL;
    int pull_target=0;
	
	while(c_table != NULL)
	{
		if(c_table->address == pull_address)
		{
			//first table
			if(p_table == NULL)
				head->next = c_table->next;
			else
				p_table->next = c_table->next;
            pull_target = c_table->target;
			free(c_table);
            return pull_target;
		}
		p_table = c_table;
		c_table = c_table->next;
	}
	return pull_target;
}

//add to head
static __inline void ADD_TABLE(PA_table *head, int new_address, int new_target)
{
	PA_table *new_table = (PA_table*)malloc(sizeof(PA_table));
	new_table->address = new_address;
	new_table->target = new_target;

    //delete(pul) table if address already exists
    PULL_TABLE(head, new_address);
    
	// first table
	// it will be tail
	if(head->next == NULL)
	{
        //printf("first table\n");
		head->next = new_table;
		new_table->next = NULL;
	}
	else
	{
		new_table->next = head->next;
		head->next = new_table;
	}
}

#endif
