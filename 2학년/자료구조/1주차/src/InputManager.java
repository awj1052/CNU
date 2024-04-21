import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class InputManager {
	
	public int[] getContents(String path) {
		String[] contents = getFileContents(path).split(" ");
		int[] inputs = new int[contents.length];
		for (int i=0; i<contents.length; i++) {
			inputs[i] = Integer.parseInt(contents[i]);
		}
		return inputs;
	}
	
	private String getFileContents(String path) {
		try {
			File file = new File(path);
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			String line = br.readLine();
			br.close();
			return line;
		} catch (FileNotFoundException e) {
			System.out.println("FileNotFoundException");
		} catch (IOException e) {
			System.out.println("IOException");
		}
		return null;
	}
}
