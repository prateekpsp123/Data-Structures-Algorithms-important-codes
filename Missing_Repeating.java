class Solve {
    int[] findTwoElement(int arr[], int n) {
        // code here
        int [] ans = new int[2];
        int i=0;
        while(i<n){
            int correct_index = arr[i]-1;
            if(arr[correct_index] != arr[i]){
                swap(arr,correct_index,i);
            }
            else{
                i++;
            }
        }
        int missing = -1;
        int repeating = -1;
        
        for(int index=0; index<n; index++){
            int correct_value = index+1;
            if(correct_value != arr[index]){
                missing = correct_value;
                repeating = arr[index];
                break;
            }
        }
        ans [0] = repeating;
        ans [1] = missing;
        return ans;
    }
    public static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
