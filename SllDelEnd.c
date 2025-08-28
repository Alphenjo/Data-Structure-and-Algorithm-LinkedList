#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} TNode;

TNode* CreateList() {
    TNode *head = NULL, *Newnode, *temp;
    int val;
    printf("Enter data (-1 to stop): ");
    scanf("%d", &val);

    while(val != -1) {
        Newnode = (TNode*) malloc(sizeof(TNode));
        if(Newnode == NULL) {
            printf("Process Failed!\n");
            return head;
        }
        Newnode->data = val;
        Newnode->next = NULL;

        if(head == NULL) {
            head = Newnode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = Newnode;

        }
        printf("Enter data (-1 to stop): ");
        scanf("%d", &val);
    }
    return head;
}

void printList(TNode *head) {
    printf("\nLinked List: HEAD =-= ");
    while(head != NULL) {
        printf("%d =-= ", head->data);
        head = head->next;
    }
    printf("END\n");
}

void deleteAtEnding(TNode** head) {
    TNode* temp = *head;
    TNode* temp2 = temp;

    while(temp->next != NULL ) {
        temp2 = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp2->next = NULL;
    free(temp);
}

int main() {
    TNode *head = NULL;
    head = CreateList();
    printList(head);
    printf("\nDeleting node at the end...\n");
    deleteAtEnding(&head);
    printList(head);
    return 0;
}