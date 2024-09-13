import java.util.ArrayList;

public class MainJava {

	public static void main(String[] args) {
		InputManager inputManager = new InputManager();
		ArrayList<String> inputs = inputManager.getFileContents("input.txt");
		for (String item : inputs) {
			String[] input = item.split(" ");
			Assignment assignment = new Assignment(input);
			assignment.assignment();
		}
	}
}
