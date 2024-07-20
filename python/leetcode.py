class Solution:
    # Determines if a given phrase is a palindrome. Cases of characters
    # are not considered neither are non-alphanumeric characters(" ", "," etc..).
    def isPalindrome(self, string: str) -> bool:
        left_ptr = 0
        right_ptr = len(string) - 1
        
        # Loop until left ptr is past the right ptr.
        while left_ptr < right_ptr:
            # Increment/Decrement right/left ptrs respectively if
            # current character is not alphanumeric.
            while left_ptr < right_ptr and not self.isAlphaNum(string[left_ptr]):
                left_ptr += 1
            while right_ptr > left_ptr and not self.isAlphaNum(string[right_ptr]):
                right_ptr -= 1

            if string[left_ptr].lower() != string[right_ptr].lower():
                return False
            # Continue on to next character.
            left_ptr += 1
            right_ptr -= 1
        return True


    # Determines if the given character is a alaphanumeric character.
    # Considerations: 
    #   ascii val   char
    #   48 - 57     0 - 9
    #   65 - 90     A - Z
    #   97 - 122    a - z
    def isAlphaNum(self, character) -> bool:
        # ord() returns ascii value of given character.
        return ( ord('0') <= ord(character) <= ord('9') or
                 ord('A') <= ord(character) <= ord('Z') or
                 ord('a') <= ord(character) <= ord('z'))
 
