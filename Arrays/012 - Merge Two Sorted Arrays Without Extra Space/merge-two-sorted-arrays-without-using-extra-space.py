class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        left = n - 1
        right = 0
        
        while(left >= 0 and right < m and arr1[left] > arr2[right]):
            if(arr1[left] > arr2[right]):
                arr1[left], arr2[right] = arr2[right], arr1[left]
                left -= 1
                right += 1
            
            
        arr1.sort()
        arr2.sort()