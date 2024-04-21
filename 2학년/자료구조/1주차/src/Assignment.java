public class Assignment {
	private final int[] arr;
	
	public Assignment(int[] inputs) {
		arr = inputs;
	}
	
	public void print_pathA(int target) {
		System.out.print(target + " ");
		if(arr[target] == 0) {
			System.out.print(0 + " ");
			return;
		}
		print_pathA(arr[target]);
	}
	
	public void print_pathB(int target) {
		if (arr[target] == 0) {
			System.out.print("0 " + target + " ");
			return;
		}
		print_pathB(arr[target]);
		System.out.print(target + " ");
	}
}
