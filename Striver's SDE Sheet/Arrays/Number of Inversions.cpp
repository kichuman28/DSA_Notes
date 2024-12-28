#include<bits/stdc++.h>


int Merge(int low, int mid, int high, vector<int> &a){
    int left = low;
    int count = 0;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }else{
            temp.push_back(a[right]);
            count += (mid - left + 1);
            right++;
        }
    }


    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }
    
    return count;
}


int mergeSort(int low, int high, vector<int>&a){
    if(low == high) return 0;
    int count = 0;
    int mid = (low + high) / 2;
    count += mergeSort(low, mid, a);
    count += mergeSort(mid+1, high, a);
    count += Merge(low, mid, high, a);
    return count;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(0, n - 1, a);
}



