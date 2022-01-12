#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int choice = 0;
int n, k=0;



struct product_info

{
    int id=0;
    string name="";
    int price=0;
    int count=0;

}*products;



int menu();
void load();
void show_list();
/*void write();
void add_product();
*/


int main()
{

    cout << "Enter number of products:  ";
    cin >>  n;
    products = new product_info[n];
    load();
    //write();


    while (choice!=8)

    {
        menu();
        switch(choice)
        {


        case 1:
           // add_product();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            show_list();
            break;
        case 8:
            break;

        }
    }

    return 0;

}

int menu()
{
    cout << "\n\t Store Menue\n\n1-Add Product\n2-Edit Product\n3-Delete Product\n4-Search\n5-Buy\n6-Sort\n7-Show List\n8-Exit\n";
    cin >>choice;
    return choice;
}

void load()
{


    string line;
    ifstream product_file;
    product_file.open("products.txt");

    while (getline(product_file,line))
    {

        string array[4];
        int j = 0;

        for (int i = 0; i <= line.size(); i++)
        {

            if(line[i]!=',' && i !=(line.size()))
                array[j] = array[j] + line[i];
            else
            {

                switch(j)
                {
                case 0:
                    products[k].id = stoi(array [j]);
                    break;
                case 1:
                    products[k].name = array [j];
                    break;
                case 2:
                    products[k].price = stoi(array [j]);
                    break;
                case 3:
                    products[k].count = stoi(array [j]);
                    break;

                }
                j++;

            }

        }

        k++;
    }

    product_file.close();
}


void show_list()
{

    cout << "\n List:\n";
    for (int i = 0; i<n; i++)

        cout << "product "<< i+1 << "= id: "<<products[i].id << "\tname: "<<products[i].name<<"\tprice: "<<products[i].price<<"\tcount: "<<products[i].count << "\n";

}


void write()
{
    string line;

    ofstream product_file("products.txt", ios::app);
    for (int i = 0; i<10 ; i++)
    {

        product_file << products[i].id << "," << products[i].name << "," << products[i].price << "," << products[i].count << endl;
    }
    product_file.close();

}

/*void add_product()
{

    for (int i = 0; i <= 3; i++)
    {
        cout << "enter product "<< i+1 << "= id: " ;
        cin >> products[i].id;
        cout << "enter product "<< i+1 << "name: ";
        cin >> products[i].name;
        cout << "enter product "<< i+1 << "price: ";
        cin >> products[i].price;
        cout << "enter product "<< i+1 <<"count: ";
        cin >> products[i].count ;
        cout << endl;


    }
}*/

