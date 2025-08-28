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

void insertAfterNode(TNode** head, int targetValue, int data) {
    TNode* temp = *head,*Newnode;

    while(temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node with value %d not found.\n", targetValue);
        return;
    }
    Newnode = (TNode*) malloc(sizeof(TNode));
    if(Newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    Newnode->data = data;
    Newnode->next = temp->next;
    temp->next = Newnode;
}

int main() {
    TNode *head = NULL;
    head = CreateList();
    printList(head);
    int targetValue, data;
    printf("\nEnter the value of the node after which to insert: ");
    scanf("%d", &targetValue);
    printf("Enter data to insert after node with value %d: ", targetValue);
    scanf("%d", &data);
    insertAfterNode(&head, targetValue, data);
    printList(head);
    return 0;
}