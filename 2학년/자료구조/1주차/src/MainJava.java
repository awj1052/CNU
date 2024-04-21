public class MainJava {

	public static void main(String[] args) {
		InputManager inputManager = new InputManager();
		int[] inputs = inputManager.getContents("input.txt");
		Assignment assignment = new Assignment(inputs);
		assignment.print_pathA(0);
	}
}
