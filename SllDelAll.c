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

void deleteEntireList(TNode **head) {
    TNode *current = *head;
    TNode *nextNode;
    while(current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    printf("Entire linked list deleted.\n");
}

int main() {
    TNode *head = NULL;
    head = CreateList();
    printList(head);
    printf("\nDeleting entire linked list...\n");
    deleteEntireList(&head);
    printList(head); // This should print "END" only, as the list is now empty
    return 0;
}
