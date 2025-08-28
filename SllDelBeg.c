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

TNode* deleteAtBeginning(TNode *head) {
    TNode *temp = head;
    if(head == NULL) {
        printf("Linked list is Empty!\n");
        return head;
    }
    head = head->next;
    free(temp);
    return head;
}

int main() {
    TNode *head = NULL;
    head = CreateList();
    printList(head);
    printf("\nDeleting the first node...\n");
    head = deleteAtBeginning(head);
    printList(head);
    return 0;
}