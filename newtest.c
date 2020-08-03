#include<stdio.h>
#include<stdlib.h>

float average(int array[], int size)
{
	float sum	=	0.0;
	for(int i=0; i<size; i++)
	{
		sum	+=	array[i];
	}
	float avg	=	sum/size;	
	return avg;
}

int maxval(int array[], int size)
{
	int max		=	array[0];
	for(int i=1; i<size; i++)
	{
		if (array[i] > max)
		{
			max	=	array[i];
		}
	}
	return max;
}

int main(int argc, char *argv[])
{
	FILE *inp,*out;
	
	if(argc	!=3)
	{
		printf("Wrong call to the executable. Command-line argument is <executable> <input> <output>\n");
		exit(1);
	}
	
	inp		=	fopen(argv[1],"r");
	out             =       fopen(argv[2],"a");

	int size;	
	int read;
	int counter=0;
	int array[size];

	fscanf(inp,"%d",&size);
	fseek(inp,1,SEEK_SET);

	while(fscanf(inp,"%d",&read) >0)
	{
		array[counter]	=	read;
		counter++;
	}
	float avgnum	=	average(array,size);
	int max		=	maxval(array,size);

	printf("The size of the array is %d and the numbers read in are ",size);
	fprintf(out,"The size of the array is %d and the numbers read in are ",size);

	for(int counter=0; counter<size; counter++)
	{
		printf("%d\t",array[counter]);
		fprintf(out,"%d\t",array[counter]);

	}

	printf("\nThe average of the numbers is %f, and the maximum value is %d\n",avgnum,max);
	fprintf(out,"\nThe average of the numbers is %f, and the maximum value is %d\n",avgnum,max);
	return 0;
}
