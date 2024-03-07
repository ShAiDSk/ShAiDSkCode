#include <bits/stdc++.h>
using namespace std;
#define nln '\n'

class Node{
public:
    int data;
    Node *next;
public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
};

Node *convArrToLinkedList(vector <int> &a){
    Node *head = new Node(a[0]);
    Node *mover = head;
    for (int i = 1; i < a.size(); i++){
        Node *temp = new Node(a[i]);
        // create a link
        mover -> next = temp;
        mover = mover->next; //or mover = temp;
    }
    return head;
}

// length of the linked list
int len_of_linked_list(Node *head){
    Node *temp = head;
    int cnt = 0;
    while (temp){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}

// check the value is present or not
bool is_present(Node *head, int val){
    Node *temp = head;
    while (temp){
        if (temp -> data == val) return true;
        temp = temp -> next;
    }
    return false;
}

// Printing the linked list
void print(Node *head){
    Node *temp = head;
    while (temp){
        cout << (temp -> data) << ' ';
        temp = temp -> next;
    }
    cout << nln;
}
// Remove the first element of linked list
Node *remove_head(Node *head){
    if (head == NULL) return head;
    Node *temp = head;
    head = head -> next;
    delete temp; // free(temp);
    // free(temp);
    return head;
}
// Remove the last element of linked list
Node *remove_tail(Node *head){
    if (head == NULL || head -> next == NULL) return NULL;
    Node *temp = head;
    while (temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete temp; // free(temp);
    temp -> next = nullptr;
    return head;
}
// remove kth element in a linked list
Node *remove_kth_element(Node *head, int k){
    if (head == NULL) return head;
    if (k == 1){
        remove_head(head);
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL){
        cnt++;
        if (cnt == k){
            prev -> next = prev -> next -> next;
            free(temp); // delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
// remove element from linked list
Node *remove_element(Node *head, int ele){
    if (head == NULL) return head;
    if (head -> data == ele){
        remove_head(head);
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL){
        if (temp -> data == ele){
            prev -> next = prev -> next -> next;
            free(temp); // delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
// insert the value before first element
Node *insert_new_head(Node *head, int val){
    Node *temp = new Node(val, head);
    return temp;
    // return new Node(val, head); // we can do this as well
}
int main(){
    vector<int> a = {11, 3, 5, 2, 8, 5};
    Node *head = convArrToLinkedList(a);
    // cout << (head -> data) << nln;

    // Printing the linked list
    // Node *temp = head;
    // while (temp){
    //     cout << (temp -> data) << ' ';
    //     temp = temp -> next;
    // }

    // length of linked list
    // cout << (len_of_linked_list(head)) << nln; // TC = O(n)

    // check the value is present or not
    // cout << (is_present(head, 7)) << nln; // TC = O(n)

    // Remove head
    // head = remove_head(head);
    // print(head);

    // Remove tail or the last element of linked list
    // head = remove_tail(head);
    // print(head); // 11 3 5 2 8

    // Remove kth element in a linked list
    // head = remove_kth_element(head, 3); // 11 3 2 8 5
    // head = remove_kth_element(head, 5); // 11 3 5 2 5 -> deleting second last element
    // head = remove_kth_element(head, 6); // 11 3 5 2 8 -> deleting last element
    // head = remove_kth_element(head, 8); // 11 3 5 2 8 5 -> it dos'n delete anything
    // print(head);

    // Remove element from the linked list
    // head = remove_element(head, 3); // 11 5 2 8 5
    // head = remove_element(head, 5); // 11 3 2 8 5 
    // head = remove_element(head, 8); // 11 3 5 2 5
    // head = remove_element(head, 6); // 11 3 5 2 8 5
    // print(head);

    // insert the value before first element -> TC = O(1)
    // head = insert_new_head(head, 100);
    // print(head); // 100 11 3 5 2 8 5
    return 0;
}