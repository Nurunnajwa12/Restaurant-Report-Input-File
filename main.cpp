#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void displayName();
void displayLine();
const int a=9;

int main()
{
    ifstream input("input1.txt");
    if(!input)
    {
        cout<<"Unable to open."<<endl;
        return 0;
    }

    int i,j;
    int code,quantity;
    int sumA,sumB,sumC;
    double d,g,price,amount,discount,gst,sum,total;


    //Display title
    displayName();

   //Reading data from text file
    while(input>>code>>quantity)
  {
      //Calculate price
       price= code % 100;

      //Calculate amount
      amount=price*quantity;

      //Calculate total
      d=amount-(amount *0.05);
      g= d*0.06;

      //Show discount,GST and total loop
      if ( code != 3314 && quantity >=15)
    {
        discount=5;
        gst=6;
        total= d + g;

    }
      else if (code !=3314 && quantity <15)
    {
        discount=0;
        gst=6;
        total= amount + (amount*0.06);
    }
      else if (code==3314 && quantity >=15)
    {
        discount=5;
        gst=0;
        total= d;
    }

      else
    {
        discount=0;
        gst=0;
        total=amount;
    }

  //Display output
  cout<<fixed<<showpoint<<setprecision(2)<<endl;

  cout<<code<<"\t"<<setw(a)<<quantity<<"\t"<<setw(a)<<price<<"\t"<<
        setw(a)<<amount<< "\t"<<setw(a)<<discount<<"\t"<<setw(5)<<gst
        <<"\t"<<setw(5)<<total<<endl;

  //Calculate total sales
  sum += total;

  //Calculate quantity each code
  if( code==1118)
  {
      sumA+=quantity;
  }
  else if(code==2220)
  {
      sumB+=quantity;
  }
  else
  {
      sumC+=quantity;
  }

  }

   displayLine();//display end line for list of record

  //Display sale statistic
  cout<<"\n\n:: SALES STATISTICS ::"<<endl;
  displayLine();

  cout<<"\nCode"<<setw(8)<<"\t"<<"Total Quantity"<<endl;
  displayLine();

  cout<<"\n1118"<<setw(8)<<"\t"<<sumA<<endl;
  cout<<"2220"<<setw(8)<<"\t"<<sumB<<endl;//KENAPA TAK DAPAT?????
  cout<<"3314"<<setw(8)<<"\t"<<sumC<<endl;

  displayLine();

  cout<<fixed<<showpoint<<setprecision(2)<<endl;
  cout<<"Total Sales: RM "<<sum<<endl;


  input.close();//Closing file

   return 0;
}

//Title function
void displayName()
{
  cout<<"\n\t\t\t\t"<<"Dynamic Restaurant's Weekly Sales Report"<<"\t\t"<<endl;

  cout<<"\n\n::SALES DETAILS::"<<endl;

  displayLine();
  cout<<"\nCode"<<"\t"<<"Quantity"<<"\t"<<"Price(RM)"<<"\t"
      <<"Amount(RM)"<<"\t"<<"Discount(%)"<<"\t"<<"GST"<<"\t"
      <<"Total(RM)"<<endl;

  displayLine();
}
//Display line function
void displayLine()
{
    for(int i=0;i<110;i++)
    {
        cout<<"=";

    }
}


