#include <iostream>
#define EMPTY '.'
#define PLAYER1 'O'
#define PLAYER2 'X'
#define DRAW_GAME ' '
#include <cstdlib>

using namespace std;

struct _Grille *Grille;
struct _Grille {

    char data[9];
    char player;
    int nb_empty;
    char status;

};
void  _Grille_display(_Grille G)
{
    cout <<"| "<< G.data[0]<<" | "<<G.data[1]<< " | " << G.data[2] <<"|      012" <<endl;
    cout <<"| "<< G.data[3]<<" | "<<G.data[4]<< " | " << G.data[5] <<"|      345" <<endl;
    cout <<"| "<< G.data[6]<<" | "<<G.data[7]<< " | " << G.data[8] <<"|      678" <<endl;
}
_Grille Grille_create( void )
{
    _Grille G ;
    int i;
    for (int i = 0; i <9 ; ++i)
    {
        G.data[i]=EMPTY;
    }
    G.nb_empty=9;
    G.player = PLAYER1;
    G.status=EMPTY;


    return G;
}
int Grille_get_position( _Grille G)
{
    int n;
cout << "Entrez le numero de case entre 0 et 8" <<endl;
cin >> n;
if(n<0 or n>8)
{
    cout <<"Votre jeu nest pas valable"<<endl;
    return Grille_get_position(G);
}
if (G.data[n]!= EMPTY) {
    cout << "La case est  deja occupe";
    return Grille_get_position(G);
}
return n;
}
void Grille_update_status(_Grille G)
{
    if( (G.data[0] == G.data[1]) &&  (G.data[1] == G.data[2]) &&  (G.data[0] == G.player))
    G.status = G.player;
    if( (G.data[3] == G.data[4]) &&  (G.data[4] == G.data[5]) &&  (G.data[5] == G.player))
        G.status = G.player;
    if( (G.data[6] == G.data[7]) &&  (G.data[7] == G.data[8]) &&    (G.data[8] == G.player))
        G.status = G.player;
    if( (G.data[0] == G.data[3]) &&  (G.data[3] == G.data[6]) &&  (G.data[6] == G.player))
        G.status = G.player;
    if( (G.data[1] == G.data[4]) &&  (G.data[4] == G.data[7]) &&  (G.data[7] == G.player))
        G.status = G.player;
    if( (G.data[2] == G.data[5]) &&  (G.data[5] == G.data[8]) &&    (G.data[8] == G.player))
        G.status = G.player;
    if( (G.data[0] == G.data[4]) &&  (G.data[4] == G.data[8]) &&  (G.data[8] == G.player))
        G.status = G.player;
    if( (G.data[2] == G.data[4]) &&  (G.data[4] == G.data[6]) && (G.data[6] == G.player))
        G.status = G.player;
   if ((G.status ==EMPTY) and (G.nb_empty==0))
         G.status= DRAW_GAME;
}





int main(int argc,char*argv[]) {
    _Grille G =Grille_create();
    _Grille_display(G);
    while(G.status == EMPTY)
    {
        int pos;
        cout << "Joueur " << G.player<<" a vous de jouer"<< endl;
         pos = Grille_get_position(G);
         G.data[pos] = G.player;
         G.nb_empty--;
        _Grille_display(G);
        Grille_update_status(G);
        if (G.player== PLAYER1)
            G.player=PLAYER2;
                    else
            G.player=PLAYER1;

    }
    if (G.status==DRAW_GAME)
        cout <<" Match nul";
        else
            cout << " Le joueur" << G.status<< " a gagne"<<endl;


    return 0;
}
