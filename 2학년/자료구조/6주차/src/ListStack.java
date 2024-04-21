import java.util.EmptyStackException;

public class ListStack<E> {
	
	private Node<E> top;
	private int size;
	
	public ListStack() {
		top = null;
		size = 0;
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public void push(E newItem) {
		Node<E> newNode = new Node<>(newItem, top);
		top = newNode;
		size++;
	}
	
	public E peek() {
		if (isEmpty()) throw new EmptyStackException();
		return top.getData();
	}
	
	public E pop() {
		if (isEmpty()) throw new EmptyStackException();
		E topItem = top.getData();
		top = top.getNext();
		size--;
		return topItem;
	}
}
