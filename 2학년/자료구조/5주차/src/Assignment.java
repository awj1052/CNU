public class Assignment {
	private final int[] inputs;
	
	public Assignment(int[] inputs) {
		this.inputs = inputs;
	}
	
	public void assignment() {
		ArrayStack<Integer> A = new ArrayStack<>(50);
		ArrayStack<Integer> B = new ArrayStack<>(50);
		
		for (int e : inputs) {
			while (!A.isEmpty() && A.peek() < e) {
				B.push(A.pop());
			}
			A.push(e);
			while (!B.isEmpty()) {
				A.push(B.pop());
			}
		}
		while (!A.isEmpty()) {
			B.push(A.pop());
		}
		while(!B.isEmpty()) {
			System.out.print(B.pop() + " ");
		}
		System.out.println();
	}
}
