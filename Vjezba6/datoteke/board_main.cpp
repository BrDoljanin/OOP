// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>
using namespace std;

// ovdje napisite klasu Board
class Board
{

    int red;
    int stup;
    char* okvir;

public:
    Board(int rows, int cols, char znak) : red(rows), stup(cols)
    {

        okvir = new char[red * stup];
        for (int i = 0; i < red; i++)
        {
            for (int j = 0; j < stup; j++) {

                if (i == 0 || i == red - 1 || j == 0 || j == stup - 1)
                {

                    okvir[i * stup + j] = znak;

                }
                else
                {

                    okvir[i * stup + j] = ' ';

                }
            }

        }

    }

    ~Board()
    {

        delete[] okvir;

    }

    Board(const Board& a) : red(a.red), stup(a.stup) {
        okvir = new char[red * stup];
        for (int i = 0; i < red * stup; ++i) {
            okvir[i] = a.okvir[i];
        }
    }

    void set(int i, int j, char znak)
    {
    
        if(i > 0 && i < red - 1 && j > 0 || j < stup - 1)
        {
        
            okvir[i * stup + j] = znak;
        
        }
    
    }
    char get(int i, int j)
    {
    
        return okvir[i * stup + j];
    
    }
    int rows() 
    {
    
        return red;
    
    }
    int cols() 
    {
    
        return stup;
    
    }
    void print() 
    {
    
        for(int i = 0; i < red; i++)
        {
        
            for(int j = 0; j < stup; j++)
            {
            
                cout << okvir[i * stup + j];
            
            }
            cout << '\n';
        
        }
    
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;          // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');     // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
