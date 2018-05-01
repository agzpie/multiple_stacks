#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
}struck;


void push_last(struck *head_node, int value) {
    if (head_node->next == NULL) {
        // First node with data
        head_node->next = malloc(sizeof(struck));
        head_node->next->value = value;
        head_node->next->next = NULL;
    } else {
        // Second or later node with data
        struck *current = head_node->next;
        while (current->next != NULL)
            current = current->next;

        current->next = malloc(sizeof(struck));
        current->next->value = value;
        current->next->next = NULL;
    }
}

void printall(struck *head_node) {
    struck *current = head_node->next;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
}

int pop_last(struck *head_node) {
    if (head_node->next == NULL) {
        return -1;
    }

    struck *current = head_node->next;
    struck *prev_current = head_node;
    while (current->next != NULL) {
        prev_current = current;
        current = current->next;
    }

    int ret = current->value;
    free(prev_current->next);
    prev_current->next = NULL;

    return ret;
}

void add_stack(struck *stos){
    printf("Podaj liczbe: ");
    char liczba[11];
    scanf("%s", liczba);
    int i=0;
    while (liczba[i]!=NULL) {
        int j=liczba[i]-48;
        push_last(stos, j);
        i++;
    }
}

int main() {
    //  STACK 1

    struck *stack1 = NULL;
    stack1 = malloc(sizeof(struck));
    // malloc test
    if (stack1 == NULL)
        return 1;
    stack1->next = NULL;

    add_stack(stack1);
    printf("otkgogno");
    printall(stack1);

   /* typedef struct nd {
        struct struck *node;
        int data;
    }node;*/
/*
    int cyfra;
    printf("Podaj cyfry oddzielone enterem: ");
    do {
        scanf("%d", &cyfra);
        if (cyfra < 10) {
            push_last1(stack1, cyfra);
        }
    } while (cyfra < 10);

    printall(stack1);
*/
    //  STACK 2

    //struck *root = malloc(sizeof(struck));
    //push_last(root, 1337);
    //push_last(root, 999);

    //printall(root);
    //exit(0);


    return 0;
}
