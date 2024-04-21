import java.util.ArrayList;

public class MainJava {

	public static void main(String[] args) {
		InputManager inputManager = new InputManager();
		ArrayList<String> inputs = inputManager.getFileContents("input.txt");
		for (String item : inputs) {
			int[] input = inputManager.getInt(item);
			Assignment assignment = new Assignment(input);
			assignment.assignment();
		}
	}
}
