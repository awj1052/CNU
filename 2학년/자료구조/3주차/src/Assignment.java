public class Assignment {
	private final int[] inputs;
	
	public Assignment(int[] inputs) {
		this.inputs = inputs;
	}
	
	public void practice() {
		SinglyLinkedList SList = new SinglyLinkedList();
		for (int e : inputs) {
			SList.insertLast(e);
		}
		SList.printall();
		SList.reverse();
		SList.printall();
	}
}
