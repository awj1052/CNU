import java.util.NoSuchElementException;

public class CDList {
	
	protected DNode head;
	protected int size;
	
	public void insert(int newItem) {
		DNode newNode = new DNode(newItem);
		if (isEmpty()) {
			head = newNode;
			head.setPrevious(head);
			head.setNext(head);
			size = 1;
			return;
		}
		DNode previous = head.getPrevious();
		previous.setNext(newNode);
		head.setPrevious(newNode);
		newNode.setNext(head);
		newNode.setPrevious(previous);
		head = newNode;
		size++;
	}
	
	public void printall() {
		if (isEmpty()) {
			throw new NoSuchElementException();
		}
		DNode p = head;
		for(int i=0; i<size; i++) {
			System.out.print(p.getData() + " ");
			p = p.getNext();
		}
		System.out.println();
	}
	
	public void delete() {
		if (isEmpty()) return;
		DNode target = head.getPrevious();
		DNode previous = target.getPrevious();
		previous.setNext(head);
		head.setPrevious(previous);
		target.setNext(null);
		target.setPrevious(null);
		size--;
		if (size == 0) head = null;
	}
	
	public boolean isEmpty() {
		return head == null;
	}
}
