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

void push_last1(struck *stack1, int value) {
    if (stack1->next == NULL) {
        // First node with data
        stack1->next = malloc(sizeof(struck));
        stack1->next->value = value;
        stack1->next->next = NULL;
    } else {
        // Second or later node with data
        struck *current = stack1->next;
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


int main() {
    struck *head_node = NULL;
    head_node = malloc(sizeof(struck));

    // malloc test
    if (head_node == NULL)
        return 1;
    head_node->next = NULL;

    //  STACK 1

    struck *stack1 = NULL;
    stack1 = malloc(sizeof(struck));

   /* typedef struct nd {
        struct struck *node;
        int data;
    }node;*/

    int cyfra;
    printf("Podaj cyfry oddzielone enterem: ");
    do {
        scanf("%d", &cyfra);
        if (cyfra < 10) {
            push_last1(stack1, cyfra);
        }
    } while (cyfra < 10);

    printall(stack1);

    //  STACK 2

    //struck *root = malloc(sizeof(struck));
    //push_last(root, 1337);
    //push_last(root, 999);

    //printall(root);
    //exit(0);

    struck *stack2 = NULL;
    stack2 = malloc(sizeof(struck));

    //struck *stack2 = malloc(sizeof(struck));
    printf("\nPodaj cyfry oddzielone enterem: ");
    do {
        scanf("%d", &cyfra);
        if (cyfra < 10) {
            push_last(stack2, cyfra);
        }
    } while (cyfra < 10);

    printall(stack2);


    return 0;
}
