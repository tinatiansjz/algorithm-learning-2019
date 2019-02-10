class Solution(object):
    def __init__(self):
        self.longestSize = 0
        self.longestStart = 0

    def longestPalindrome(self, s):
        for index, value in enumerate(s):
            self.checkOddPalindrome(s, index)
            self.checkEvenPalindrome(s, index)
        return s[self.longestStart:self.longestSize+self.longestStart+1]

    def checkOddPalindrome(self, s, index):
        start = index
        end = index
        while start >= 1 and end < len(s)-1 and s[start-1] == s[end+1]:
            start -= 1
            end += 1
        if end - start > self.longestSize:
            self.longestSize = end - start
            self.longestStart = start
    
    def checkEvenPalindrome(self, s, index):
        start = index
        end = min(index + 1, len(s)-1)
        while s[start] == s[end] and start >= 1 and end < len(s)-1 and s[start-1] == s[end+1]:
            start -= 1
            end += 1
        if end-start > self.longestSize and s[start] == s[end]:
            self.longestSize = end - start
            self.longestStart = start

def execute():
    sol = Solution()
    print(sol.longestPalindrome("babbad"))

if __name__ == '__main__':
    execute()
