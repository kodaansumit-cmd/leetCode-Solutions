class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);

        vector<string> words;
        string word;

    
        while (ss >> word) {
            words.push_back(word);
        }
if (pattern.length() != words.size())
            return false;

        unordered_map<char, string> charToWord;

        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.length(); i++) {

            char ch = pattern[i];
            string currentWord = words[i];

            if (charToWord.count(ch)) {

                if (charToWord[ch] != currentWord)
                    return false;
            }
            else {
                charToWord[ch] = currentWord;
            }
            if (wordToChar.count(currentWord)) {
                if (wordToChar[currentWord] != ch)
                    return false;
            }
            else {
                wordToChar[currentWord] = ch;
            }
        }
        return true;
    }
};