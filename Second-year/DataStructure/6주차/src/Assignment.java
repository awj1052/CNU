public class Assignment {
	
	private final String[] inputs;
	
	public Assignment(String[] inputs) {
		this.inputs = inputs;
	}
	
	public void assignment() {
		ListStack<String> stack = new ListStack<>();
		
		for (int i=0; i<inputs.length; i++) {
			String temp = inputs[i];
			
			if (!isOperator(temp)) {
				System.out.print(temp + " ");
				continue;
			}
			
			while (!stack.isEmpty() 
					&& in_priority(stack.peek()) >= out_priority(temp)) {
				String pop = stack.pop();
				if (pop.equals("(")) break;
				System.out.print(pop + " ");
			}
			if (temp.equals(")")) continue;
			stack.push(temp);			
		}
		
		while(!stack.isEmpty()) {
			System.out.print(stack.pop() + " ");
		}
		System.out.println();
	}
	
	private boolean isOperator(String st) {
		return priority(st) != -1;
	}
	
	private int in_priority(String operator) {
		return operator.equals("(") ? 0 : priority(operator);
	}
	
	private int out_priority(String operator) {
		return priority(operator);
	}
	
	private int priority(String operator) {
		if (operator.equals("+")) return 8;
		if (operator.equals("-")) return 8;
		if (operator.equals("*")) return 9;
		if (operator.equals("/")) return 9;
		if (operator.equals("(")) return 10;
		if (operator.equals(")")) return 0;
		return -1;
	}	
}
