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

void add_stack(struck *stos) {
    printf("Podaj liczbe: ");
    char liczba[11];
    scanf("%s", liczba);
    int i = 0;
    while (liczba[i] != NULL) {
        int j = liczba[i] - 48;
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
    printall(stack1);
    printf("it worked\n");

    // STACK 2
    struck *stack2 = NULL;
    stack2 = malloc(sizeof(struck));
    // malloc test
    if (stack2 == NULL)
        return 1;
    stack2->next = NULL;

    add_stack(stack2);
    printall(stack2);
    printf("it worked again\n");

    //STACK 3
    struck *stack3 = NULL;
    stack3 = malloc(sizeof(struck));
    // malloc test
    if (stack3 == NULL)
        return 1;
    stack3->next = NULL;

    add_stack(stack3);
    printall(stack3);
    printf("good job\n");

    //STACK 4: THE RESULT

    struck *result = NULL;
    result = malloc(sizeof(struck));
    // malloc test
    if (result == NULL)
        return 1;
    result->next = NULL;

    // TODO

    int sum=0;
    int extra=0;
    //do {
        sum = pop_last(stack1) + pop_last(stack2) + pop_last(stack3);
        if (sum > 9) {
            extra = sum%10;
            sum = sum/10;
        }
        push_last(result, sum);



    //}while();
    printall(result);




    return 0;
}
