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

public class linked_list {
    public static void main(String[] args) {
        int arr[] = {1, 4, 6, 8};
        Node y = new Node(arr[3]);
        System.out.print(y.data);
    }
}