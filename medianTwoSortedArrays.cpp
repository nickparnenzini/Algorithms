#include <vector>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int>::iterator it1 = nums1.begin();
	vector<int>::iterator it2 = nums2.begin();
	vector<int> arr;
	int n = 0;
	int m = 0;
	
	while ( (it1 != nums1.end()) && (it2 != nums2.end()) ) {          
		if ( *it1 <= *it2 ) {
			arr.push_back(*it1);
			it1++; n++;
		}
		else {
			arr.push_back(*it2);
			it2++; m++;
		}  
	}
	
	if ( it1 != nums1.end() ) {
		while ( it1 != nums1.end() ) {
		  arr.push_back(*it1);
		  it1++; n++;
		}
	}
	
	if ( it2 != nums2.end() ) {
		while( it2 != nums2.end() ) {
			arr.push_back(*it2);
			it2++; m++;
		}
	}
		  
	int med_index = (n+m)/2;
	
	double median = 0.0; 
	
	if ( n+m == 1 ) {
		median = arr[med_index];
	}
	else {
		 if ( (n+m) % 2 == 0 ) {
			median = (arr[med_index-1] + arr[med_index])/2.0;
		}
		else {
			median = arr[med_index];
		}
	}
   
	return median;
}
	