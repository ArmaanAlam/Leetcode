class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = {}

        for char in s:
            mp[char] = mp.get(char, 0) + 1

        for char in t:
            mp[char] = mp.get(char, 0) - 1

        ans = True
        for value in mp.values():
            if(value != 0):
                ans = False

        return ans