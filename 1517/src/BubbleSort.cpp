
#include <iostream>


long long int merge(int* list, int start, int mid, int end, int n){
	long long int i, j, k, l;
	i = start;
	j = mid + 1;
	k = start;
	int temp[n];
	long long int swaps = 0;

	while(i <= mid && j <= end){
		if(list[i] <= list[j]){
			temp[k] = list[i];
			k++;
			i++;
		}
		else if (list[i] > list[j]){
			temp[k] = list[j];
			swaps += mid - i + 1;
			k++;
			j++;
		}
	}

	if(i > mid){
		for(l = j; l <= end; l++){
			temp[k] = list[l];
			k++;
		}
	}
	else if(j > end){
		for(l = i; l <= mid; l++){
			temp[k] = list[l];
			k++;
		}
	}
	for(l = start; l <=end; l++){
		list[l] = temp[l];
	}
	return swaps;
}

long long int divide(int* list, int start, int end, int n){
	long long int swaps = 0;
	if (start < end){
		int mid = (start + end) / 2;
		swaps += divide(list, start, mid, n);
		swaps += divide(list, mid+1, end, n);
		swaps += merge(list, start, mid, end, n);
	}
	return swaps;
}

int main(){
	int n;
	std::cin >> n;
	int list[n];
	for(long long int i = 0; i < n; i++){
		std::cin >> list[i];
	}
	long long int swaps = divide(list, 0, n-1, n);
	std::cout << swaps;
}

