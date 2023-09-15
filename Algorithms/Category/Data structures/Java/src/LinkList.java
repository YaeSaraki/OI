public class LinkList<T> {
  class Node {
    T item; // data
    Node next;// pointer
    public Node(T item) { // * Constructor 1
      this.item = item;
    }
    public Node(T item, Node next) { // * Constructor 2
      this.item = item;
      this.next = next;
    }
  }
  private Node head = null, tail = null;
  private int size = 0;
  public Node get(int index) { // * search the linklist
    if (index < 0 || index >= size) return null;
    else {
      Node temp = head;
      for (int i = 1; i <= index; ++i) temp = temp.next;
      return temp;
    }
  }
  public void add(T data) { // * add Node
    Node temp = new Node(data);
    if (size == 0) {
      head = temp;
      tail = head;
    } else {
      tail.next = temp;
      tail = temp;
    }
    ++size;
  }
  public void insert(int index, T data) throws Exception { // * insert data by index
    if (0 > index || index > size) throw new Exception("Out of index");
    Node newNode = new Node(data);
    if (index == 0) { // insert data at head
      if (size > 0) newNode.next = head;
      head = newNode;
    } else if (index == size) { // insert data at tail
      tail.next = newNode;
      tail = newNode;
    } else { // insert data normally
      Node preNode = get(index - 1);
      Node nextNode = preNode.next;
      preNode.next = newNode;
      newNode.next = nextNode;
    }
    ++size;
    if (size == 1) tail = head;
  }
  public void delete(int index) throws Exception {
    if (0 > index || index >= size) throw new Exception("Out of index");
    if (index == 0) { // delete data at head
      Node temp = head.next;
      head = temp;
    } else if (index == size - 1) {
      Node preNode = get(index - 1);
      tail = preNode;
      tail.next = null;
    } else { // delete data normally
      Node preNode = get(index - 1);
      Node nextNode = preNode.next.next;
      preNode.next = nextNode;
    }
    --size;
  }
  public void printLinkList() {
    if (size == 0) { System.out.print("linklist is empty!"); return ; }
    Node temp = head;
    System.out.print("head is : " + head.item + "\ntail is : " + tail.item + "\noverview : ");
    while (temp != null) {
      System.out.print(temp.item + " ");
      temp = temp.next;
    }
    System.out.print("\n");
    return ;
  }
  public static void main(String args[]) throws Exception {
    LinkList<Integer> ls = new LinkList<>();
    ls.add(0);
    ls.add(1);
    ls.delete(1);
    ls.insert(0, 233);
    ls.printLinkList();
    return ;
  }
}
