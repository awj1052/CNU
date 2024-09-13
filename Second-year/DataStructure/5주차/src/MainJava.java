import java.util.ArrayList;

public class MainJava {

	public static void main(String[] args) {
		Practice practice = new Practice("I go to school");
		practice.practice();
		InputManager inputManager = new InputManager();
		ArrayList<String> inputs = inputManager.getFileContents("input.txt");
		for (String item : inputs) {
			int[] input = inputManager.getInt(item);
			Assignment assignment = new Assignment(input);
			assignment.assignment();
		}
	}
}
