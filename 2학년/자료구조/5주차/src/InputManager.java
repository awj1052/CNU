import java.io.*;
import java.util.ArrayList;

public class InputManager {
	
	public int[] getInt(String content) {
		String[] temp = content.split(" ");
		int[] res = new int[temp.length];
		for (int i=0; i<temp.length; i++) {
			res[i] = Integer.parseInt(temp[i]);
		}
		return res;
	}
	
	public ArrayList<String> getFileContents(String path) {
		ArrayList<String> res = new ArrayList<String>();
		try {
			File file = new File(path);
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			String line;
			while ((line = br.readLine()) != null) {
				res.add(line);
			}
			br.close();
			fr.close();
			return res;
		} catch (FileNotFoundException e) {
			System.out.println("FileNotFoundException");
		} catch (IOException e) {
			System.out.println("IOException");
		}
		return null;
	}
}
