#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    unordered_set<string> openedSpoilerWords;
    int answer = 0;
    int n = message.size();
    int rangeCount = spoiler_ranges.size();

    unordered_set<string> normalWords;
    vector<vector<string>> revealedAt(rangeCount);

    int rangeIndex = 0;

    for (int i = 0; i < n; )
    {
        int start = i;

        while (i < n && message[i] != ' ')
            i++;

        int end = i - 1;
        string word = message.substr(start, end - start + 1);

        while (rangeIndex < rangeCount && spoiler_ranges[rangeIndex][1] < start)
            rangeIndex++;

        int tempIndex = rangeIndex;
        bool isSpoilerWord = false;
        int lastRevealIndex = -1;

        while (tempIndex < rangeCount && spoiler_ranges[tempIndex][0] <= end)
        {
            isSpoilerWord = true;
            lastRevealIndex = tempIndex;
            tempIndex++;
        }

        if (isSpoilerWord)
        {
            revealedAt[lastRevealIndex].push_back(word);
        }
        else
        {
            normalWords.insert(word);
        }

        i++;
    }


    for (int i = 0; i < rangeCount; i++)
    {
        for (const string& word : revealedAt[i])
        {
            if (normalWords.count(word) > 0)
                continue;

            if (openedSpoilerWords.count(word) > 0)
                continue;

            openedSpoilerWords.insert(word);
            answer++;
        }
    }

    return answer;
}