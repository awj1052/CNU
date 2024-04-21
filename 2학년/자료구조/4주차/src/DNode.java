public class DNode {
	
	private Integer data;
	private DNode previous;
	private DNode next;

	public DNode(Integer data) {
		this.data = data;
	}
	
	public DNode getNext() {
		return next;
	}
	
	public void setNext(DNode next) {
		this.next = next;
	}

	public DNode getPrevious() {
		return previous;
	}
	
	public void setPrevious(DNode previous) {
		this.previous = previous;
	}
	
	public int getData() {
		return data;
	}
	
	public void setData(int data) {
		this.data = data;
	}
}