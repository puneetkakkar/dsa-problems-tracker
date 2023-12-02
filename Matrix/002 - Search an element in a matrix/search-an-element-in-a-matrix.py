class Solution:
    def col_binary_search(self, arr, low, high, element):  
        if(high >= low):
            mid = (high + low) // 2

            if(arr[mid] == element):
                return mid
            elif(arr[mid] > element):
                return self.col_binary_search(arr, low, mid - 1, element)
            else:
                return self.col_binary_search(arr, mid + 1, high, element)
        else:
            return -1

    def row_binary_search(self, matrix, low, high, element):
        col_idx = 0

        if(high >= low):
            mid_idx = (high + low) // 2

            if((mid_idx != high and matrix[mid_idx + 1][col_idx] > element 
                and matrix[mid_idx][col_idx] <= element) 
                or (mid_idx == high and matrix[mid_idx][col_idx] <= element)
            ):
                return mid_idx
            elif(matrix[mid_idx][col_idx] > element):
                return self.row_binary_search(matrix, low, mid_idx - 1, element)
            else:
                return self.row_binary_search(matrix, mid_idx + 1, high, element)
        else:
            return -1

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        num_r = len(matrix)
        num_c = len(matrix[0])

        found = False

        row_search = self.row_binary_search(matrix, 0, num_r - 1, target)

        if(row_search != -1):
            col_search = self.col_binary_search(
                            matrix[row_search], 
                            0, num_c - 1,target
                        )
            
            if(col_search != -1):
                found = True

        return found