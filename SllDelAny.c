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

void deleteNode(TNode** head, int targetValue) {
    TNode* temp = *head;
    TNode* temp2 = temp;

    while(temp != NULL && temp->data != targetValue) {
        temp2 = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node with value %d not found.\n", targetValue);
        return;
    }

    temp2->next = temp->next;
    free(temp);
}

int main() {
    TNode *head = NULL;
    head = CreateList();
    printList(head);
    int targetValue;
    printf("\nEnter the value of the node which to delete: ");
    scanf("%d", &targetValue);
    deleteNode(&head, targetValue);
    printList(head);
    return 0;
}