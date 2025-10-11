#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    vector<string> line;
    int length = 0;
    int i = 0;
    int n = words.size();

    while (i < n) {
        // Check if adding the next word exceeds maxWidth
        if ((length + (line.size()) + (words[i].size())) > maxWidth) {
            // line complete
            int extra_space = maxWidth - length;

            // Calculate evenly distributed spaces and remainder
            int spaces = extra_space / max(1, (int)(line.size()) - 1);
            int remainder = extra_space % max(1, (int)(line.size()) - 1);

            // Add spaces to each word except the last one
            for (int j = 0; j < max(1, (int)(line.size()) - 1); j++) {
                line[j] += string(spaces, ' ');
                if (remainder) {
                    line[j] += " ";
                    remainder -= 1;
                }
            }

            // Combine words in line into one justified string
            string line_words = accumulate(line.begin(), line.end(), string(""));
            res.push_back(line_words);

            // Reset for the next line
            line.clear();
            length = 0;
            continue;
        }

        // Add word to the current line
        line.push_back(words[i]);
        length += words[i].size();
        i += 1;
    }

    // Handling the last line - left justified with trailing spaces
    string last_line = "";
    for (int k = 0; k < line.size(); k++) {
         if (k > 0) last_line += " "; 
         last_line += line[k];
    }
    int trail_space = maxWidth - (int)(last_line.size());
    last_line += string(trail_space, ' ');
    res.push_back(last_line);

    return res;
}

int main() {
    // Input words and maxWidth
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    // Call the fullJustify function and print the result
    vector<string> justifiedText = fullJustify(words, maxWidth);
    for (const string& line : justifiedText) {
        cout << '"' << line << '"' << endl;
    }

    return 0;
}
