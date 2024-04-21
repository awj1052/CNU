public class Practice {
	
	private final String input;
	
	public Practice(String input) {
		this.input = input;
	}
	
	public void practice() {
		ArrayStack<Character> stack = new ArrayStack<>(input.length());
		
		for(int i=0; i<input.length(); i++) {
			char c = input.charAt(i);
			if (c == ' ') {
				while (!stack.isEmpty()) {
					System.out.print(stack.pop());
				}
				System.out.print(" ");
				continue;
			}
			stack.push(c);
		}
		while (!stack.isEmpty()) {
			System.out.print(stack.pop());
		}
		System.out.println();
	}
}
