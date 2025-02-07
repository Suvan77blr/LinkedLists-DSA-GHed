// LinkedList Solution Template : Java

class Node 
{
    int data;
    Node next;

    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
    Node(int data) {
        this(data, null);
    }
    Node() {
        this(0, null);
    }
}

// class Solution {
//     public static void main(String args[]) {
//         int[] arr = {10, 20, 30, 40};
//         Node list = new Node(arr[0]);
//         System.out.println(list.data);
//         System.out.println(list.next);
//     }
// }