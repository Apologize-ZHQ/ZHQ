#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct LinkNode Node;

struct LinkNode {
    int data;
    Node *next;
};

Node *creat() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = INT_MAX;
    head->next = NULL;
    Node *temp = head;
    while (1) {
        int value;
        scanf("%d", &value);
        if (value == 0)
            break;
        Node *p = (Node *) malloc(sizeof(Node));
        p->data = value;
        p->next = NULL;
        temp->next = p;
        temp = p;

    }
    return head->next;
}

void printNode(Node *head) {
    if (!head)
        return;
    Node *temp = head;
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int lengthNode(Node *head) {
    if (!head)
        return 0;
    Node *temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }

    return length;
}

Node *findNode(Node *head, int index) {
    if (!head)
        return head;

    int len = lengthNode(head);

    if (index < 0 || index > len) {
        printf("the index is error\n");
        return NULL;
    }
    int count = 0;
    Node *temp = head;

    while (count < index && temp) {
        temp = temp->next;
        count++;
    }

    return temp;
}

Node *insertNode(Node *head, int index, int data) {
    if (!head) {
        head = (Node *) malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
    }
    Node *temp = head;

    while (--index) {
        temp = temp->next;
    }

    Node *p = (Node *) malloc(sizeof(Node));
    p->data = data;
    p->next = temp->next;
    temp->next = p;

    return head;
}

Node *deleteNode(Node *head, int index) {
    if (!head || !head->next)
        return NULL;
    int len = lengthNode(head);
    if (index >= len || index < 0) {
        printf("delete: the index is error\n");
        return head;
    }
    Node *temp = head;
    while (--index) {
        temp = temp->next;
    }
    Node *p = temp->next;
    temp->next = temp->next->next;
    free(p);
    p = NULL;
    return head;
}

Node *reverse(Node *head) {
    if (!head || !head->next) {
        return head;
    }

    Node *left = NULL;
    Node *curr = head;
    Node *right;

    while (curr) {
        right = curr->next;

        curr->next = left;
        left = curr;
        curr = right;
    }

    return left;
}

Node *findMid(Node *head) {
    if (!head || !head->next)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow= slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void test() {
    Node *head = creat();
    printNode(head);
    printf("%d\n", lengthNode(head));

    printNode(findMid(head));
    printNode(reverse(head));
}

int main() {
    test();
    return 0;
}
