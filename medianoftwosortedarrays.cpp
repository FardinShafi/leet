#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mergedArr;
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                mergedArr.push_back(nums1[i]);
                i++;
            }
            else
            {
                mergedArr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size())
        {
            mergedArr.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size())
        {
            mergedArr.push_back(nums2[j]);
            j++;
        }
        double median = 0;
        int mergedSize = mergedArr.size();
        if (mergedSize % 2 == 0)
        {
            median = (mergedArr[mergedSize / 2 - 1] +
                      mergedArr[mergedSize / 2]) /
                     2.0;
        }
        else
        {
            median = mergedArr[mergedSize / 2];
        }

        return median;
    }
};

int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};

    Solution solution;
    double median = solution.findMedianSortedArrays(nums1, nums2);

    cout << "Median of the merged array: " << median << endl;

    return 0;
}
