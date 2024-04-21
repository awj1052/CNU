package week13;

public class CustomException {

	public static void main(String[] args) {
		try(CloseableResource cr = new CloseableResource()){
			cr.exceptionWork(false);
		} catch (WorkException e) {
			e.printStackTrace();
		} catch (CloseException e) {
			e.printStackTrace();
		}
		System.out.println();
		
		try(CloseableResource cr = new CloseableResource()){
			cr.exceptionWork(true);
		} catch (WorkException e) {
			e.printStackTrace();
		} catch (CloseException e) { // Suppressed
			e.printStackTrace();
		}		

	}

}

class CloseableResource implements AutoCloseable{
	
	public void exceptionWork(boolean exception) throws WorkException{
		System.out.println("exceptionWork(" + exception + ")가 호출됨");
		if(exception) {
			throw new WorkException("WorkException 발생!");
		}
	}

	@Override
	public void close() throws CloseException {
		System.out.println("close() 호출");
		throw new CloseException("CloseException 호출");		
	}
	
}

class CloseException extends Exception{
	CloseException(String msg){
		super(msg);
	}
}

class WorkException extends Exception{
	WorkException(String msg){
		super(msg);
	}
}