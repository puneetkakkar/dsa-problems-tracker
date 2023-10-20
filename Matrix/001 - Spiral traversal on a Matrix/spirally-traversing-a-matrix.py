
'''
:file spirally-traversing-a-matrix.cpp
:author Puneet Kakkar (puneetkakkar91@gmail.com)
:brief Given a matrix of size r*c. Traverse the matrix in spiral form.
:version 0.1
:date 2023-10-19

@copyright Copyright (c) 2022
'''

class Solution:
    
    #Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self,matrix, r, c): 
        # used to change direction and 
        # move in a clockwise direction
        tr = [0, 1, 0, -1]
        tc = [1, 0, -1, 0]
        
        visited = [[0 for i in range(c)] for j in range(r)]
        max_items = r * c
        pos_r = 0 
        pos_c = 0
        di = 0
        result = []
        
        for _ in range(0, max_items):
            elem = matrix[pos_r][pos_c]
            result.append(elem)
            
            visited[pos_r][pos_c] = 1
            new_pos_r = pos_r + tr[di]     
            new_pos_c = pos_c + tc[di]
            
            if( new_pos_r >= 0 and new_pos_r < r and 
                new_pos_c >= 0 and new_pos_c < c and 
                visited[new_pos_r][new_pos_c] != 1
            ):
                pos_r = new_pos_r
                pos_c = new_pos_c
            else:
                di += 1
                di = di % 4
                pos_r += tr[di]
                pos_c += tc[di]
            
        return result
        
