import java.util.NoSuchElementException;

public class SinglyLinkedList {
	private Node head, tail;
	
	class Node {
		private int data;
		private Node next;
		
		Node(int data) {
			this.setData(data);
		}
		
		Node(int data, Node next) {
			this.setData(data);
			this.setNext(next);
		}

		public int getData() {
			return data;
		}

		public void setData(int data) {
			this.data = data;
		}

		public Node getNext() {
			return next;
		}

		public void setNext(Node next) {
			this.next = next;
		}
	}
	
	void insertLast(int x) {
		Node newNode = new Node(x);
		if (handleEmpty(newNode)) return;
		tail.setNext(newNode);
		tail = newNode;
	}
	
	void printall() {
		if (isEmpty()) {
			throw new NoSuchElementException();
		}
		Node p = head;
		while (p != null) {
			System.out.print(p.getData() + " ");
			p = p.getNext();
		}
		System.out.println();
	}

	void reverse() {
		if (isEmpty()) {
			throw new NoSuchElementException();
		}
		Node p = head;
		Node next = p.getNext();
		p.setNext(null);
		while (next != null) {
			Node temp = next.getNext();
			next.setNext(p);
			p = next;
			next = temp;
		}
		Node temp = head;
		head = tail;
		tail = temp;
	}
	
	private boolean handleEmpty(Node node) {
		if (isEmpty()) {
			head = node;
			tail = node;
			return true;
		}
		return false;
	}
	
	private boolean isEmpty() {
		return head == null;
	}
}
