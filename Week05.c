/*
Michelle Lugo
CIS 236 
Week 05 homework
For this week 05 homework, I had to create a program that included functions.
Everything will appear the same to the user but the programming itself will be different.

I had to create a program that if the user purchased 
JJC spirit wear they would get a discount.
But if they did not purchase JJC spirit wear, they do not get a discount.
If the purchase was more than or equal to $100, they get 10% off. 
If the purchase was less than $100, they only get 7%. 
I also had to include sales tax after each purchase which was 5%. 


*/

#include <stdio.h>

/*

Below are the functions that are used in the program.
They give the same results as the previous homework assignment from week 03. 
The functions are able to give results for the discount amount, 
new purchase after discount, the sales tax, and the final total purchase amount.


*/


// function to compute the discount amount
double computeDiscount(double amount, double discount_rate) 
{
    return (amount * discount_rate) / 100.0;
}

// function to compute the new purchase amount after discount
double computePurchase(double discount, double amount)
{
    return amount - discount;
}

// function to compute the sales tax
double computeTax(double amount) 
{
	double tax_rate = 5.0; 
    return (amount * tax_rate) / 100.0;
}

// function to compute the total purchase amount including tax
double computeTotalPurchaseAmount(double new_purch, double sales_tax) 
{
    return new_purch + sales_tax;
}


int main(void)
{
	
	// Variables that are used in the program
	
	char yn;
	double amount; 
	
	// Initialization step
	int discount_rate = 0; 
	
	// The user inputs the information about the purchase
	
	printf("Enter the purchase amount> ");
    scanf("%lf", &amount); 
    fflush(stdin);
    
    printf("Does this purchase include Spirit Wear (Y/N)? ");
    scanf("%c", &yn);
    fflush(stdin);
    
    
/*
This is where the if else statement begins. 
The first if conditon states that if the purchase does include spirit wear, then 
it will either be 7% or 10% discount depending if the purchase was more or equal to $100 or less than $100. 
After it determines which discount to use, it'll perform calculations in order to get the outcomes and will print the results to the screen. 
When the amount was entered, it will print out the new amount after the discount, sales tax, and the total of the purchase.
The equations that use multiplications, i divided them by 100.0 in order to get a float number. Without it, the numbers came out negative and inaccurate.  
 If the user entered no, then it will print out the purchase anmount, sales tax, and toal purchase. 
 */
 
 
 if (yn == 'y' || yn == 'Y') 
{
        printf("Purchase amount                 $ %6.2f\n", amount);

        if (amount <= 100) 
		 {
            discount_rate = 7;
         } 
		   else 
		  {
            discount_rate = 10;
          }
	
/*
Here is where things are diffrent in the program, the functions calculate the the information 
that entered by the user and give the same results from previous homework. 
*/

	double discount = computeDiscount(amount, discount_rate);
    printf("Discount(%d%%)                   $ %6.2f\n", discount_rate, discount);

    double new_purch = computePurchase(discount, amount);
    printf("Purchase amount after discount  $ %6.2f\n", new_purch);

    double sales_tax = computeTax(new_purch);
    printf("Sales tax (5%%)                  $ %6.2f\n", sales_tax);

    double total_purch = computeTotalPurchaseAmount(new_purch, sales_tax);
    printf("Total purchase                  $ %6.2f", total_purch);
	
}

	else if (yn == 'n' || yn == 'N') 
	{
    double sales_tax = computeTax(amount);
    double total_purch = computeTotalPurchaseAmount(amount, sales_tax);

    printf("Purchase amount                 $ %6.2f\n", amount);
    printf("Sales tax (5%%)                  $ %6.2f\n", sales_tax);
    printf("Total purchase                  $ %6.2f", total_purch);
    } 
	
}


