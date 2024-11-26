#include <iostream>
#include <vector>

using namespace std;

struct BallSeq
{
    int color;
    int length;
};

int numBallSeqs;
BallSeq ballSeqs[10'000];

int pang(int left, int right)
{
    int score = 0;
    while (left >= 0 && right < numBallSeqs)
    {
        int t;
        if (ballSeqs[left].color == ballSeqs[right].color
        && (t = ballSeqs[left].length + ballSeqs[right].length) >= 4)
        {
            score += t;
            left--;
            right++;
        }
        else
            break;
    }
    return score;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numBalls; 
    cin >> numBalls;

    cin >> ballSeqs[0].color;
    ballSeqs[0].length = 1; 
    numBallSeqs = 1;

    vector<int> lenThreeBallSeqIndexes;

    for (int i = 1; i < numBalls; i++)
    {
        int color; 
        cin >> color;

        if (color == ballSeqs[numBallSeqs - 1].color) // extend seq
        {
            if (++ballSeqs[numBallSeqs - 1].length == 3) // candidate 
            {
                lenThreeBallSeqIndexes.push_back(numBallSeqs - 1);
            }
        }
        else // new seq
        {
            ballSeqs[numBallSeqs].color = color;
            ballSeqs[numBallSeqs++].length = 1;
        }
    }

    // printf("number of ballsecks = %d\n", numBallSeqs);
    // for (int i = 0; i < numBallSeqs; i++)
    // {
    //     BallSeq ballSeq = ballSeqs[i];
    //     switch (ballSeq.color)
    //     {
    //         case 1: printf("red"); break;
    //         case 2: printf("blue"); break;
    //         case 3: printf("yellow");
    //     }
    //     printf(" %d, ", ballSeq.length);
    // }

    /*
     *  위 아래로
     *  임시적으로 length-- 해줄거야. 나중에 복구해줘야하고
     *  근데 length-- 한게 0이 되었다? 이러면 그 다음 녀석이랑도 합쳐지는지 봐야됨.
     *  이렇게 합쳐지는 거 다 시뮬레이션 한 다음엔, 합쳐진 덩어리 위 아래 각각 포인터 둬서 뻗어나가면서 색 같은지 확인
     *  이게 전부 아닐까?
    */

   int mostPang = 0;

    for (int lenThreeBallSeqIndex : lenThreeBallSeqIndexes)
    {
        int left = lenThreeBallSeqIndex - 1;
        int right = lenThreeBallSeqIndex + 1;
        int pangScore = 4;

        if (left >= 0)
        {
            if (--ballSeqs[left].length == 0) // merge left
            {
                if (--left >= 0)
                {
                    if (ballSeqs[lenThreeBallSeqIndex].color == ballSeqs[left].color) 
                    {
                        pangScore += ballSeqs[left].length;
                        left--;
                    }
                }
            }

            pangScore += pang(left, right);
            if (pangScore > mostPang)
                mostPang = pangScore;

            ballSeqs[lenThreeBallSeqIndex - 1].length++;
        }

        left = lenThreeBallSeqIndex - 1;
        right = lenThreeBallSeqIndex + 1;
        pangScore = 4;

        if (right < numBallSeqs)
        {
            if (--ballSeqs[right].length == 0) // merge right
            {
                if (++right < numBallSeqs)
                {
                    if (ballSeqs[lenThreeBallSeqIndex].color == ballSeqs[right].color) 
                    {
                        pangScore += ballSeqs[right].length;
                        right++;
                    }
                }
            }

            pangScore += pang(left, right);
            if (pangScore > mostPang)
                mostPang = pangScore;

            ballSeqs[lenThreeBallSeqIndex + 1].length++;
        }
    }

    cout << numBalls - mostPang;
}