class Solution:
    def isPalindrome(self, s: str) -> bool:
        # convert a string to all lowercase and strip all non-alphanumeric characters
        s = s.lower()
        s = "".join(char for char in s if char.isalnum())

        # check for pallindrome by comparing the reveresed string
        rev_s = s[::-1]

        if(s == rev_s):
            return True
        else:
            return False
        
        

