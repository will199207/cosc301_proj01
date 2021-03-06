#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */
struct node {
	int i; 
	struct node *next;};


/* your function declarations associated with the list */
void append(int num, struct node** head);
struct node** parse_numbers(char *s, struct node **head);
void get_input(FILE * input);
void print_list(struct node **head);
void list_sort(struct node **head);
void swap(int first, int second); 
void print_stats();

#endif // __LIST_H__
