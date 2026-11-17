class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        hashmap = [0] * 26
        freq = 0
        left = 0
        length = 0

        for right in range(len(s)):

            index = ord(s[right]) - ord('A')
            hashmap[index] += 1

            freq = max(freq, hashmap[index])

            while (right - left + 1) - freq > k:
                index = ord(s[left]) - ord('A')
                hashmap[index] -= 1
                left += 1

            length = max(length, right - left + 1)

        return length