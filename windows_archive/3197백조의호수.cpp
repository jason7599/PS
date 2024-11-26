#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

const char mappa_acqua = '.';
const char mappa_ghiaccio = 'X';
const char mappa_anatra = 'L';

const int dys[] = {1, 0, -1, 0};
const int dxs[] = {0, 1, 0, -1};

int mappa_altezza, mappa_larghezza;
char mappa[1'500][1'500];
bool anatra_visitato[1'500][1'500];

bool fuori_di_mappa(int y, int x)
{
    return y < 0 || y >= mappa_altezza || x < 0 || x >= mappa_larghezza;
}

int risolvere(queue<pii>& coda_aqua, pii anatra0)
{
    int giorni = 0;

    queue<pii> coda_anatra;
    coda_anatra.push(anatra0);

    anatra_visitato[anatra0.first][anatra0.second] = true;

    while (true)
    {
        queue<pii> prossima_coda_anatra;

        while (!coda_anatra.empty())
        {
            int y = coda_anatra.front().first;
            int x = coda_anatra.front().second;
            coda_anatra.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (fuori_di_mappa(ny, nx) || anatra_visitato[ny][nx])
                    continue;

                // penso di potere cambiare questo in "if (mappa[ny][nx] == mappa_anatra)"
                // perche abbiamo gia controllato anatra_visitato
                if (mappa[ny][nx] == mappa_anatra)
                    return giorni;
                
                anatra_visitato[ny][nx] = true;

                if (mappa[ny][nx] == mappa_acqua)
                    coda_anatra.push({ny, nx});
                else // == if(mappa[ny][nx] == mappa_ghiaccio)
                    prossima_coda_anatra.push({ny, nx});
            }
        }

        coda_anatra = prossima_coda_anatra;

        int dimensione_coda_aqua = coda_aqua.size();
        while (dimensione_coda_aqua--)
        {
            int y = coda_aqua.front().first;
            int x = coda_aqua.front().second;
            coda_aqua.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dys[d];
                int nx = x + dxs[d];

                if (fuori_di_mappa(ny, nx))
                    continue;
                
                if (mappa[ny][nx] == mappa_ghiaccio)
                {
                    mappa[ny][nx] = mappa_acqua;
                    coda_aqua.push({ny, nx});
                }
            }
        }

        giorni++;
    }

    return -1;
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> mappa_altezza >> mappa_larghezza;

    queue<pii> coda_aqua;

    pii anatra0;
    bool anatra0_trovato = false;

    for (int y = 0; y < mappa_altezza; y++)
    {
        for (int x = 0; x < mappa_larghezza; x++)
        {
            char c; cin >> c;

            if (c == mappa_acqua)
                coda_aqua.push({y, x});
            else if (c == mappa_anatra)
            {
                if (!anatra0_trovato)
                {
                    anatra0 = {y, x};
                    anatra0_trovato = true;
                }

                coda_aqua.push({y, x});
            }

            mappa[y][x] = c;
        }
    }

    cout << risolvere(coda_aqua, anatra0);

    return 0;
}