int degre(int s, int G[100][100], int nb_sommets)
{
    int i, deg = 0;
    for (i = 0; i < count; i++)
    {
        if (G[nb_sommets][i])
        {
           deg++
        }
        if (G[i][nb_sommets])
        {
            deg++;
        }
    }
    return deg ;
}