public class Assignment {
	private final String[] inputs;
	
	public Assignment(String[] inputs) {
		this.inputs = inputs;
	}
	
	public void assignment() {
		CDList cdList = new CDList();
		for (String e : inputs) {
			if (e.equals("i")) continue;
			if (e.equals("d")) {
				cdList.delete();
				continue;
			}
			cdList.insert(Integer.parseInt(e));
		}
		cdList.printall();
	}
}
