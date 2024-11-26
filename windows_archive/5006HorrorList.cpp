#include <iostream>
#include <queue>

using namespace std;

const int inf = 1e9;

int horrorIndices[1000];
vector<int> similarities[1000];
bool visited[1000];

void solve(const vector<int>& horrors)
{
    queue<int> q;

    for (int horror : horrors)
    {
        q.push(horror);
        visited[horror] = true;
    }

    int horrorIndex = 0;
    int qSize;
    while ((qSize = q.size()) != 0)
    {
        while (qSize--)
        {
            int movie = q.front();
            q.pop();

            horrorIndices[movie] = horrorIndex;
            
            for (int similar : similarities[movie])
            {
                if (!visited[similar])
                {
                    visited[similar] = true;
                    q.push(similar);
                }
            }
        }

        horrorIndex++;
    }
}

int main()
{
    int numMovies, numHorrors, numSimilarities;
    cin >> numMovies >> numHorrors >> numSimilarities;

    for (int i = 0; i < numMovies; i++)
        horrorIndices[i] = inf;

    vector<int> horrors;

    for (int i = 0; i < numHorrors; i++)
    {
        int horror;
        cin >> horror;
        horrors.push_back(horror);
    }

    for (int i = 0; i < numSimilarities; i++)
    {
        int movie0, movie1;
        cin >> movie0 >> movie1;
        similarities[movie0].push_back(movie1);
        similarities[movie1].push_back(movie0);
    }

    solve(horrors);

    int bestMovie;
    int maxHorrorIndex = -1;

    for (int i = 0; i < numMovies; i++)
    {
        if (maxHorrorIndex < horrorIndices[i])
        {
            maxHorrorIndex = horrorIndices[i];
            bestMovie = i;
        }
    }

    cout << bestMovie;
    return 0;
}