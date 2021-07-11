/**
 * @file sol0sol.cpp
 *
 * @version 01.01 20201125
 *
 * @brief sol2sol
 *
 * @ingroup sol0sol
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

// Variabiles
int M, temp1, temp2;

vector <vector<int> > giocatori;

int visita(int n)
{
    int max_ = -1;
    for (int nn = 0; nn < M; ++nn)
    {
        if(nn != n)
        {
            int counter = 0;
            vector <bool> visitato (M + 1, false);

            visitato[n] = true;
            stack <int> pila;
            pila.push(nn);

            while(!pila.empty())
            {
                int now_ = pila.top();
                pila.pop();
                if(!visitato[now_])
                {
                    visitato[now_] = true;
                    for(int i = 0; i < giocatori[now_].size(); ++i)
                        pila.push(giocatori[now_][i]);
                }
            }

            for(int i = 2; i < visitato.size(); ++i)
                if(!visitato[i])
                    counter++;

            if(counter > max_)
                max_ = counter;
        }
    }
    return max_;
}

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Input
    cin >> M;
    giocatori.resize(M + 1);
    for (int i = 0; i < M; ++i)
    {
        cin >> temp1 >> temp2;
        giocatori[temp1 - 1].push_back(temp2 - 1);
    }

    int result;
    int escluded_player = -1;
    for(int i = 0; i < M; ++i)
    {
        int temp = visita(i);
        if(temp > escluded_player)
        {
            escluded_player = temp;
            result = i;
        }
    }

// Output
    cout << result + 1 << endl;

// End
    return 0;
}
