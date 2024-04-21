package week13;

public class QuickSort {
	static void Bubble(int[] data) {
		for(int i=0; i<data.length-1; i++) {
			boolean changed = false;
			for(int j=0; j<data.length-1-i;j++) {
				if(data[j]>data[j+1]) {
					int tmp = data[j];
					data[j]=data[j+1];
					data[j+1]=tmp;
					changed = true;
				}
			}
			if(!changed)break;
		}
	}
	static void quick(int[] data, int start, int end) {
		if(start >= end) return;
		int pv = pivot(data, start, end);
		quick(data, start, pv-1);
		quick(data, pv+1, end);
	}
	static int pivot(int[] data, int start, int end) {
		int tmp;
		int pv = data[start];
		int low = start + 1;
		int high = end;
		while(true) {
			while(low<=high&&data[low]<=pv) {
				low++;
			}
			while(low<=high&&pv<=data[high]) {
				high--;
			}
			if(high<low) {
				break;
			}else {
				tmp = data[low];
				data[low]=data[high];
				data[high]=tmp;
			}
		}
		tmp = data[start];
		data[start]=data[high];
		data[high]=tmp;
		return high;
	}
	public static void main(String[] args) {
		int tmp;
		int[] b = new int[60000];
		int[] q = new int[60000];
		for(int i=0; i<60000; i++) {
			tmp = (int)(Math.random()*100000)-50000;
			b[i]=tmp;
			q[i]=tmp;
		}
		long start;
		long end;
		System.out.println("---버블정렬---");
		start = System.currentTimeMillis();
		Bubble(b);
		end = System.currentTimeMillis();
		System.out.println((end-start) + " ms"); // 4800ms
		System.out.println("---퀵정렬---");
		start = System.currentTimeMillis();
		quick(q, 0, q.length-1);
		end = System.currentTimeMillis();
		System.out.println((end-start) + " ms");  // 10ms
		
	}
}
