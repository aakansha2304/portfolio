#include <iostream>
using namespace std;

struct node1 {
    int data1;
    struct node1* ptr1;
};

struct node2 {
    int data2;
    struct node2* ptr2;
};

// Function to display the list1
void display1(struct node1* l) {
    while (l != NULL) {
        cout << l->data1 << "  ";
        l = l->ptr1;
    }
}

// Function to display the list2
void display2(struct node2* l) {
    while (l != NULL) {
        cout << l->data2 << "  ";
        l = l->ptr2;
    }
}

// Function to merge two sorted linked lists
node1* mergeLists(node1* list1, node2* list2) {
    // Create a new head pointer for the merged list
    node1* mergedList = NULL;
    node1* tail = NULL;

    // Loop through both lists and merge them in sorted order
    while (list1 != NULL && list2 != NULL) {
        node1* newNode = new node1;
        if (list1->data1 <= list2->data2) {
            newNode->data1 = list1->data1;
            newNode->ptr1 = NULL;
            list1 = list1->ptr1;
        } else {
            newNode->data1 = list2->data2;
            newNode->ptr1 = NULL;
            list2 = list2->ptr2;
        }

        // Attach newNode to the merged list
        if (mergedList == NULL) {
            mergedList = newNode;
            tail = mergedList;
        } else {
            tail->ptr1 = newNode;
            tail = tail->ptr1;
        }
    }

    // Add remaining elements from list1
    while (list1 != NULL) {
        node1* newNode = new node1;
        newNode->data1 = list1->data1;
        newNode->ptr1 = NULL;
        tail->ptr1 = newNode;
        tail = tail->ptr1;
        list1 = list1->ptr1;
    }

    // Add remaining elements from list2
    while (list2 != NULL) {
        node1* newNode = new node1;
        newNode->data1 = list2->data2;
        newNode->ptr1 = NULL;
        tail->ptr1 = newNode;
        tail = tail->ptr1;
        list2 = list2->ptr2;
    }

    return mergedList;
}

int main() {
    struct node1 *temp1, *p1, *list1 = NULL;
    struct node2 *temp2, *p2, *list2 = NULL;

    // Creating the first sorted linked list (list1)
    cout << "Elements For List 1 : " << endl;
    temp1 = (struct node1*)malloc(sizeof(struct node1));
    cout << "Enter Ele: ";
    cin >> temp1->data1;
    temp1->ptr1 = NULL;
    list1 = temp1;
    p1 = list1;
    for (int i = 0; i < 3; i++) {
        temp1 = (struct node1*)malloc(sizeof(struct node1));
        cout << "Enter Ele: ";
        cin >> temp1->data1;
        temp1->ptr1 = NULL;
        p1->ptr1 = temp1;
        p1 = p1->ptr1;
    }

    // Creating the second sorted linked list (list2)
    cout << endl << "Elements For List 2 : " << endl;
    temp2 = (struct node2*)malloc(sizeof(struct node2));
    cout << "Enter Ele: ";
    cin >> temp2->data2;
    temp2->ptr2 = NULL;
    list2 = temp2;
    p2 = list2;
    for (int i = 0; i < 3; i++) {
        temp2 = (struct node2*)malloc(sizeof(struct node2));
        cout << "Enter Ele: ";
        cin >> temp2->data2;
        temp2->ptr2 = NULL;
        p2->ptr2 = temp2;
        p2 = p2->ptr2;
    }

    // Display elements of both lists
    cout << "Elements of List 1: ";
    display1(list1);
    cout << endl << "Elements of List 2: ";
    display2(list2);
    cout << endl;

    // Merge the two sorted lists
    node1* mergedList = mergeLists(list1, list2);

    // Display the merged list
    cout << "Merged List: ";
    display1(mergedList);
    cout << endl;

    return 0;
}