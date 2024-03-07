class Node{
    int data;
    Node next;
    Node(int data1){
        this.data = data1;
        this.next = null;
    }
    Node(int data1, Node next1){
        this.data = data1;
        this.next = next1;
    }
};
 
public class linked_list_{
    private static Node convArrToLinkedList(int a[]){
        Node head = new Node(a[0]);
        Node mover = head;
        for (int i = 1; i < a.length; i++){
            Node temp = new Node(a[i]);
            // create a link
            mover.next = temp;
            mover = mover.next; //or mover = temp;
        }
        return head;
    }
    // Printing the linked list
    private static void print(Node head){
        Node temp = head;
        while (temp != null){
            System.out.print((temp.data) + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    // length of the linked list
    private static int len_of_linked_list(Node head){
        Node temp = head;
        int cnt = 0;
        while (temp != null){
            cnt++;
            temp = temp.next;
        }
        return cnt;
    }
    // check the value is present or not
    private static boolean is_present(Node head, int val){
        Node temp = head;
        while (temp != null){
            if (temp.data == val) return true;
            temp = temp.next;
        }
        return false;
    }
    // Remove the first element of linked list
    private static Node remove_head(Node head){
        if (head == null) return head;
        head = head.next;
        return head;
    }
    // Remove the last element of linked list
    private static Node remove_tail(Node head){
        if (head == null || head.next == null) return null;
        Node temp = head;
        while (temp.next.next != null){
            temp = temp.next;
        }
        temp.next = null;
        return head;
    }
    // remove kth element in a linked list
    private static Node remove_kth_element(Node head, int k){
        if (head == null) return head;
        if (k == 1){
            remove_head(head);
        }
        int cnt = 0;
        Node temp = head;
        Node prev = null;
        while (temp != null){
            cnt++;
            if (cnt == k){
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
    // remove element from linked list
    private static Node remove_element(Node head, int ele){
        if (head == null) return head;
        if (head.data == ele){
            remove_head(head);
        }
        Node temp = head;
        Node prev = null;
        while (temp != null){
            if (temp.data == ele){
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
    // insert the value before first element
    private static Node insert_new_head(Node head, int val){
        Node temp = new Node(val, head);
        return temp;
        // return new Node(val, head); // we can do this as well
    }
    public static void main(String[] args) {
        int a[] = {12, 4, 5, 6, 8};
        Node head = convArrToLinkedList(a); // TC = O(n)
        // System.out.print(head.data);

        // Printing the linked list
        // Node temp = head;
        // while (temp != null){
        //     System.out.print(temp.data + " ");
        //     temp = temp.next;
        // }

        // length of the linked list
        // System.out.print(len_of_linked_list(head)); // TC = O(n)

        // check the value is present or not
        // System.out.println(is_present(head, 7));

        // Remove head
        // head = remove_head(head);
        // print(head); // 4 5 6 8

        // Remove tail or the last element of linked list
        // head = remove_tail(head);
        // print(head); // 12 4 5 6

        // Remove kth element in a linked list -> TC = O(k)
        // head = remove_kth_element(head, 3); // 12 4 6 8
        // head = remove_kth_element(head, 5); // 12 4 5 6 -> deleting last element
        // head = remove_kth_element(head, 8); // 11 3 5 2 8 5 -> it dos'n delete anything
        // print(head);

        // Remove element from the linked list -> TC = O(n)
        // head = remove_element(head, 4);
        // print(head); // 12 5 6 8

        // insert the value before first element
        head = insert_new_head(head, 100);
        print(head); // 100 12 4 5 6 8
    }
}

