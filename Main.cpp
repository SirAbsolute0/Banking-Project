#include <iostream>
#include <string>
#include "Header.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;




int main() 
{
   
    int value = 0;
    int x = 0;
    data* header = new data;
   
    //Loop executing user action through choice
   do
    {
        value = menu();
        switch (value)
        {
        case 1:
        {
            //Need to see if there is a better way to execute first user
            if (x == 0)
            {
                input(header);
                x += 1;
                break;
            }
            else
            {newUser(header);
            break;}
        };
            
        case 2:
        {
            if (header->ID == 0)
            {
                cout << "The list is currently empty, please enter the data of the first user." << endl;
                break;
            }
            else
            {
                updateData(header);
                break;
            }
        };


         case 3:
         {transaction(header);
         break; }

         case 4:
         {displayAll(header);
         break; };

         case 5:
         {deleteNode(header);
         break; };

        }
    } while (value != 7);
    cout << "The application has been terminated." << endl;
    exit; 
}


