// FPS COUNTER FOR 4075 CEM PROJECT CODE 

// This code calculates fps by dividing the time spent sorting the "arr" vector using the "merge sort" function by 1000000 microseconds per second to give fps shown ingame when the player is playing the game 

 #include <chrono> 
 #include <iostream> 
 #include <vector> 

 // Function that created 2 sorted arrays and returns a merged sorted array shown on the code below = 
 std::vector <int> merge(std::vector<int> left, std::vector<int> right){
    std:: vector <int> result; 
    int i = 0, j = 0; 
 }

// Code below merges elements from both the arrays and then into the result vector =
while (i < left.size()) && j < right.size()) {
    if (left[i] < right[j]){
        result.pusback (left[i]);
        i++;
    }   else {
        result.push_back (right[j]);
    }
}

// Code below is the remaining elements from the left array 
while (i <left.size()){
    result.push_back (left[i]);
    i++;
}

// Code below is the remaining relements from the right array 
while (j < right.size()){
    result.push_back (right[j]);
    j++;
}

return result; 
}

// Merge sort algorithm shown in the code below = 
std:: vector <int> merge_sort(std::vector<int> & arr) { 
    if (if arr.size()) < = 1) return arr;

    int mid = arr.size()/2; 
    std::vector <int> left(arr.begin(), arr.begin() + mid);
    std::vector <int> right(arr.begin() + mid, arr.end());

     left = merge_sort(left);
     right = merge_sort(right);

return merge(left,right);

}

int main() {
  std:: vector <int> arr = {38, 27, 43, 3, 9, 82, 10};
  
  // measure the duration of the sorting algorithm
  auto start = std::chrono::high_resolution_clock::now();
  arr = merge_sort(arr);
  auto stop = std::chrono::high_resolution_clock::now();
  
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  int fps = 1'000'000 / duration.count();
  
  std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
  std::cout << "Frames per second: " << fps << std::endl;
  
  return 0;
  
}

// Code writting by Vince Dayrit 
