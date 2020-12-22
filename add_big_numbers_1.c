// To find sum of 2 large integers

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

// reverses the string in arr1 and stores it in arr1_rev
// for ex "123" gets converted to "321"
void reverse(char arr1[], char arr1_rev[])
{
  int i;
  for(i = 0; i < strlen(arr1); i++)
  	arr1_rev[i] = arr1[strlen(arr1) - 1 - i];
  arr1_rev[strlen(arr1)] = '\0';
}

// stores the arr1 string length at dec[0]
// stores the arr2 string length at dec[1]
// stroes the corresponding "string number"(1 or 2) with bigger length 
void str_lengths(char arr1[], char arr2[], int dec[])
{
	if(strlen(arr1) >= strlen(arr2))
	{
		dec[0] = strlen(arr1);
		dec[1] = strlen(arr2);
		dec[2] = 1;
	}
	else if(strlen(arr1) < strlen(arr2))
	{	
		dec[0] = strlen(arr2);
		dec[1] = strlen(arr1);
		dec[2] = 2;
	}
}

// appends "a" number of zeros to the beginning of arr
void add_zero_bef(char arr[], long int a)
{
	char temp_arr[100000];
	long int i;
	int len = strlen(arr);
	for(i = 0; i < a; i++)
		temp_arr[i] = '0';
	temp_arr[a] = '\0';
	strcat(temp_arr, arr);
	strcpy(arr, temp_arr);
}

void add(char num1[], char num2[], char fin_sum[])
{
	char *ptr1, *ptr2, *ptr, num1_copy[100000], num2_copy[100000], sum[100000];
	
	// store the copy of given 2 numbers
	strcpy(num1_copy, num1);
	strcpy(num2_copy, num2);

	//printf("%s %s \n", num1_copy, num2_copy);

	int i, limit, n1, n2, carry = 0, temp_sum, decide[3];
	str_lengths(num1, num2, decide);
	//printf("%s %s \n", num1, num2);
	if(decide[2] == 1)
		add_zero_bef(num2_copy, decide[0] - decide[1]);
	else if(decide[2] == 2)
		add_zero_bef(num1_copy, decide[0] - decide[1]);

	//printf("%s %s \n", num1_copy, num2_copy);
	
	ptr1 = num1_copy + strlen(num1_copy);
	ptr2 = num2_copy + strlen(num2_copy);

	limit = strlen(num1_copy);

	// take num1 = "124" and num2 = "456" then
	// we initialize 2 pointers ptr1 at '4' of "124" and 
	// ptr2 at '6' of "456". We add 4+6 = 10. store the '0' of this 10
	// at the last place(unit's place) of sum array and store the '1' of 10
	// in carry variable. We go on doing this until we've covered each
	// digit of the bigger string  
	for(i = 0; i < limit; i++)
	{
		ptr1 -= 1;
		ptr2 -= 1;

		n1 = atoi(ptr1);
		n2 = atoi(ptr2);

		*ptr1 = '\0';
		*ptr2 = '\0';

		temp_sum = n1 + n2 + carry;
		carry = temp_sum / 10;
		temp_sum = temp_sum % 10;
		sum[limit - i] = temp_sum + '0';
	}
	sum[0] = carry + '0';
	//printf("%s\n", sum[0]);
	sum[limit + 1] = '\0';
	
	if(sum[0] == '0')
	{
		ptr = sum + 1;
		strcpy(fin_sum, ptr);
	}
	else
		strcpy(fin_sum, sum);
}

// int main()
// {
// 	char num1[100000], num2[100000], sum[100000];
// 	scanf("%s %s", num1, num2);
// 	add(num1, num2, sum);
// 	printf("%s ", sum);
// 	return 0;
// }


