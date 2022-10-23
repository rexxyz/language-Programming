#include<stdio.h>

void TimeConversions()
{
    printf("Time World Welcomes You\n\n");
    printf(" Description :\n\n");
    printf(" This Time World is some what Biased in terms of Conversions \n Because Conversion of a Decade into Seconds or Milliseconds is a Useless thing and is also Completely Unnessesary\n So After Considering these sort of things We Will Provide only Required Conversions \n If Any thing else Needed it Can also be Done Because these Units are Interrelated \n !! So Use Your Brain hehe !!\n\n");
    printf("1. Min and Sec\n");
    printf("2. Hour and Sec\n");
    printf("3. Hour and Min\n");
    printf("4. Day and Hour\n");
    printf("5. Day and Min\n");
    printf("6. Week and Day\n");
    printf("7. Week and Hour\n");
    printf("8. Year and Month\n");
    printf("9. Decade and Year\n");
    printf("10. Century and Year\n");
    printf("11. Millennium and Decades\n");
    printf("12. Decisecond and Seconds\n");
    printf("13. Milliseconds and Seconds\n");
    printf("14. Microseconds and Seconds\n\n");

    int a; 
printf("!! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &a);

if(a>14 || a<1)
{
    printf(" !! Enter a Valid Number According to the Task Needed to be Done !!");

}

else
{

if(a==1)
{
    printf(" If You Want to Convert from Min to Sec Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*60);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/60);

    }
}
if(a==2)
{
    printf(" If You Want to Convert from Hour to Sec Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*60*60);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/3600);

    }
}
if(a==3)
{
    printf(" If You Want to Convert from Hour to Min Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*60);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/60);

    }
}
if(a==4)
{
    printf(" If You Want to Convert from Day to Hour Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*24);
    }
    else
    {
      printf("Enter the Value\n");
     long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/24);

    }
}
if(a==5)
{
    printf(" If You Want to Convert from Day to Min Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*60*24);
    }
    else
    {
      printf("Enter the Value\n");
     long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/1440);

    }
}
if(a==6)
{
    printf(" If You Want to Convert from Week to Day Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*7);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/7);

    }
}
if(a==7)
{
    printf(" If You Want to Convert from Week to Hour Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
   scanf("%lld",&x);
      printf("%lld ",x*7*24);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/168);

    }
}
if(a==8)
{
    printf(" If You Want to Convert from Year to Month Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*12);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/12);

    }
}
if(a==9)
{
    printf(" If You Want to Convert from Decade to Year Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
   scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*10);
    }
    else
    {
      printf("Enter the Value\n");
     long  double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/10);

    }
}
if(a==10)
{
    printf(" If You Want to Convert from Century to Year Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
     scanf("%lld",&x);
      printf("%lld ",x*100);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/100);

    }
}
if(a==11)
{
    printf(" If You Want to Convert from Millennium to Decades Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*100);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/100);

    }
}
if(a==12)
{
    printf(" If You Want to Convert from Decisecond to Sec Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/10);
    }
    else
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*10);

    }
}
if(a==13)
{
    printf(" If You Want to Convert from Millisec to Sec Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
 scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/1000);
    }
    else
    {
      printf("Enter the Value\n");
      long long int x;
     scanf("%lld",&x);
      printf("%lld ",x*1000);

    }
}
if(a==14)
{
    printf(" If You Want to Convert from Microsec to Sec Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
    long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/1000000);
    }
    else
    {
      printf("Enter the Value\n");
      long long int  x;
      scanf("%lld",&x);
      printf("%lld ",x*1000000);

    }
}
}
}
void MassConversions()
{
printf(" Welcome to World of Mass\n");
printf(" Description :\n\n");
printf(" This Mass World is some what Biased in terms of Conversions \n It Will Only Give You Some Valid Conversions  \n If Any thing else Needed it Can also be Done Because these Units are Interrelated \n !! So Use Your Brain hehe !!\n\n");
printf("1. Kg and g\n");
printf("2. g and mg\n");
printf("3. Tonn and Kg\n");
printf("4.Pound and Kg\n");
printf("5.Ounce and Pound\n");
printf("6.Stone and Pound\n");

int a; 
printf(" !! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &a);

if(a>6 || a<1)
{
    printf(" !! Enter a Valid Number According to the Task Needed to be Done !!");
}
else
{
if(a==1)
{
    printf(" If You Want to Convert from Kg to g Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*1000);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/1000);

    }
}
if(a==2)
{
    printf(" If You Want to Convert from g to mg Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*1000);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/1000);

    }
}
if(a==3)
{
    printf(" If You Want to Convert from Tonn to Kg Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*1000);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/1000);

    }
}
if(a==4)
{
    printf(" If You Want to Convert from Pound to Kg Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
   scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x*0.45359);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/0.45359);

    }
}
if(a==5)
{
    printf(" If You Want to Convert from Ounce to Pound Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x*0.0625);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/0.0625);

    }
}
if(a==6)
{
    printf(" If You Want to Convert from Stone to Pound Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*14);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/14);

    }
}
}
}

