class Solution {
public:
    
    pair<int,int> search(vector<int> &v1, vector<int> &v2, bool is_gt, int start, int end, int v1_med, int v2_med) {
        int mid1 = (end-start)/2 + start;
        int mid2 = v2_med + (v1_med-mid1);
        int diff = v1[mid1] - v2[mid2];
std::cout << "start:" << start << " end:" << end << " mid1:" << mid1 << " mid2:" << mid2 << " diff:" << diff << std::endl;   
        
        if (diff == 0)
            return make_pair(mid1, mid2);
        if (is_gt)
        {
            if (diff>0 && mid1>start)
            {
                pair<int,int> ret = search(v1, v2, is_gt, start, mid1-1, v1_med, v2_med);
                if (ret.first != -1)
                    return ret;
                else
                    return make_pair(mid1, mid2);
            }
            else if (diff<0 && mid1<end)
            {
                return search(v1, v2, is_gt, mid1+1, end, v1_med, v2_med);
            }
            else
            {
                if (diff>0)
                    return make_pair(mid1, mid2);
                else
                    return make_pair(-1, -1);
            }
        }
        else
        {
            if (diff<0 && mid1<end)
            {
                pair<int,int> ret = search(v1, v2, is_gt, mid1+1, end, v1_med, v2_med);
                if (ret.first != -1)
                    return ret;
                else
                    return make_pair(mid1, mid2);
            }
            else if (diff>0 && mid1>start)
            {
                return search(v1, v2, is_gt, start, mid1-1, v1_med, v2_med);
            }
            else
            {
                if (diff<0)
                    return make_pair(mid1, mid2);
                else
                    return make_pair(-1, -1);
            }
        }
    }
    
    enum ArrayTypes {
        bothEven,
        odd1even2,
        even1odd2,
        bothOdd
    };
    ArrayTypes getArrayTypes(vector<int> &v1, vector<int> &v2) {
        ArrayTypes arrayTypes;
        bool even1 = ((v1.size()%2) == 0);
        bool even2 = ((v2.size()%2) == 0);
        
        if (even1 && even2)
            arrayTypes = bothEven;
        else if (!even1 && even2)
            arrayTypes = odd1even2;
        else if (even1 && !even2)
            arrayTypes = even1odd2;
        else
            arrayTypes = bothOdd;
        
        return arrayTypes;
    }
    
    double calcMedian(vector<int>& v) {
        int left = (v.size()-1) / 2;
        double median;
        
        if (v.size() % 2)
            median = v[left];
        else
            median = ((double)v[left] + v[left+1]) / 2.0;
        
        return median;
    }
    
    pair<int,int> findMedIndicies(vector<int> &v1, vector<int> &v2, ArrayTypes arrayTypes, double &foundMedian) {
        pair<int,int> med;
        
        switch (arrayTypes) {
            case (bothEven):
            {
                int left1 = (v1.size()-1) / 2;
                int right1 = left1 + 1;
                int left2 = (v2.size()-1) / 2;
                int right2 = left2 + 1;
                
                if (v1[left1] >= v2[right2])
                {
                    med.first = left1;
                    med.second = right2;
                }
                else if (v1[right1] <= v2[left2])
                {
                    med.first = right1;
                    med.second = left2;
                }
                else
                {
                    // found median!!!
                    vector<int> vtmp = {v1[left1], v1[right1], v2[left2], v2[right2]};
                    std::sort(vtmp.begin(), vtmp.end());
                    foundMedian = calcMedian(vtmp);
                    med.first = med.second = -1; 
                }
                break;
            }
            case (odd1even2):
            {
                med.first =  (v1.size()-1) / 2;
                int left2 = (v2.size()-1) / 2;
                int right2 = left2 + 1;
                if (v1[med.first]>=v2[left2] && v1[med.first]>=v2[right2])
                    med.second = right2;
                else if (v1[med.first]<=v2[left2] && v1[med.first]<=v2[right2])
                    med.second = left2;
                else
                {
                    // found median!!!
                    foundMedian = v1[med.first];
                    med.first = med.second = -1;
                }
                break;
            }
            case (even1odd2):
            {
                med.second = (v2.size()-1) / 2;
                int left1 = (v1.size()-1) / 2;
                int right1 = left1 + 1;
                if (v2[med.second]>=v1[left1] && v2[med.second]>=v1[right1])
                    med.first = right1;
                else if (v2[med.second]<=v1[left1] && v2[med.second]<=v1[right1])
                    med.first = left1;
                else
                {
                    // found median!!!
                    foundMedian = v2[med.second];
                    med.first = med.second = -1;
                }
                break;
            }
            default: // bothOdd
            {
                med.first = (v1.size()-1) / 2;
                med.second = (v2.size()-1) / 2;
                break;
            }
        }

        return med;
    }
    
