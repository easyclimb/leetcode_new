#include<vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size() + nums2.size();
    if(size%2) {
      return findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2)
    }
    else {
      int n1 = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2);
      int n2 = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), size/2 -1 );
      return (n1 + n2)/2;
    }
  }

  int findKth(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k) {
    if(nums1[e1] <= nums2[s1]) {
    }
    else {
      if(nums1[e1] )
    }
  }
};
