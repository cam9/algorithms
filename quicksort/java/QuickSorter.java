import java.util.*;

public class QuickSorter{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		ArrayList<Integer> input = new ArrayList<Integer>();
		while(in.hasNext()){
			input.add(in.nextInt());	
		}
		int[] arr = new int[input.size()];
		for(int i = 0; i < input.size(); i++){
			arr[i] = input.get(i);
		}

		System.out.println(Arrays.toString(quickSort(arr)));
	}

	private static int[] quickSort(int[] arr){
	 return arr;
	}	 

	private static void sort(int[] arr, int lo, int hi){
		
	}

}