    double findMedian(vector<int> &v1, vector<int> &v2, ArrayTypes arrayTypes, int idx1, int idx2, bool is_gt) {
        double median;
        vector<int> v;
        
        switch (arrayTypes) {
            case (odd1even2):
            {
                
                //// select 1 idx in odd arr, two in even arr, plus one extra in each with gt sel <-, and lt sel ->
                // select 1 idx in odd arr, two in even arr
                v.push_back(v1[idx1]);
                v.push_back(v2[idx2]);
                if (is_gt)
                {
                    if (idx1 > 0)
                        v.push_back(v1[idx1-1]);
                    else
                        v.push_back(INT_MIN);
                }
                else
                {
                    if (idx1 < (v1.size()-1))
                        v.push_back(v1[idx1+1]);
                    else
                        v.push_back(INT_MAX);
                }                

                if (idx2 < (v2.size()-1))
                    v.push_back(v2[idx2+1]);
                else
                    v.push_back(INT_MAX);
                if (idx2 > 0)
                    v.push_back(v2[idx2-1]);
                else
                    v.push_back(INT_MIN);                

                std::sort(v.begin(), v.end());
                return calcMedian(v);
                break;
            }
            case (even1odd2):
            {
                //// select 1 idx in odd arr, two in even arr, plus one extra in each with gt sel <-, and lt sel ->
                // select 1 idx in odd arr, two in even arr
                v.push_back(v1[idx1]);
                v.push_back(v2[idx2]);
                if (idx1 < (v1.size()-1))
                    v.push_back(v1[idx1+1]);
                else
                    v.push_back(INT_MAX);
                if (idx1 > 0)
                    v.push_back(v1[idx1-1]);
                else
                    v.push_back(INT_MIN);
                
                if (is_gt)
                {
                    if (idx2 < (v2.size()-1))
                        v.push_back(v2[idx2+1]);
                    else
                        v.push_back(INT_MAX);
                }
                else
                {
                    if (idx2 > 0)
                        v.push_back(v2[idx2-1]);
                    else
                        v.push_back(INT_MIN);
                }
                std::sort(v.begin(), v.end());
std::cout << "even1odd2 v.size():" << v.size() << std::endl;
                return calcMedian(v);
                break;
            }
            default: // bothEven OR bothOdd
            {
                // select two idx per array, with gt sel <-, and lt sel ->
                v.push_back(v1[idx1]);
                v.push_back(v2[idx2]);
                if (is_gt)
                {
                    if (idx1 > 0)
                        v.push_back(v1[idx1-1]);
                    else
                        v.push_back(INT_MIN);
                    if (idx2 < (v2.size()-1))
                        v.push_back(v2[idx2+1]);
                    else
                        v.push_back(INT_MAX);
                }
                else
                {
                    if (idx2 > 0)
                        v.push_back(v2[idx2-1]);
                    else
                        v.push_back(INT_MIN);
                    if (idx1 < (v1.size()-1))
                        v.push_back(v1[idx1+1]);
                    else
                        v.push_back(INT_MAX);
                }
                std::sort(v.begin(), v.end());
std::cout << "bothSame v.size():" << v.size() << std::endl;
                return calcMedian(v);
                break;
            }
        }
            
        return median;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()==0 && nums2.size()==0)
            return 0;
        if (nums1.size() == 0)
            return calcMedian(nums2);
        if (nums2.size() == 0)
            return calcMedian(nums1);
        
        double median;
        vector<int> &v1 = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int> &v2 = (nums1.size() <= nums2.size()) ? nums2 : nums1;      
        
        ArrayTypes arrayTypes = getArrayTypes(v1, v2);
        pair<int,int> idx;
        double foundMedian;
        pair<int,int>med = findMedIndicies(v1, v2, arrayTypes, foundMedian);
std::cout << "med.first:" << med.first << " med.second:" << med.second << std::endl;
        if (med.first == -1)
            return foundMedian;

        bool is_gt = v1[med.first] >= v2[med.second];
        idx = search(v1, v2, is_gt, 0, v1.size()-1, med.first, med.second);
std::cout << "search first:" << idx.first << " second:" << idx.second << std::endl;
        median = findMedian(v1, v2, arrayTypes, idx.first, idx.second, is_gt);   
        
        return median;
    }
};
