#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *longestSubstring(char *str,int str_length)
{
	int max = 0,i,chars= 0,j =  0;
	for( i = 0; i <str_length; i++)
	{
		if(str[i] > max)max = str[i];
	}

	const int k = max+1;
	int arr[k];
	for(i = 0; i < k; i++)
	{
		arr[i] = 0;
	}

	for(i = 0; i < str_length; i++)
	{
		arr[str[i]] += 1;
	}

	for(i = 0; i < k; i++)
	{
		if(arr[i] != 0)chars++;
	}
	const int size = chars;
	i = 1;
	char *sub = (char*)malloc(sizeof(char)*size);
	for(i = 0; i < size; i++){
		sub[i] = '0';
	}
	int l;
	i = 0;
	while(i < str_length && j < chars){
		bool found = false;
		for(l = 0; l < chars;l++)
		{
			if(str[i] == sub[l])found = true;
		}
		if(found == true)
		{
			for(l = 0; l < size; l++){
				sub[l] = '0';
			}
			j = 0;
			sub[j] = str[i];
		}
		else{
			sub[j] = str[i];
			j++;
		}
		i++;

	}
	printf("This string contains %d different characters.\n",chars);
	return sub;
}
void main()
{
	char str[] = {"abcbacbb"};
	printf("%s\n",str);
	printf("%s\n",longestSubstring(str,8));
}
