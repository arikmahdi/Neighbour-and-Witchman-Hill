#include<stdio.h>

int array[5][5]=
{
    {0,1,0,0,0},
    {0,0,1,0,0},
    {0,1,1,0,1},
    {0,1,0,0,1},
    {0,0,0,0,0}
};

int temp[5][5];  ///dummy array

void copy()      /// copying array to temperory
{

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            temp[i][j]=array[i][j];

        }
    }
}



int neighbour(int i,int j)
{

    int alive=0,dead=0;

/* Neighbour Check */


    if(i!=0 && j!=0)   ///Neighbour 1
    {

        if(temp[i-1][j-1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }


    }




    if(i!=0)       ///Neighbour 2
    {
        if(temp[i-1][j]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }

    }



    if(i!=0 && j!=4)      ///Neighbour 3
    {
        if(temp[i-1][j+1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }
    }




    if(j!=4)      ///Neighbour 4
    {
        if(temp[i][j+1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }

    }



    if(i!=4 && j!=4)      ///Neighbour 5
    {
        if(temp[i+1][j+1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }
    }





    if(i!=4)            ///Neighbour 6
    {
        if(temp[i+1][j]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }
    }



    if(i!=4 && j!=0)       ///Neighbour 7
    {
        if(temp[i+1][j-1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }

    }




    if(j!=0)            ///Neighbour 8
    {
        if(temp[i][j-1]==1)
        {
            alive++;

        }
        else
        {
            dead++;

        }

    }





   if (temp[i][j]==1)  /// cell check if cell is alive ( it contains three rules 1-3 )
    {
        if(alive<2)
            return 0;
        if(alive==2)
            return 1;
        if(alive>2)
            return 0;

    }
    if (temp[i][j]==0)  /// if cell is dead (  4 no. rules )
    {
        if(alive>=2 && alive<=3)
            return 1;

    }
}

void print()    /// Output format print
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    int m=0,cell,i,j,k;
    while(m<=20)
    {
        printf("\nTime -- %d  \n",m);
        print();
        copy();
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                cell=neighbour(i,j);
                array[i][j]=cell;
            }
        }


        m++;
    }

}
