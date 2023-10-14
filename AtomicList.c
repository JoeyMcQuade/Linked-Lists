/*
Periodic table list
Code prints an inputed number of elements from the periodic table (up to 10)
Created by Joey McQ
*/

#include <stdio.h>
#include <stdlib.h>

//initiaslises the adt needed for the code.
int weight;
typedef enum name{hydrogen, helium, lithium, beryllium, boron, carbon, nitrogen, oxygen, fluorine, neon} name;
struct elements{enum name name; double weight;};

//initialises the linked list
typedef struct list{
    struct elements e;
    struct list * next;
} table;

int is_empty(const table *l){return(l == NULL);}

table* create_element_list(struct elements element){
    //builds the new head of a list
    table* head = malloc(sizeof(table));
    head ->e = element;
    head ->next = NULL;
    return head;
}

table* add_element(struct elements element, table* h){
    // adds a new element at the head of the list.
    table* head = create_element_list(element);
    head ->next = h;
    return head;
}

struct elements build_element(int i){
    //Gives the element an atomic weight based on its name.
    struct elements element;
    element.name = i;
    switch(i){
        case 0: element.weight = 1.008; break;
        case 1: element.weight = 4.0026; break;
        case 2: element.weight = 6.94; break;
        case 3: element.weight = 9.0122; break;
        case 4: element.weight = 10.81; break;
        case 5: element.weight = 12.011; break;
        case 6: element.weight = 14.007; break;
        case 7: element.weight = 15.999; break;
        case 8: element.weight = 18.998; break;
        case 9: element.weight = 20.990; break;
    }
    return element;
}

void print_table(struct elements element, int i){
    //prints the table from the list
    if(i==0){
        printf("\nName\t \tSymbol\t Atmoic Weight\n");
    }
    switch(element.name){
        case 0: printf("Hydrogen\tH\t %lf\n", element.weight); break;
        case 1: printf("Helium\t \tHe\t %lf\n", element.weight); break;
        case 2: printf("Lithium\t \tLi\t %lf\n", element.weight); break;
        case 3: printf("Beryllium\tBe\t %lf\n", element.weight); break;
        case 4: printf("Boron\t \tB\t %lf\n", element.weight); break;
        case 5: printf("Carbon\t \tC\t %lf\n", element.weight); break;
        case 6: printf("Nitrogen\tN\t %lf\n", element.weight); break;
        case 7: printf("Oxygen\t \tO\t %lf\n", element.weight); break;
        case 8: printf("Fluorine\tF\t %lf\n", element.weight); break;
        case 9: printf("Neon\t \tNe\t %lf\n", element.weight); break;
    }
}

table * reverse(table * head){
    /*Reverse the order of a linked list*/
    //initialise next, current and prev local pointer variables 
    table * current = head;
    table * prev = NULL, * next = NULL;
    while(current != NULL){
        next = current -> next; //store next
        current -> next = prev; // Reverse current next pointer to prev 
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main(void){
    //Main code blocks that runs the functions in order to produce the linked list and print the table
    int num_elements=10, i=0, x=0;
    struct elements element;
    struct list* table;
    //Input that specifies the number of elements that should be printed.
    printf("How many Elements would you like to list? (No more than 10)\n");
    scanf("%d", &num_elements);
    for(i=0;i<num_elements;i++){
        //builds the list to the length specified from the input
        element = build_element(i);
        if(i==0){
            table = create_element_list(element);
        }
        else{
            table = add_element(element, table);
        }
    }
    table = reverse(table);
    while(table!=NULL){
        //prints each element in the list until the link = null meaning the list has ended
        print_table(table->e, x);
        table = table -> next;
        x++;
    }
    printf("\n");
    return 0;
}