void LengthConversions()
{
printf(" Welcome Just Welcome ...\n");
printf(" Description :\n\n");
printf(" This World is some what Biased in terms of Conversions \n It Will Only Give You Some Valid Conversions  \n If Any thing else Needed it Can also be Done Because these Units are Interrelated \n !! So Use Your Brain hehe !!\n\n");

printf("1. Km and m\n");
printf("2. m and cm\n");
printf("3. cm and mm\n");
printf("4. dm and cm\n");
int a; 
printf(" !! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &a);

if(a>4 || a<1)
{
    printf(" !! Enter a Valid Number According to the Task Needed to be Done !!");
}
else
{
if(a==1)
{
    printf(" If You Want to Convert from Km to m Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
  scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*1000);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/1000);

    }
}
if(a==2)
{
    printf(" If You Want to Convert from m to cm Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*100);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/100);

    }
}
if(a==3)
{
    printf(" If You Want to Convert from cm to mm Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*10);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",x/10);

    }
}
if(a==4)
{
    printf(" If You Want to Convert from dm to cm Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long long int x;
      scanf("%lld",&x);
      printf("%lld ",x*10);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x/10);

    }
}
}
}

void ThermodynamicConversions()
{
printf(" Welcome to Heat World \n");
printf(" Description :\n\n");
printf(" This World is some what Biased in terms of Conversions \n It Will Only Give You Some Valid Conversions  \n If Any thing else Needed it Can also be Done Because these are Interrelated \n !! So Use Your Brain hehe !!\n\n"); 
printf("1. Fahrenheit and Celsius\n");
printf("2. Celsius and Kelvin\n");
printf("3. kelvin and Fahrenheit\n");
int a; 
printf(" !! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &a);

if(a>3 || a<1)
{
    printf(" !! Enter a Valid Number According to the Task Needed to be Done !!");

}
else
{
if(a==1)
{
    printf(" If You Want to Convert from Fahrenheit to Celsius Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",((x-32)*5)/9);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",((x*9)/5)+ 32);

    }
}
if(a==2)
{
    printf(" If You Want to Convert from Celsius to Kelvin Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x+273.15);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x-273.15);

    }
}
if(a==3)
{
    printf(" If You Want to Convert from Kelvin to Fahrenheit Press 1 For Viceversa Press Any Number Except 1\n");
    int n; 
    scanf("%d",&n);
    if(n==1)
    {
      printf("Enter the Value\n");
      long double x;
      scanf("%Lf",&x);
      printf("%Lf ",(((x-273.15)*9)/5)+32);
    }
    else
    {
      printf("Enter the Value\n");
      long double x;
    scanf("%Lf",&x);
      printf("%Lf ",(((x-32)*5)/9)+ 273.15);

    }
}
}
}

void CurrencyConversions()
{
printf(" Welcome to Money World \n");
printf(" Description :\n\n");
printf(" This World is one of the Most Wanted World hehe \n It Will Only Give You Some Conversions No Personals hehe \n\n"); 
printf("1. Dollar to Rupee\n");
printf("2. Euro to Rupee\n");
printf("3. Ruble to Rupee\n");
printf("4. Yen to Rupee\n");
int a; 
printf(" !! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &a);

if(a>4 || a<1)
{
    printf(" !! Enter a Valid Number According to the Task Needed to be Done !!");
}
else
{
    if(a==1)
{
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x*82.43165);
}
if(a==2)
{
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x*80.1359163);
}
if(a==3)
{
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x*1.3157485);
}
if(a==4)
{
      printf("Enter the Value\n");
      long double x;
     scanf("%Lf",&x);
      printf("%Lf ",x*0.5541439);
}
}
}

int main()
{
printf("Data Converter Welcomes You \n");
printf("Choose One of Your Required Conversion \n\n");
printf(" 1. Time Conversions\n");
printf(" 2. Mass Conversions\n");
printf(" 3. Length Conversions\n");
printf(" 4. Thermodynamic Conversions\n");
printf(" 5. Currency Conversions\n\n");

int n; 
printf("!! Enter a Number Present on Left Corresponding to the Task Needed to be Done !!\n ");
scanf("%d", &n);
if(n>5 || n<1)
{
    printf("!! Enter a Valid Number According to the Task Needed to be Done !!");
}
else
{
if(n==1)
{
    TimeConversions();
}
if(n==2)
{
    MassConversions();
}
if(n==3)
{
    LengthConversions();
}
if(n==4)
{
    ThermodynamicConversions();
}
if(n==5)
{
    CurrencyConversions();
//FXXRPI pull
}
}
}
