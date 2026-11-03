// 345. Reverse Vowels of a String

// Approach: Two Pointers
// Initialize two pointers:
// st at the beginning of the string.
// end at the end of the string.
// Traverse the string using both pointers.
// Check whether the character at st is a vowel:
// If not, increment st.
// Otherwise, check whether the character at end is a vowel:
// If not, decrement end.
// If both characters are vowels:
// Swap the characters.
// Increment st and decrement end.
// Continue until the two pointers cross.
// Return the modified string.
// Time Complexity
// O(n): Each pointer traverses the string at most once.
// Space Complexity
// O(1): Reversal is performed in-place without using extra data structures.
// Key Idea

// Use the two-pointer technique to find vowels from both ends and swap them, while keeping all consonants in their original positions.

class Solution
{
public:
    string reverseVowels(string s)
    {
        int st = 0;
        int end = s.length() - 1;

        while (st <= end)
        {
            if (s[st] != 'a' && s[st] != 'e' && s[st] != 'i' && s[st] != 'o' && s[st] != 'u' && s[st] != 'A' && s[st] != 'E' && s[st] != 'I' && s[st] != 'O' && s[st] != 'U')
            {

                st++;
            }

            else if (s[end] != 'a' && s[end] != 'e' && s[end] != 'i' && s[end] != 'o' && s[end] != 'u' && s[end] != 'A' && s[end] != 'E' && s[end] != 'I' && s[end] != 'O' && s[end] != 'U')
            {

                end--;
            }

            else
            {
                char temp = s.at(st);
                s.at(st) = s.at(end);
                s.at(end) = temp;

                st++;
                end--;
            }
        }
        return s;
    }
};