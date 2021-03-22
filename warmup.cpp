#include <vector>
using std::vector;
#include <iostream>
using std::cout;

vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
/* make future a copy of world. */
	/* NOTE: the vector 'world' above corresponds to the contents
	 * of ../res/tests/0.  TODO: apply the rules to the vector,
	 * write the result to standard output, and compare with the
	 * contents of ../tests/1. */

void print()
{
/*we use void since we don't want the function to return anything, this function is to simply print the world*/

	int m = world.size();
	int n = world[0].size();

	for(int i = 0 ; i < m; i++)
	{

		for(int j = 0; j < n; j++)
		{
			if (world[i][j] == false)
			{
				cout << ".";
			}
			else
			{
				cout << "O";
			}
		}
		cout << "\n";
	}
}

int countB(int i, int j, int m, int n)
{
  //this will act as a function for counting the 8 neighbors surrounding each cell
  //b is the nieghbors alive
  int b = 0;

        // top left
        if (world[(i - 1 + m ) % m][(j - 1 + n) % n])
        {
          b++;
        }
        // top
        if (world[(i - 1 + m)% m][j])
        {
          b++;
        }
        // top right
        if (world[(i -1 + m) % m][(j + 1 + n) % n])
        {
          b++;
        }
        // left
        if (world[i][(j - 1 + n) % n])
        {
          b++;
        }

        // right
        if (world[i][(j + 1) % n])
        {
          b++;
        }

        // bottom left
        if (world[(i + 1) % m][(j - 1 + n) % n])
        {
          b++;
        }

        // bottom
        if (world[(i + 1) % m][j])
        {
          b++;
        }

        // bottom right
        if (world[(i + 1) % m][(j + 1) % n])
        {
          b++;
        }

 return b;
}



void newcycle()
{
  //this function has a role in updating our world

   vector<vector<bool>> future(world);

  int m = world.size();
	int n = world[0].size();


  // m is the total number of rows and n is the total number of columns

    for (int i = 0 ; i < m; i++)
    {

      for (int j = 0; j < n; j++)
      {

        //b is the nieghbors alive
        int b = countB(i, j, m, n);


    //applying rules of the GOL

        //for the condition of cell being alive

        if (world[i][j])
        {
          if( b < 2 || b > 3 )
          {
            //the cell dies
            future[i][j] = 0;
          }
        }
        //for the condition of cell being dead
        else
        {
          //the dead cell can become alive if its has 3 exactly neighbors
          if( b == 3)
          {
            //the cell becomes alive
            future[i][j] = 1;
          }
        }
      }

  }

world = future;
}

  int main(int argc, char *argv[])
{

  //the role of b is to store whatever argument is presented as an input
  // if we type ./warmup 8 in then it is argv[1] = 8
  //so atoi's role is to convert the charactr to int
  int b = 1;

  if (argc == 2)
  {
      b = atoi(argv[1]);
  }


  for(int c = 0; c < b; c++)
  {
    newcycle();
  }

  //prints out our world

  print();

  return 0;
}
