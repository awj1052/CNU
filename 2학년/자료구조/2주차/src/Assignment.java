public class Assignment {
	private final int[] inputs;
	
	public Assignment(int[] inputs) {
		this.inputs = inputs;
	}
	
	public void assignment() {
		int start = 0;
		int end = inputs.length - 1;
		while (start < end) {
			if (inputs[start]%2 == 1 && inputs[end]%2 == 0) {
				int temp = inputs[start];
				inputs[start] = inputs[end];
				inputs[end] = temp;
				start++; end--;
			} else {
				if (inputs[start]%2 == 0) {
					start++;
				}
				if (inputs[end]%2 == 1) {
					end--;
				}
			}
		}
		for (int item : inputs) {
			System.out.print(item + " ");
		}
		System.out.println();
	}
}
